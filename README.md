# uselessbox
Just another useless box

3D printed useless box or so called useless machines. Arduino driven. Features 4 servos and a gesture/proximity sensor. Contains a 16 LED neopixel ring. All parts are easy to source. 

## Video in Action
https://www.youtube.com/watch?v=pDcApzEbbxg


## List of parts, sources (no affiliate links)
1x Arduino Nano V3 5V

1x Gesture/proximity sensor, 5V (!) similar to https://www.distrelec.de/de/naeherungs-licht-rgb-und-gestensensor-apds9960-5v-adafruit-3595/p/30139163

1x switch, similar to https://www.amazon.de/gp/product/B07MY2WVQ3/

1x jack similar to https://www.amazon.de/gp/product/B009PH1J5Y/

1x power adaptor similar to https://www.amazon.de/gp/product/B07HSPT57Y

4x servo motors, similar to https://www.amazon.de/gp/product/B06XQD18QN

cables, solder stuff

22x M3*10 scews

5x M3*8 screws

2x M3*20 screws

1x Neopixel 16 LED ring similar to https://www.distrelec.de/de/neopixel-ring-mit-16-rgb-leds-adafruit-1463-neopixel/p/30091142

1x resistor 1/4W 260 Ohm

1x resistor 1/4W 10 kOhm

20x 2.54mm pin headers

2x 5mm 2pol screw terminals

some steering servo push wire, 0.6mm will do. You need about 10 cm.

some double sided tape

optional: stuff to create PCBs


## Instructions
Optional: create your PCB

Just 3d print the parts, each part one time. I printed the "OK fingers" in 0.1mm, and all other stuff in 0.25mm. I used cubic infill, 2 shells, and 3 shells on bottom and top. I did not use any support except for the LED housing. I was using PLA from https://dasfilament.de

Mount one servo to the back part. The axis on top is showing to the outside. Add the lid servo arm. Mount the lid to the back using M3*20 screws. Now use the steering servo push wire. Make sure your servo is at center position when doing that. Make the wire as long as you need it so the lid and back are located rectangular.

Mount the back to the bottom, using 4 M3*10 screws. 

Mount the usb door using the usb door frame, to the the front. Mount the front to the bottom using 4 M3*10 screws.

Mount the jack to the bottom rear and lock it using the "Buchsenhalter" (sorry, forgot to translate it) to the bottom. Use 2 M3*8 screws.

Solder 5 cables to the gesture sensor board, but do not use the pins for this breakout board. If you have, use some old servo cable or anything similar that would match to pins at your main board if you use any. If there are no pins, you will have to solder the wires to the main board later. Make the cables around 15cm long. Mount the sensor board to the top, using the Sensorlock and 2 M3*8 screws.

Solder 2 cables to your switch. Mount the switch to the top. The "on position" of the switch has to show away from the sensor board. Make these cables around 15cm long.

Solder 3 more cables to your neopixel ring (ground, V+, data in). Make these cables 15 cm long, and use again some old servo cables or other cables matching pins. Add the neopixel ring to the housing, and close it using the LED cover. Btw, print this in transparent filament, if you have. Nice light effects are waiting for you. Lock the housing and the cover by another M3*8 screw. The neopixel ring points towards the cover with its LEDs. Mount the LED housing on top of your top part, and lock it using some M3*10 screws. The LED point towards the front. Moint the "flag arm" to one servo, and this servo to the top part. If you look from behind, the axis points to you and to the left. You can add some white label to the flag holder, to create a small flag. Mount the top to the front using another 4 M3*10 screws.

Mount the finger to one servo, do not lock it up yet. Mount the servo to the right housing part, axis to the right. Mount the right housing to the already mounted parts, mount it on the right side when you look from behind! Use 5 M3*10 screws.

OK, we enter the finish line, slowly...

Mount the 4th servo to the "left" part. Axis point to the front, but downwards. Connect OK fingers and "assholearm" together using another M3*10 screw. Mount the whole arm to the servo. DO NOT CLOSE THE HOUSING YET!

Connect all wires (servos, LED, switch, jack, gesture sensor) to your PCB. Take care for not short cutting anything. Use double sided tape and mount your PCB in a way you can reach the USB of te arduino throught the "usb door" at the front of your housing. Make sure again you do not block any servo movement by cables.

It is time to connect the power adaptor. If nothing smokes, you got your solder job the right way.

Make sure the switch on top of your new toy is in Off position, pointing to the front. Connect USB and your PC. Fire up your Arduino IDE, load the sketch and push it to the Arduino. Maybe you need to activate libraries for servos, or FastLED or the gesture sensor. Just follow the instruction of these vendors.

After the reboot, the LED should light up in blue and kind of glow...if you put your finger on the sensor, it should glow red, brightness depending on how close your finger is to the sensor.

At the same time, all your servos were "reset". You can now tighten all the screws of the servo arms connecting to the servo heads.

Servo for Lid: in reset position the LID should be closed

Servo for Flag: in reset position the flag arm should be horizontal, but below the edge of the top.

Servo for OKFinger/Asshole: The door should be closed, the fingers hidden.

Servo for Finger: Tricky one. Push the switch backwards and watch your finger if it makes it way to the switch. Idealy, it should turn the switch off. Just adjust until this happens. Hint: give a little extra push, just about 2-3 mm. Finally, tighten the screw.

OK, if all mechanics are working as expected, your useless machine should work as expected. You can now close the housing, using the last 5 M3*10 screws.

## What does it do?
Basically, the Arduino will cycle trough different ways the servos work. To start the machine, just push the switch to on. The main task of this machine is to push the switch into its off position.

Step 1: open lid, push switch off

Step 2: open lid very harsh, push switch off. After that the lid will open depending on how close your finger is to the sensor.

Step 3: open lid again, push switch off

Step 4: open lid, waving white flag, close the lid. Open the lid, push off the switch, close the lid.

Step 5: show the OK finger / asshole finger (as you prefer), then open the lid, push the switch, close the lid.


Of course you are invited to extent the possible action, color codes and so on. Just make sure to not use "delay()" too heavy, since this will interrupt the glowing of the LED.

## Frequently asked questions
### Why do you enable and disable the servos that much?
I found my servos to be really cheap ones. They interfere with each other. Disabling the servos I do not need for the moment solved this. However, in the video you can see the servos "choking". If you can, buy quality servos.


## Crosslinks

Repo
https://github.com/pstimpel/uselessbox

Thingiverse
https://www.thingiverse.com/thing:3901482

Prusaprinters
https://www.prusaprinters.org/prints/6042-another-useless-box

Youtube
https://www.youtube.com/watch?v=pDcApzEbbxg
