EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:wemos_mini
LIBS:Wled_christmas_tree-cache
EELAYER 25 0
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
L WeMos_mini U1
U 1 1 6004796F
P 3050 2000
F 0 "U1" H 3050 2500 60  0000 C CNN
F 1 "WeMos_mini" H 3050 1500 60  0000 C CNN
F 2 "" H 3600 1300 60  0000 C CNN
F 3 "" H 3600 1300 60  0000 C CNN
	1    3050 2000
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x02 J6
U 1 1 600479AF
P 2750 1350
F 0 "J6" H 2750 1450 50  0000 C CNN
F 1 "Conn_01x02" H 2750 1150 50  0000 C CNN
F 2 "" H 2750 1350 50  0001 C CNN
F 3 "" H 2750 1350 50  0001 C CNN
	1    2750 1350
	1    0    0    1   
$EndComp
$Comp
L Conn_01x02 J7
U 1 1 60047B33
P 3350 1350
F 0 "J7" H 3350 1450 50  0000 C CNN
F 1 "Conn_01x02" H 3350 1150 50  0000 C CNN
F 2 "" H 3350 1350 50  0001 C CNN
F 3 "" H 3350 1350 50  0001 C CNN
	1    3350 1350
	-1   0    0    1   
$EndComp
$Comp
L Conn_01x10 J5
U 1 1 60047BB6
P 1800 1950
F 0 "J5" H 1800 2450 50  0000 C CNN
F 1 "Extra_pin_esp32_1" H 1800 1350 50  0000 C CNN
F 2 "" H 1800 1950 50  0001 C CNN
F 3 "" H 1800 1950 50  0001 C CNN
	1    1800 1950
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x10 J8
U 1 1 60047C1A
P 4350 1950
F 0 "J8" H 4350 2450 50  0000 C CNN
F 1 "Extra_pin_esp32_2" H 4350 1350 50  0000 C CNN
F 2 "" H 4350 1950 50  0001 C CNN
F 3 "" H 4350 1950 50  0001 C CNN
	1    4350 1950
	-1   0    0    -1  
$EndComp
NoConn ~ 3550 1250
NoConn ~ 3550 1350
NoConn ~ 4550 1550
NoConn ~ 4550 1650
NoConn ~ 4550 1750
NoConn ~ 4550 1850
NoConn ~ 4550 1950
NoConn ~ 4550 2050
NoConn ~ 4550 2150
NoConn ~ 4550 2250
NoConn ~ 4550 2350
NoConn ~ 4550 2450
NoConn ~ 2550 1250
NoConn ~ 2550 1350
NoConn ~ 1600 1550
NoConn ~ 1600 1650
NoConn ~ 1600 1750
NoConn ~ 1600 1850
NoConn ~ 1600 1950
NoConn ~ 1600 2050
NoConn ~ 1600 2150
NoConn ~ 1600 2250
NoConn ~ 1600 2350
NoConn ~ 1600 2450
$Comp
L +5V #PWR01
U 1 1 60047DB7
P 2350 1550
F 0 "#PWR01" H 2350 1400 50  0001 C CNN
F 1 "+5V" H 2350 1690 50  0000 C CNN
F 2 "" H 2350 1550 50  0001 C CNN
F 3 "" H 2350 1550 50  0001 C CNN
	1    2350 1550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 60047DE9
P 2050 1750
F 0 "#PWR02" H 2050 1500 50  0001 C CNN
F 1 "GND" H 2050 1600 50  0000 C CNN
F 2 "" H 2050 1750 50  0001 C CNN
F 3 "" H 2050 1750 50  0001 C CNN
	1    2050 1750
	1    0    0    -1  
$EndComp
Text GLabel 2500 1850 0    60   Input ~ 0
LED1
Text GLabel 2500 2150 0    60   Input ~ 0
LED3
Text GLabel 3650 2050 2    60   Input ~ 0
LED2
Text GLabel 3900 1900 2    60   Input ~ 0
RELAY
Wire Wire Line
	3550 1950 3650 1950
Wire Wire Line
	3650 1950 3650 1900
Wire Wire Line
	3650 1900 3900 1900
