PRG            = program
#MCU_TARGET     = atmega16
#MCU_TARGET     = atmega8
#MCU_TARGET     = atmega48
#MCU_TARGET     = atmega88
#MCU_TARGET     = atmega168
MCU_TARGET     = attiny2313
OPTIMIZE       = -Os

DEFS           =
LIBS           = ./src/main.cpp

# You should not have to change anything below here.

CC             = avr-gcc

# Override is only needed by avr-lib build system.

override CFLAGS        = -g -Wall $(OPTIMIZE) -mmcu=$(MCU_TARGET) $(DEFS)
#override LDFLAGS       = -Wl,-Map,$(PRG).map
all: $(PRG).elf

$(PRG).elf:
	$(CC) $(CFLAGS) -o bin/$@ $(LIBS)
	avr-size bin/$@
