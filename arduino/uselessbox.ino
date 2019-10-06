#include <FastLED.h>
#include <Servo.h>
#include "Adafruit_APDS9960.h"
Adafruit_APDS9960 apds;


FASTLED_USING_NAMESPACE

Servo hood, finger, flag, asshole;

#if defined(FASTLED_VERSION) && (FASTLED_VERSION < 3001000)
#warning "Requires FastLED 3.1 or later; check github for latest code."
#endif

#define INT_PIN 7

#define DATA_PIN    4
//#define CLK_PIN   4
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define NUM_LEDS    16
CRGB leds[NUM_LEDS];
CRGBPalette16 gPal;
volatile bool glowstate = false;
volatile int brightness = 150;
volatile int colorcode =1;
int presetbrightness = 150;

int hoodactivestop = 1000;
int hoodinactivestop = 1650;
volatile int hoodcurrent = 1650;
volatile int hoodspeed = 25;
volatile bool hoodservoactive = false;

int fingeractivestop = 1700;
int fingerinactivestop = 1300;
volatile int fingercurrent = 1300;
volatile int fingerspeed = 250;
volatile bool fingerservoactive = false;

int flagactivestop = 2000;
int flaginactivestop = 1500;
volatile int flagcurrent = 1500;
volatile int flagspeed = 150;
volatile bool flagservoactive = false;

int assholeactivestop = 1000;
int assholeinactivestop = 1700;
volatile int assholecurrent = 1700;
volatile int assholespeed = 50;
volatile bool assholeservoactive = false;

volatile bool servoactive = false;
volatile bool servoactionfinished = false;

volatile int currentstep=0;
volatile bool currentstepfinished=false;

volatile bool skipflag = false;
volatile bool skipasshole = false;

#define FRAMES_PER_SECOND  120

volatile bool triggerInUse=false;
volatile bool triggerinprogress = false;

volatile int localloop =-1;

int lowerproximitythreshold=15;

int servopinhood = 3;
int servopinfinger = 5;
int servopinflag = 6;
int servopinasshole = 9;

int pinswitch = 2;
volatile int oldhoodcurrent=0;

void setup() {
  Serial.begin(9600); //init debug console 
  pinMode(INT_PIN, INPUT_PULLUP);
  delay(500); // 500 milliseconds delay for recovery
  pinMode(3, INPUT); //modeswitch
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(brightness);
  if(!apds.begin()){
    Serial.println("failed to initialize device! Please check your wiring.");
  }
  else Serial.println("Device initialized!");

  apds.enableProximity(true);
  apds.setProximityInterruptThreshold(0, lowerproximitythreshold);
  apds.enableProximityInterrupt();
  
  setled(CRGB::White);
  //delay(5000);
  hoodcurrent = hoodinactivestop;
  movehood(hoodcurrent);
  fingercurrent = fingerinactivestop;
  movefinger(fingercurrent);
  flagcurrent = flaginactivestop;
  moveflag(flagcurrent);
  assholecurrent = assholeinactivestop;
  moveasshole(assholecurrent);
  
  enableServos();
  delay(500);  
  servoactive = true;
  executeServo();
  delay(500);
  disableServos();
  delay(500);
  servoactive = false;
  servoactionfinished = true;
  
  setled(CRGB::Black);
  brightness=10;
  
}