Wire Wire Line
	3650 2050 3550 2050
Wire Wire Line
	2350 1550 2350 1650
Wire Wire Line
	2350 1650 2550 1650
Wire Wire Line
	2050 1750 2550 1750
Wire Wire Line
	2550 1850 2500 1850
Wire Wire Line
	2500 2150 2550 2150
NoConn ~ 2550 2350
NoConn ~ 2550 2250
NoConn ~ 2550 2050
NoConn ~ 2550 1950
NoConn ~ 3550 1650
NoConn ~ 3550 1750
NoConn ~ 3550 1850
NoConn ~ 3550 2150
NoConn ~ 3550 2250
NoConn ~ 3550 2350
$Comp
L R R1
U 1 1 6004809F
P 5950 4350
F 0 "R1" V 6030 4350 50  0000 C CNN
F 1 "10k" V 5950 4350 50  0000 C CNN
F 2 "" V 5880 4350 50  0001 C CNN
F 3 "" H 5950 4350 50  0001 C CNN
	1    5950 4350
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 6004814F
P 5600 3950
F 0 "R5" V 5680 3950 50  0000 C CNN
F 1 "1K" V 5600 3950 50  0000 C CNN
F 2 "" V 5530 3950 50  0001 C CNN
F 3 "" H 5600 3950 50  0001 C CNN
	1    5600 3950
	0    1    1    0   
$EndComp
Wire Wire Line
	5750 3950 6200 3950
Wire Wire Line
	5950 4200 5950 3950
Connection ~ 5950 3950
Wire Wire Line
	5450 3950 5100 3950
Text GLabel 5100 3950 0    60   Input ~ 0
RELAY
$Comp
L GND #PWR03
U 1 1 600482A3
P 5950 4700
F 0 "#PWR03" H 5950 4450 50  0001 C CNN
F 1 "GND" H 5950 4550 50  0000 C CNN
F 2 "" H 5950 4700 50  0001 C CNN
F 3 "" H 5950 4700 50  0001 C CNN
	1    5950 4700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 600482C7
P 7350 4650
F 0 "#PWR04" H 7350 4400 50  0001 C CNN
F 1 "GND" H 7350 4500 50  0000 C CNN
F 2 "" H 7350 4650 50  0001 C CNN
F 3 "" H 7350 4650 50  0001 C CNN
	1    7350 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 4500 5950 4700
$Comp
L SANYOU_SRD_Form_A K1
U 1 1 6004881E
P 7150 3100
F 0 "K1" H 7500 3250 50  0000 L CNN
F 1 "JS1a-5V" H 7500 3150 50  0000 L CNN
F 2 "Relays_THT:Relay_SPDT_SANYOU_SRD_Series_Form_A" H 8400 3050 50  0001 C CNN
F 3 "" H 7150 3100 50  0001 C CNN
	1    7150 3100
	1    0    0    -1  
$EndComp
$Comp
L D D1
U 1 1 6004888C
P 6500 3100
F 0 "D1" H 6500 3200 50  0000 C CNN
F 1 "D" H 6500 3000 50  0000 C CNN
F 2 "" H 6500 3100 50  0001 C CNN
F 3 "" H 6500 3100 50  0001 C CNN
	1    6500 3100
	0    1    1    0   
$EndComp
$Comp
L VDC #PWR05
U 1 1 60048912
P 7350 2500
F 0 "#PWR05" H 7350 2400 50  0001 C CNN
F 1 "VDC" H 7350 2750 50  0000 C CNN
F 2 "" H 7350 2500 50  0001 C CNN
F 3 "" H 7350 2500 50  0001 C CNN
	1    7350 2500
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR06
U 1 1 60048958
P 6950 2500
F 0 "#PWR06" H 6950 2350 50  0001 C CNN
F 1 "+5V" H 6950 2640 50  0000 C CNN
F 2 "" H 6950 2500 50  0001 C CNN
F 3 "" H 6950 2500 50  0001 C CNN
	1    6950 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6950 2500 6950 2800
Wire Wire Line
	6500 2950 6500 2650
Wire Wire Line
	6500 2650 6950 2650
