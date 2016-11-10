EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
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
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "13 may 2016"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L HA2540 IC1
U 1 1 57354C3F
P 3900 1900
F 0 "IC1" H 4000 2100 70  0000 C CNN
F 1 "NJM4580" H 4150 1700 70  0000 C CNN
F 2 "" H 3900 1900 60  0000 C CNN
F 3 "" H 3900 1900 60  0000 C CNN
	1    3900 1900
	1    0    0    -1  
$EndComp
Text GLabel 2350 1800 0    60   Input ~ 0
INPUT
$Comp
L R R1
U 1 1 57354D82
P 2700 1800
F 0 "R1" V 2780 1800 40  0000 C CNN
F 1 "3.3k" V 2707 1801 40  0000 C CNN
F 2 "~" V 2630 1800 30  0000 C CNN
F 3 "~" H 2700 1800 30  0000 C CNN
	1    2700 1800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2950 1800 3300 1800
Wire Wire Line
	2450 1800 2350 1800
Wire Wire Line
	3100 2100 3100 2000
Wire Wire Line
	3100 2000 3300 2000
Wire Wire Line
	4500 1900 4800 1900
Text GLabel 4800 1900 2    60   Output ~ 0
OUTPUT
$Comp
L -12V #PWR?
U 1 1 57354DF8
P 3900 2400
F 0 "#PWR?" H 3900 2530 20  0001 C CNN
F 1 "-12V" H 3900 2500 30  0000 C CNN
F 2 "" H 3900 2400 60  0000 C CNN
F 3 "" H 3900 2400 60  0000 C CNN
	1    3900 2400
	-1   0    0    1   
$EndComp
Wire Wire Line
	3900 2300 3900 2400
Wire Wire Line
	3900 1500 3900 1400
$Comp
L +12V #PWR?
U 1 1 57354E1F
P 3900 1400
F 0 "#PWR?" H 3900 1350 20  0001 C CNN
F 1 "+12V" H 3900 1500 30  0000 C CNN
F 2 "" H 3900 1400 60  0000 C CNN
F 3 "" H 3900 1400 60  0000 C CNN
	1    3900 1400
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 57354E38
P 3900 1150
F 0 "R2" V 3980 1150 40  0000 C CNN
F 1 "3.3k" V 3907 1151 40  0000 C CNN
F 2 "~" V 3830 1150 30  0000 C CNN
F 3 "~" H 3900 1150 30  0000 C CNN
	1    3900 1150
	0    -1   -1   0   
$EndComp
$Comp
L C C1
U 1 1 57354E5B
P 3900 850
F 0 "C1" H 3900 950 40  0000 L CNN
F 1 "0.047" H 3906 765 10  0000 L CNN
F 2 "~" H 3938 700 30  0000 C CNN
F 3 "~" H 3900 850 60  0000 C CNN
	1    3900 850 
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3150 850  3150 1800
Wire Wire Line
	3150 1150 3650 1150
Connection ~ 3150 1800
Wire Wire Line
	4150 1150 4650 1150
Wire Wire Line
	4650 850  4650 1900
Connection ~ 4650 1900
Wire Wire Line
	3150 850  3700 850 
Connection ~ 3150 1150
Wire Wire Line
	4100 850  4650 850 
Connection ~ 4650 1150
$Comp
L GND #PWR?
U 1 1 57354EDB
P 3100 2100
F 0 "#PWR?" H 3100 2100 30  0001 C CNN
F 1 "GND" H 3100 2030 30  0001 C CNN
F 2 "" H 3100 2100 60  0000 C CNN
F 3 "" H 3100 2100 60  0000 C CNN
	1    3100 2100
	1    0    0    -1  
$EndComp
$EndSCHEMATC