void loop()
{

  
  if(!digitalRead(INT_PIN)){
    setled(CRGB::DarkRed);
    int proximity = apds.readProximity();
    //Serial.println(proximity);
    FastLED.setBrightness(proximity);
    //clear the interrupt
    apds.clearInterrupt();
    if(localloop==1) {
      if(hoodservoactive==false) {
        enableServoHood();
        delay(100);
        oldhoodcurrent = hoodcurrent;
      }
      hoodcurrent = map(proximity, lowerproximitythreshold, 255, hoodinactivestop, hoodactivestop);
      if(hoodcurrent > (oldhoodcurrent + 50) || hoodcurrent < (oldhoodcurrent - 50)) {
        oldhoodcurrent=hoodcurrent;
        movehood(hoodcurrent);
        //Serial.println(hoodcurrent);
      }
      if(hoodservoactive==true) {
        disableServoHood();
      }
    }
    
  } else {
    
    FastLED.setBrightness(brightness);
    glow();
  }
  FastLED.show();  
  FastLED.delay(1000/FRAMES_PER_SECOND); 
  
  if(digitalRead(pinswitch) == HIGH) {
    if(triggerInUse==false && triggerinprogress==false) {  
      triggerinprogress=true;
      brightness=presetbrightness;
      FastLED.setBrightness(brightness);
      //Serial.println("------------>trigger");  
      localloop++;
      if (localloop > 5) {
        localloop = 0;
      }
      switch (localloop) {
        case 0: //standard
          skipflag = true;
          skipasshole = true;
          hoodspeed = 25;
          fingerspeed = 250;
          flagspeed = 50;
          assholespeed = 50;
          colorcode=2;
        break;
        case 1: //fast and resolute
          skipflag = true;
          skipasshole = true;
          hoodspeed = 200;
          fingerspeed = 250;
          flagspeed = 250;
          assholespeed = 50;
          colorcode=5;
        break;
        case 2: //open hood based on proximity
          skipflag = true;
          skipasshole = true;
          hoodspeed = 25;
          fingerspeed = 250;
          flagspeed = 150;
          assholespeed = 50;
          colorcode=3;
        break;
        case 3: //wave flag
          skipflag = false;
          skipasshole = true;
          hoodspeed = 25;
          fingerspeed = 250;
          flagspeed = 150;
          assholespeed = 50;
          colorcode=3;
        break;
        case 4: //really slow
          skipflag = true;
          skipasshole = true;
          hoodspeed = 10;
          fingerspeed = 250;
          flagspeed = 150;
          assholespeed = 50;
          colorcode=2;
        break;
        case 5: //show asshole
          skipflag = true;
          skipasshole = false;
          hoodspeed = 25;
          fingerspeed = 250;
          flagspeed = 150;
          assholespeed = 50;
          colorcode=4;
        break;
        default:
          skipflag = true;
          skipasshole = true;
          hoodspeed = 25;
          fingerspeed = 250;
          flagspeed = 150;
          assholespeed = 50;
          colorcode=2;
        break;
      }
      //Serial.print("loop:");
      //Serial.println(localloop);
      servoactive=true;
      servoactionfinished=false;
      currentstep=1;
      currentstepfinished=false;

      //enableServos();

      setled(CRGB::White);
      FastLED.show();
      delay(250);
      

      
      
    } else {
      //Serial.println("----------Trigger in use already");
    }
      
  } else {
    if(triggerInUse==true) {
      brightness=presetbrightness;
      FastLED.setBrightness(brightness);
      //Serial.println("------------>trigger release");  
      setled(CRGB::Black);
      triggerInUse=false;
      triggerinprogress=false;
    }
  }
  
  if(servoactionfinished==true) {
    colorcode=1;
    if(servoactive==true) {
      //disableServos();
      servoactive=false;
      currentstep=0;
    }
    servoactive = false;
    triggerInUse=false;
    triggerinprogress=false;
    
  }
  
  if(servoactive==true && servoactionfinished==false) {

    
    
    //do math staff and so on
    if(currentstepfinished==true && currentstep==9) {
      servoactionfinished=true;
      if(hoodservoactive==true) {
        disableServoHood();
      }
    }
    
    if(currentstepfinished==false && currentstep==8) {
      if(fingerservoactive==true) {
        disableServoFinger();
      }
      if(hoodservoactive==false) {
        enableServoHood();
      }
      if(hoodcurrent < hoodinactivestop) {
        if(hoodcurrent <= (hoodinactivestop - hoodspeed)) {
          hoodcurrent=hoodcurrent+(hoodspeed-1);
          //Serial.println("close hood");
        } else {
          hoodcurrent=hoodinactivestop;
          currentstepfinished=true;
          currentstep++;
          //Serial.println("closed hood");
        }
      }
    }

    if(currentstepfinished==false && currentstep==7) {
      if(fingercurrent > fingerinactivestop) {
        if(fingercurrent >= (fingerinactivestop + fingerspeed)) {
          fingercurrent=fingercurrent-(fingerspeed-1);
          //Serial.println("close finger");
        } else {
          fingercurrent=fingerinactivestop;
          currentstepfinished=false;
          currentstep++;
          //Serial.println("closed finger");
        }
      }
    }

    if(currentstepfinished==false && currentstep==6) {
      if(fingerservoactive==false) {
        enableServoFinger();
      }
      if(flagservoactive==true) {
        disableServoFlag();
      }
      if(fingercurrent < fingeractivestop) {
        if(fingercurrent <= (fingeractivestop - fingerspeed)) {
          fingercurrent=fingercurrent+(fingerspeed-1);
          //Serial.println("raise finger");
        } else {
          fingercurrent=fingeractivestop;
          currentstepfinished=false;
          currentstep++;
          //Serial.println("stay finger");
        }
      }
    }

        
    if(currentstepfinished==false && currentstep==5) {
      
      if(skipflag == true) {
        currentstep++;
      } else {
        if(flagcurrent > flaginactivestop) {
          if(flagcurrent >= (flaginactivestop + flagspeed)) {
            flagcurrent=flagcurrent-(flagspeed-1);
            //Serial.println("close flag");
          } else {
            flagcurrent=flaginactivestop;
            currentstepfinished=false;
            currentstep++;
            //Serial.println("closed flag");
          }
        }
        
      }
    }
    
    if(currentstepfinished==false && currentstep==4) {
      if(hoodservoactive==true) {
        disableServoHood();
      }
      if(skipflag == true) {
        currentstep++;
      } else {
        if(flagservoactive==false) {
          enableServoFlag();
        }
        if(flagcurrent < flagactivestop) {
          if(flagcurrent <= (flagactivestop - flagspeed)) {
            flagcurrent=flagcurrent+(flagspeed - 1);
            //Serial.println("raise flag");
          } else {
            flagcurrent=flagactivestop;
            currentstepfinished=false;
            currentstep++;
            //Serial.println("stay flag");
            //waving the flag
            moveflag(flagcurrent);
            delay(200);
            flagcurrent = flagcurrent-50;
            moveflag(flagcurrent);
            delay(200);
            flagcurrent = flagcurrent-50;
            moveflag(flagcurrent);
            delay(200);
            flagcurrent = flagcurrent+50;
            moveflag(flagcurrent);
            delay(200);
            flagcurrent = flagcurrent+50;
            moveflag(flagcurrent);
            delay(200);
            flagcurrent = flagcurrent-50;
            moveflag(flagcurrent);
            delay(200);
            flagcurrent = flagcurrent-50;
            moveflag(flagcurrent);
            delay(200);
            flagcurrent = flagcurrent+50;
            moveflag(flagcurrent);
            delay(200);
            flagcurrent = flagcurrent+50;
            moveflag(flagcurrent);
            delay(200);
            flagcurrent = flagactivestop;
            
          }
        }
      }
    }
  
    if(currentstepfinished==false && currentstep==3) {
      if(assholeservoactive==true) {
        disableServoAsshole();
      }
      if(hoodservoactive==false) {
        enableServoHood();
      }
      if(hoodcurrent > hoodactivestop) {
        if(hoodcurrent >= (hoodactivestop + hoodspeed)) {
          hoodcurrent=hoodcurrent-(hoodspeed - 1);
          //Serial.println("raise hood");
        } else {
          hoodcurrent=hoodactivestop;
          currentstepfinished=false;
          currentstep++;
          //Serial.println("stay hood");
        }
      }
    }

    if(currentstepfinished==false && currentstep==2) {
      
      if(skipasshole == true) {
        currentstep++;
      } else {
        if(assholecurrent < assholeinactivestop) {
          if(assholecurrent <= (assholeinactivestop - assholespeed)) {
            assholecurrent=assholecurrent+(assholespeed-1);
            //Serial.println("close asshole");
          } else {
            assholecurrent=assholeinactivestop;
            currentstepfinished=false;
            currentstep++;
            //Serial.println("closed asshole");
          }
        }
        
      }
    }
    
    if(currentstepfinished==false && currentstep==1) {
     
      if(skipasshole == true) {
        currentstep++;
      } else {
        if(assholeservoactive==false) {
          enableServoAsshole();
        }
        if(assholecurrent > assholeactivestop) {
          if(assholecurrent >= (assholeactivestop + assholespeed)) {
            assholecurrent=assholecurrent-(assholespeed - 1);
            //Serial.println("raise asshole");
          } else {
            assholecurrent=assholeactivestop;
            currentstepfinished=false;
            currentstep++;
            //Serial.println("stay asshole");
            delay(2000);
          }
        }
      }
    }
  

    
    executeServo();
    delay(50);
  }
  
}