Connection ~ 6950 2650
Wire Wire Line
	7350 2500 7350 2800
Wire Wire Line
	6500 3250 6500 3750
Wire Wire Line
	6950 3400 6950 3550
Wire Wire Line
	6950 3550 6500 3550
Connection ~ 6500 3550
$Comp
L CP C1
U 1 1 60048AAF
P 7350 3900
F 0 "C1" H 7375 4000 50  0000 L CNN
F 1 "1000uF" H 7375 3800 50  0000 L CNN
F 2 "" H 7388 3750 50  0001 C CNN
F 3 "" H 7350 3900 50  0001 C CNN
	1    7350 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 4650 6500 4650
Connection ~ 5950 4650
Wire Wire Line
	6500 4650 6500 4150
Wire Wire Line
	7350 4050 7350 4650
Wire Wire Line
	7350 3400 7350 3750
$Comp
L BC337 Q1
U 1 1 60048C4D
P 6400 3950
F 0 "Q1" H 6600 4025 50  0000 L CNN
F 1 "2N2222" H 6600 3950 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Molded_Narrow" H 6600 3875 50  0001 L CIN
F 3 "" H 6400 3950 50  0001 L CNN
	1    6400 3950
	1    0    0    -1  
$EndComp
$Comp
L 74LS125 U2
U 1 1 60049055
P 2150 4100
F 0 "U2" H 2150 4200 50  0000 L BNN
F 1 "SN74AHCT125" H 2200 3950 50  0000 L TNN
F 2 "" H 2150 4100 50  0001 C CNN
F 3 "" H 2150 4100 50  0001 C CNN
	1    2150 4100
	1    0    0    -1  
$EndComp
$Comp
L 74LS125 U2
U 2 1 60049148
P 2150 5850
F 0 "U2" H 2150 5950 50  0000 L BNN
F 1 "SN74AHCT125" H 2200 5700 50  0000 L TNN
F 2 "" H 2150 5850 50  0001 C CNN
F 3 "" H 2150 5850 50  0001 C CNN
	2    2150 5850
	1    0    0    -1  
$EndComp
$Comp
L 74LS125 U2
U 3 1 60049181
P 2150 5000
F 0 "U2" H 2150 5100 50  0000 L BNN
F 1 "SN74AHCT125" H 2200 4850 50  0000 L TNN
F 2 "" H 2150 5000 50  0001 C CNN
F 3 "" H 2150 5000 50  0001 C CNN
	3    2150 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 6000 2000 6150
Wire Wire Line
	2000 6150 2150 6150
Wire Wire Line
	2150 6150 2150 6200
Wire Wire Line
	2000 3950 2000 3700
$Comp
L C C3
U 1 1 60049505
P 2250 3700
F 0 "C3" H 2275 3800 50  0000 L CNN
F 1 "0.1uF" V 2050 3650 50  0000 L CNN
F 2 "" H 2288 3550 50  0001 C CNN
F 3 "" H 2250 3700 50  0001 C CNN
	1    2250 3700
	0    1    1    0   
$EndComp
Wire Wire Line
	1550 3700 2100 3700
Wire Wire Line
	2400 3700 2500 3700
Wire Wire Line
	1550 3700 1550 3650
Connection ~ 2000 3700
$Comp
L GND #PWR07
U 1 1 600496DB
P 2500 3700
F 0 "#PWR07" H 2500 3450 50  0001 C CNN
F 1 "GND" H 2500 3550 50  0000 C CNN
F 2 "" H 2500 3700 50  0001 C CNN
F 3 "" H 2500 3700 50  0001 C CNN
	1    2500 3700
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR08
U 1 1 6004970F
P 2150 4400
F 0 "#PWR08" H 2150 4150 50  0001 C CNN
F 1 "GND" H 2150 4250 50  0000 C CNN
F 2 "" H 2150 4400 50  0001 C CNN
F 3 "" H 2150 4400 50  0001 C CNN
	1    2150 4400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR09
U 1 1 60049743
P 2150 5300
F 0 "#PWR09" H 2150 5050 50  0001 C CNN
F 1 "GND" H 2150 5150 50  0000 C CNN
F 2 "" H 2150 5300 50  0001 C CNN
F 3 "" H 2150 5300 50  0001 C CNN
	1    2150 5300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR010
