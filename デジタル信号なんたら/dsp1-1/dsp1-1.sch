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
L LEMO2 ECM
U 1 1 57200A56
P 4700 3100
F 0 "ECM" H 4700 3300 50  0000 C CNN
F 1 "IC1" H 4700 2900 50  0000 C CNN
F 2 "" H 4700 3100 50  0000 C CNN
F 3 "" H 4700 3100 50  0000 C CNN
	1    4700 3100
	-1   0    0    1   
$EndComp
$Comp
L C 4.7μF
U 1 1 57200C60
P 5500 3050
F 0 "4.7μF" H 5525 3150 50  0000 L CNN
F 1 "C" H 5525 2950 50  0000 L CNN
F 2 "" H 5538 2900 50  0000 C CNN
F 3 "" H 5500 3050 50  0000 C CNN
	1    5500 3050
	0    1    1    0   
$EndComp
Wire Wire Line
	5050 3050 5350 3050
Wire Wire Line
	5650 3050 5800 3050
Text GLabel 5800 3050 2    60   Input ~ 0
output
$Comp
L GND #PWR?
U 1 1 57200EB1
P 5050 3150
F 0 "#PWR?" H 5050 2900 50  0001 C CNN
F 1 "GND" H 5050 3000 50  0000 C CNN
F 2 "" H 5050 3150 50  0000 C CNN
F 3 "" H 5050 3150 50  0000 C CNN
	1    5050 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 3050 5200 2800
Connection ~ 5200 3050
$Comp
L R 1kΩ
U 1 1 57200F3C
P 5200 2650
F 0 "1kΩ" V 5280 2650 50  0000 C CNN
F 1 "R" V 5200 2650 50  0000 C CNN
F 2 "" V 5130 2650 50  0000 C CNN
F 3 "" H 5200 2650 50  0000 C CNN
	1    5200 2650
	1    0    0    -1  
$EndComp
$Comp
L +12V #PWR?
U 1 1 5720100F
P 5200 2500
F 0 "#PWR?" H 5200 2350 50  0001 C CNN
F 1 "+12V" H 5200 2640 50  0000 C CNN
F 2 "" H 5200 2500 50  0000 C CNN
F 3 "" H 5200 2500 50  0000 C CNN
	1    5200 2500
	1    0    0    -1  
$EndComp
$EndSCHEMATC