void enableServoHood() {
  hood.attach(servopinhood);
  hoodservoactive=true;
}
void enableServoFinger() {
  finger.attach(servopinfinger);
  fingerservoactive=true;
}
void enableServoFlag() {
  flag.attach(servopinflag);
  flagservoactive=true;
}
void enableServoAsshole() {
  asshole.attach(servopinasshole);
  assholeservoactive=true;
}
void disableServoHood() {
  hood.detach();
  hoodservoactive=false;
}
void disableServoFinger() {
  finger.detach();
  fingerservoactive=false;
}
void disableServoFlag() {
  flag.detach();
  flagservoactive=false;
}
void disableServoAsshole() {
  asshole.detach();
  assholeservoactive=false;
}

void enableServos() {
  hood.attach(servopinhood);
  finger.attach(servopinfinger);
  flag.attach(servopinflag);
  asshole.attach(servopinasshole);
  //delay(500);
}

void disableServos() {
  hood.detach();
  finger.detach();
  flag.detach();
  asshole.detach();
  //delay(500);
}

void executeServo() {
  if(servoactive==true) {
    //hood
    movehood(hoodcurrent);
    //Serial.print("hood Servo moved to ");
    //Serial.println(hoodcurrent);
    
    //finger
    movefinger(fingercurrent);
    //Serial.print("finger Servo moved to ");
    //Serial.println(fingercurrent);
    
    //flag
    moveflag(flagcurrent);
    //Serial.print("flag Servo moved to ");
    //Serial.println(flagcurrent);
    
    //asshole
    moveasshole(assholecurrent);
    //Serial.print("asshole Servo moved to ");
    //Serial.println(assholecurrent);
    
  }
}