U 1 1 600499B7
P 2150 6200
F 0 "#PWR010" H 2150 5950 50  0001 C CNN
F 1 "GND" H 2150 6050 50  0000 C CNN
F 2 "" H 2150 6200 50  0001 C CNN
F 3 "" H 2150 6200 50  0001 C CNN
	1    2150 6200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR011
U 1 1 600499EB
P 2100 7150
F 0 "#PWR011" H 2100 6900 50  0001 C CNN
F 1 "GND" H 2100 7000 50  0000 C CNN
F 2 "" H 2100 7150 50  0001 C CNN
F 3 "" H 2100 7150 50  0001 C CNN
	1    2100 7150
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR012
U 1 1 60049A1F
P 1550 3650
F 0 "#PWR012" H 1550 3500 50  0001 C CNN
F 1 "+5V" H 1550 3790 50  0000 C CNN
F 2 "" H 1550 3650 50  0001 C CNN
F 3 "" H 1550 3650 50  0001 C CNN
	1    1550 3650
	1    0    0    -1  
$EndComp
Text GLabel 1550 4100 0    60   Input ~ 0
LED1
Text GLabel 1550 5000 0    60   Input ~ 0
LED2
Text GLabel 1550 5850 0    60   Input ~ 0
LED3
Wire Wire Line
	1550 4100 1700 4100
Wire Wire Line
	1700 5000 1550 5000
Wire Wire Line
	1550 5850 1700 5850
$Comp
L 74LS125 U2
U 4 1 600491B2
P 2100 6850
F 0 "U2" H 2100 6950 50  0000 L BNN
F 1 "SN74AHCT125" H 2150 6700 50  0000 L TNN
F 2 "" H 2100 6850 50  0001 C CNN
F 3 "" H 2100 6850 50  0001 C CNN
	4    2100 6850
	1    0    0    -1  
$EndComp
Wire Wire Line
	1650 6850 1650 7150
Wire Wire Line
	1650 7150 2100 7150
$Comp
L R R2
U 1 1 6004A91F
P 3050 4100
F 0 "R2" V 3130 4100 50  0000 C CNN
F 1 "100 - 500 ohm" V 2950 4100 50  0000 C CNN
F 2 "" V 2980 4100 50  0001 C CNN
F 3 "" H 3050 4100 50  0001 C CNN
	1    3050 4100
	0    1    1    0   
$EndComp
$Comp
L R R3
U 1 1 6004A968
P 3050 5000
F 0 "R3" V 3130 5000 50  0000 C CNN
F 1 "100 - 500 ohm" V 2950 5000 50  0000 C CNN
F 2 "" V 2980 5000 50  0001 C CNN
F 3 "" H 3050 5000 50  0001 C CNN
	1    3050 5000
	0    1    1    0   
$EndComp
$Comp
L R R4
U 1 1 6004A9D9
P 3050 5850
F 0 "R4" V 3130 5850 50  0000 C CNN
F 1 "100 - 500 ohm" V 2950 5850 50  0000 C CNN
F 2 "" V 2980 5850 50  0001 C CNN
F 3 "" H 3050 5850 50  0001 C CNN
	1    3050 5850
	0    1    1    0   
$EndComp
Wire Wire Line
	2600 5000 2900 5000
Wire Wire Line
	2600 5850 2900 5850
Wire Wire Line
	2900 4100 2600 4100
Text GLabel 3600 4100 2    60   Input ~ 0
LED_OUT_1
Text GLabel 3600 5000 2    60   Input ~ 0
LED_OUT_2
Text GLabel 3600 5850 2    60   Input ~ 0
LED_OUT_3
Wire Wire Line
	3200 4100 3600 4100
Wire Wire Line
	3200 5000 3600 5000
Wire Wire Line
	3200 5850 3600 5850
