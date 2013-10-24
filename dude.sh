#!/bin/bash
MCU="t2313"
PROG="linuxspi"
PORT="/dev/spidev0.0"
FLELF="./bin/program.elf"
BAUD=100000
sudo avrdude -c $PROG -p $MCU -P $PORT -b $BAUD -U :w:$FLELF
echo "Dude.sh done"
