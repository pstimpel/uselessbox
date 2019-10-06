EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Module:Arduino_Nano_v3.x A1
U 1 1 5D8BD22D
P 5150 3800
F 0 "A1" V 5150 2756 50  0000 R CNN
F 1 "n" V 5195 2757 50  0001 R CNN
F 2 "Module:Arduino_Nano" H 5300 2850 50  0001 L CNN
F 3 "http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf" H 5150 2800 50  0001 C CNN
	1    5150 3800
	0    1    1    0   
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 Jswitch1
U 1 1 5D8BDE01
P 7150 3700
F 0 "Jswitch1" H 7230 3692 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 7230 3601 50  0000 L CNN
F 2 "TerminalBlock:TerminalBlock_Altech_AK300-2_P5.00mm" H 7150 3700 50  0001 C CNN
F 3 "~" H 7150 3700 50  0001 C CNN
	1    7150 3700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5D8C03C8
P 6850 4100
F 0 "R1" H 6920 4146 50  0000 L CNN
F 1 "10k" H 6920 4055 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 6780 4100 50  0001 C CNN
F 3 "~" H 6850 4100 50  0001 C CNN
	1    6850 4100
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5D8C088D
P 6250 3300
F 0 "R2" H 6320 3346 50  0000 L CNN
F 1 "270" H 6320 3255 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 6180 3300 50  0001 C CNN
F 3 "~" H 6250 3300 50  0001 C CNN
	1    6250 3300
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 Jfinger1
U 1 1 5D8C1066
P 4150 2200
F 0 "Jfinger1" H 4230 2242 50  0000 L CNN
F 1 "Conn_01x03" H 4230 2151 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 4150 2200 50  0001 C CNN
F 3 "~" H 4150 2200 50  0001 C CNN
	1    4150 2200
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 Jflag1
U 1 1 5D8C265A
P 5500 2200
F 0 "Jflag1" H 5580 2242 50  0000 L CNN
F 1 "Conn_01x03" H 5580 2151 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 5500 2200 50  0001 C CNN
F 3 "~" H 5500 2200 50  0001 C CNN
	1    5500 2200
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 Jasshole1
U 1 1 5D8C2F86
P 5500 2600
F 0 "Jasshole1" H 5580 2642 50  0000 L CNN
F 1 "Conn_01x03" H 5580 2551 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 5500 2600 50  0001 C CNN
F 3 "~" H 5500 2600 50  0001 C CNN
	1    5500 2600
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 Jled1
U 1 1 5D8C35FC
P 6750 2200
F 0 "Jled1" H 6830 2242 50  0000 L CNN
F 1 "Conn_01x03" H 6830 2151 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 6750 2200 50  0001 C CNN
F 3 "~" H 6750 2200 50  0001 C CNN
	1    6750 2200
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 Jpower1
U 1 1 5D8C4D13
P 7150 2950
F 0 "Jpower1" H 7230 2942 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 7230 2851 50  0000 L CNN
F 2 "TerminalBlock:TerminalBlock_Altech_AK300-2_P5.00mm" H 7150 2950 50  0001 C CNN
F 3 "~" H 7150 2950 50  0001 C CNN
	1    7150 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6950 2950 6500 2950
Wire Wire Line
	6950 3050 6600 3050
Wire Wire Line
	6600 3050 6600 3450
Wire Wire Line
	6600 4550 3950 4550
Wire Wire Line
	3950 4550 3950 3900
Wire Wire Line
	3950 3900 4150 3900
Wire Wire Line
	4150 3800 4150 3900
Connection ~ 4150 3900
Wire Wire Line
	6150 4000 6500 4000
Wire Wire Line
	6500 2950 6500 3700
$Comp
L Connector_Generic:Conn_01x03 Jhood1
U 1 1 5D8C1AD9
P 4150 2600
F 0 "Jhood1" H 4230 2642 50  0000 L CNN
F 1 "Conn_01x03" H 4230 2551 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 4150 2600 50  0001 C CNN
F 3 "~" H 4150 2600 50  0001 C CNN
	1    4150 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	3950 2500 3750 2500
Wire Wire Line
	3750 2500 3750 2950
Wire Wire Line
	5450 2950 5450 3300
Wire Wire Line
	3750 2950 5450 2950
Wire Wire Line
	4900 3000 4900 1900
Wire Wire Line
	4900 1900 3950 1900
Wire Wire Line
	3950 1900 3950 2100
Wire Wire Line
	5300 2500 4850 2500
Wire Wire Line
	4850 2500 4850 3300
Wire Wire Line
	4900 3000 5250 3000
Wire Wire Line
	5250 3000 5250 3300