$Comp
L Conn_01x03 J4
U 1 1 6004B690
P 6050 6950
F 0 "J4" H 6050 7150 50  0000 C CNN
F 1 "Conn_01x03" H 6050 6750 50  0000 C CNN
F 2 "" H 6050 6950 50  0001 C CNN
F 3 "" H 6050 6950 50  0001 C CNN
	1    6050 6950
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x03 J3
U 1 1 6004B707
P 4400 7300
F 0 "J3" H 4400 7500 50  0000 C CNN
F 1 "Conn_01x03" H 4400 7100 50  0000 C CNN
F 2 "" H 4400 7300 50  0001 C CNN
F 3 "" H 4400 7300 50  0001 C CNN
	1    4400 7300
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x03 J2
U 1 1 6004B752
P 4850 6600
F 0 "J2" H 4850 6800 50  0000 C CNN
F 1 "Conn_01x03" H 4850 6400 50  0000 C CNN
F 2 "" H 4850 6600 50  0001 C CNN
F 3 "" H 4850 6600 50  0001 C CNN
	1    4850 6600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 6850 5650 6850
Wire Wire Line
	5650 6850 5650 7050
Wire Wire Line
	5650 7050 5850 7050
Wire Wire Line
	5850 6950 5650 6950
Connection ~ 5650 6950
$Comp
L GND #PWR013
U 1 1 6004C386
P 5650 7050
F 0 "#PWR013" H 5650 6800 50  0001 C CNN
F 1 "GND" H 5650 6900 50  0000 C CNN
F 2 "" H 5650 7050 50  0001 C CNN
F 3 "" H 5650 7050 50  0001 C CNN
	1    5650 7050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 7200 4200 7200
Wire Wire Line
	4000 7200 4000 7400
Wire Wire Line
	4000 7400 4200 7400
Wire Wire Line
	4200 7300 4000 7300
Connection ~ 4000 7300
Connection ~ 4000 7200
Text GLabel 3900 7200 0    60   Input ~ 0
+5V_LED
Text GLabel 7650 3600 2    60   Input ~ 0
+5V_LED
Wire Wire Line
	7650 3600 7350 3600
Connection ~ 7350 3600
NoConn ~ 2550 6850
NoConn ~ 4000 5000
Text GLabel 4550 6500 0    60   Input ~ 0
LED_OUT_2
Text GLabel 4550 6700 0    60   Input ~ 0
LED_OUT_3
Text GLabel 3900 6600 0    60   Input ~ 0
LED_OUT_1
Wire Wire Line
	4550 6500 4650 6500
Wire Wire Line
	4650 6600 3900 6600
Wire Wire Line
	4550 6700 4650 6700
$Comp
L Screw_Terminal_01x02 J1
U 1 1 6004DA25
P 6700 5850
F 0 "J1" H 6700 5950 50  0000 C CNN
F 1 "Screw_Terminal_01x02" H 6700 5650 50  0000 C CNN
F 2 "" H 6700 5850 50  0001 C CNN
F 3 "" H 6700 5850 50  0001 C CNN
	1    6700 5850
	-1   0    0    1   
$EndComp
$Comp
L Fuse F1
U 1 1 6004DA98
P 7500 5350
F 0 "F1" V 7580 5350 50  0000 C CNN
F 1 "DC car fuse 4A" V 7425 5350 50  0000 C CNN
F 2 "" V 7430 5350 50  0001 C CNN
F 3 "" H 7500 5350 50  0001 C CNN
	1    7500 5350
	0    1    1    0   
$EndComp
$Comp
L D D2
U 1 1 6004DB7F
P 8300 5350
F 0 "D2" H 8300 5450 50  0000 C CNN
F 1 "1N5819" H 8300 5250 50  0000 C CNN
F 2 "" H 8300 5350 50  0001 C CNN
F 3 "" H 8300 5350 50  0001 C CNN
	1    8300 5350
	-1   0    0    1   
$EndComp
$Comp
L D D3
U 1 1 6004DBF2
P 7900 5750
F 0 "D3" H 7900 5850 50  0000 C CNN
F 1 "SK36A" H 7900 5650 50  0000 C CNN
F 2 "" H 7900 5750 50  0001 C CNN
F 3 "" H 7900 5750 50  0001 C CNN
	1    7900 5750
	0    1    1    0   