void movefinger(int speed) {
  int angle = map(speed, 1000, 2000, 0, 180);
  finger.write(angle);
}

void movehood(int speed) {
  int angle = map(speed, 1000, 2000, 0, 180);
  hood.write(angle);
}
void moveflag(int speed) {
  int angle = map(speed, 1000, 2000, 0, 180);
  flag.write(angle);
  
}

void moveasshole(int speed) {
  int angle = map(speed, 1000, 2000, 0, 180);
  asshole.write(angle);
}

void allwhite() {
      setled(CRGB::White);
      FastLED.show();
       
}

void allblack() {
      setled(CRGB::Black);
      FastLED.show();
       
}

void glow() {
      CRGB color;
      switch(colorcode) {
          case 1:
            color = CRGB::DarkBlue;
            break;
          case 2:
            color = CRGB::Yellow;
            break;
          case 5:
            color = CRGB::OrangeRed;
            break;
          case 3:
            color = CRGB::DarkGreen;
            break;
          case 4:
            color = CRGB::Pink;
            break;
          default:
            color = CRGB::DarkRed;    
      }


      setled(color);
      
      if(glowstate==false) {
        if(brightness<presetbrightness) {
          brightness=brightness+3;
          if(brightness>=presetbrightness) {
            glowstate=true;
          }
        } else {
          glowstate=true;
        }
      } else {
        if(brightness>10) {
          brightness=brightness-3;
          if(brightness<=10) {
            glowstate=false;
            colorcode=random(0,3);
            colorcode=1;//keep red
          }
        } else {
          glowstate=false;
        }

      }
      addGlitter(20);
      FastLED.setBrightness(brightness);
      FastLED.show();
      delay(1);
      setled(color);
      FastLED.setBrightness(brightness);
      FastLED.show();
      delay(15);  

      //delay(1000); 
}

void setled(CRGB ledcolor) {
  for( int i = 0; i < NUM_LEDS; i++) {
    leds[i] = ledcolor;
  }
}

void addGlitter( fract8 chanceOfGlitter) 
{
  if( random8() < chanceOfGlitter) {
    leds[ random16(NUM_LEDS) ] += CRGB::White;
  }
}
