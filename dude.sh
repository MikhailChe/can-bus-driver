#!/bin/bash
MCU="t2313"
PROG="linuxspi"
PORT="/dev/spidev0.0"
FLELF="./bin/prog.elf"
BAUD=100000
avrdude -c $PROG -p $MCU -P $PORT -b $BAUD -U flash:w:$FLELF
echo "Dude.sh is done"