$EndComp
$Comp
L Polyfuse F2
U 1 1 6004DC49
P 9050 5350
F 0 "F2" V 8950 5350 50  0000 C CNN
F 1 "Polyfuse 0.5A" V 9150 5350 50  0000 C CNN
F 2 "" H 9100 5150 50  0001 L CNN
F 3 "" H 9050 5350 50  0001 C CNN
	1    9050 5350
	0    1    1    0   
$EndComp
$Comp
L CP C2
U 1 1 6004DCB8
P 9450 5750
F 0 "C2" H 9475 5850 50  0000 L CNN
F 1 "100uF" H 9475 5650 50  0000 L CNN
F 2 "" H 9488 5600 50  0001 C CNN
F 3 "" H 9450 5750 50  0001 C CNN
	1    9450 5750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 5350 7200 5350
Wire Wire Line
	7200 5350 7200 5750
Wire Wire Line
	7200 5750 6900 5750
Wire Wire Line
	7650 5350 8150 5350
Wire Wire Line
	7900 5050 7900 5600
Connection ~ 7900 5350
Wire Wire Line
	6900 5850 7200 5850
Wire Wire Line
	7200 5850 7200 6100
Wire Wire Line
	7200 6050 9450 6050
Wire Wire Line
	7900 5900 7900 6100
Wire Wire Line
	9450 6050 9450 5900
Connection ~ 7900 6050
Wire Wire Line
	8450 5350 8900 5350
Wire Wire Line
	9200 5350 10000 5350
Wire Wire Line
	9450 5350 9450 5600
Wire Wire Line
	10000 5350 10000 5050
Connection ~ 9450 5350
$Comp
L VDC #PWR014
U 1 1 6004F043
P 7900 5050
F 0 "#PWR014" H 7900 4950 50  0001 C CNN
F 1 "VDC" H 7900 5300 50  0000 C CNN
F 2 "" H 7900 5050 50  0001 C CNN
F 3 "" H 7900 5050 50  0001 C CNN
	1    7900 5050
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR015
U 1 1 6004F08F
P 10000 5050
F 0 "#PWR015" H 10000 4900 50  0001 C CNN
F 1 "+5V" H 10000 5190 50  0000 C CNN
F 2 "" H 10000 5050 50  0001 C CNN
F 3 "" H 10000 5050 50  0001 C CNN
	1    10000 5050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR016
U 1 1 6004F0DB
P 7900 6100
F 0 "#PWR016" H 7900 5850 50  0001 C CNN
F 1 "GND" H 7900 5950 50  0000 C CNN
F 2 "" H 7900 6100 50  0001 C CNN
F 3 "" H 7900 6100 50  0001 C CNN
	1    7900 6100
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG017
U 1 1 6004F31D
P 9450 5350
F 0 "#FLG017" H 9450 5425 50  0001 C CNN
F 1 "PWR_FLAG" H 9450 5500 50  0000 C CNN
F 2 "" H 9450 5350 50  0001 C CNN
F 3 "" H 9450 5350 50  0001 C CNN
	1    9450 5350
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG018
U 1 1 6004F5D1
P 7350 3600
F 0 "#FLG018" H 7350 3675 50  0001 C CNN
F 1 "PWR_FLAG" H 7350 3750 50  0000 C CNN
F 2 "" H 7350 3600 50  0001 C CNN
F 3 "" H 7350 3600 50  0001 C CNN
	1    7350 3600
	0    -1   -1   0   
$EndComp
Text Notes 6100 1850 0    157  ~ 0
Led wires:\n- left, copper (red) wire -> +5V\n- center, silver (black) wire -> GND\n- right, silver (yellow) wire -> DATA
$Comp
L PWR_FLAG #FLG019
U 1 1 60051801
P 7200 6100
F 0 "#FLG019" H 7200 6175 50  0001 C CNN
F 1 "PWR_FLAG" H 7200 6250 50  0000 C CNN
F 2 "" H 7200 6100 50  0001 C CNN
F 3 "" H 7200 6100 50  0001 C CNN
	1    7200 6100
	-1   0    0    1   
$EndComp
Connection ~ 7200 6050
$EndSCHEMATC
