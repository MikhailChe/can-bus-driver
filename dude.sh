#!/bin/bash
MCU="t2313"
PROG="linuxspi"
PORT="/dev/spidev0.0"
FLELF="./bin/prog.elf"
BAUD=100000
<<<<<<< HEAD
sudo avrdude -c $PROG -p $MCU -P $PORT -b $BAUD -U flash:w:$FLELF
echo "Dude.sh done"
=======
avrdude -c $PROG -p $MCU -P $PORT -b $BAUD -U flash:w:$FLELF
echo "Dude.sh is done"
>>>>>>> b6bbac47c031769eb3fad83729b93e8324e3dfec