Wire Wire Line
	5150 3300 5150 2100
Wire Wire Line
	5150 2100 5300 2100
Wire Wire Line
	6550 2300 6550 2800
Wire Wire Line
	6550 2850 6600 2850
Wire Wire Line
	6600 2850 6600 3050
Connection ~ 6600 3050
Wire Wire Line
	6550 2100 6500 2100
Wire Wire Line
	6500 2100 6500 2950
Connection ~ 6500 2950
Wire Wire Line
	5350 3300 5350 3100
Wire Wire Line
	5350 3100 6250 3100
Wire Wire Line
	6400 3100 6400 2200
Wire Wire Line
	6400 2200 6550 2200
Wire Wire Line
	6250 3150 6250 3100
Connection ~ 6250 3100
Wire Wire Line
	6250 3100 6400 3100
Wire Wire Line
	6250 3450 6600 3450
Connection ~ 6600 3450
Wire Wire Line
	6600 3450 6600 4250
Wire Wire Line
	6950 3700 6500 3700
Connection ~ 6500 3700
Wire Wire Line
	6500 3700 6500 4000
Wire Wire Line
	5550 3300 5550 3150
Wire Wire Line
	5550 3150 6150 3150
Wire Wire Line
	6150 3150 6150 3550
Wire Wire Line
	6150 3550 6800 3550
Wire Wire Line
	6800 3550 6800 3800
Wire Wire Line
	6800 3800 6850 3800
Wire Wire Line
	6850 3950 6850 3800
Connection ~ 6850 3800
Wire Wire Line
	6850 3800 6950 3800
Wire Wire Line
	6850 4250 6600 4250
Connection ~ 6600 4250
Wire Wire Line
	6600 4250 6600 4550
$Comp
L Connector_Generic:Conn_01x05 Jsensor1
U 1 1 5D8CE94D
P 3400 3500
F 0 "Jsensor1" H 3480 3542 50  0000 L CNN
F 1 "Conn_01x05" H 3480 3451 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 3400 3500 50  0001 C CNN
F 3 "~" H 3400 3500 50  0001 C CNN
	1    3400 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 4000 6500 4650
Wire Wire Line
	6500 4650 3200 4650
Wire Wire Line
	3200 4650 3200 3700
Connection ~ 6500 4000
Wire Wire Line
	3200 3600 3100 3600
Wire Wire Line
	3100 3600 3100 3900
Wire Wire Line
	3100 3900 3950 3900
Connection ~ 3950 3900
Wire Wire Line
	4650 4300 4650 4500
Wire Wire Line
	4650 4500 3000 4500
Wire Wire Line
	3000 4500 3000 3500
Wire Wire Line
	3000 3500 3200 3500
Wire Wire Line
	4750 4300 4750 4700
Wire Wire Line
	4750 4700 2850 4700
Wire Wire Line
	2850 4700 2850 3400
Wire Wire Line
	2850 3400 3200 3400
Wire Wire Line
	3200 3100 3200 3300
Wire Wire Line
	5300 2300 5300 2400
Wire Wire Line
	5300 2400 4750 2400
Wire Wire Line
	3950 2400 3950 2300
Wire Wire Line
	3950 2700 3950 2800
Wire Wire Line
	3950 2800 4750 2800
Wire Wire Line
	5300 2800 5300 2700
Wire Wire Line
	4750 2400 4750 2800
Connection ~ 4750 2400
Wire Wire Line
	4750 2400 3950 2400
Connection ~ 4750 2800
Wire Wire Line
	4750 2800 5300 2800
Wire Wire Line
	5300 2800 6550 2800
Connection ~ 5300 2800
Connection ~ 6550 2800
Wire Wire Line
	6550 2800 6550 2850
Wire Wire Line
	5300 2600 5000 2600
Wire Wire Line
	5000 2600 5000 2200
Wire Wire Line
	5000 2200 5300 2200
Wire Wire Line
	3950 2600 3650 2600
Wire Wire Line
	3650 2600 3650 2200
Wire Wire Line
	3650 2200 3950 2200
Wire Wire Line
	3650 2200 3650 1750
Wire Wire Line
	3650 1750 5000 1750
Wire Wire Line
	5000 1750 5000 2200
Connection ~ 3650 2200
Connection ~ 5000 2200
Wire Wire Line
	5000 1750 6500 1750
Wire Wire Line
	6500 1750 6500 2100
Connection ~ 5000 1750
Connection ~ 6500 2100
Wire Wire Line
	5050 3300 5050 3100
Wire Wire Line
	5050 3100 3200 3100
$EndSCHEMATC
