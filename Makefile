PRG            = program
#MCU_TARGET     = atmega16
#MCU_TARGET     = atmega8
#MCU_TARGET     = atmega48
#MCU_TARGET     = atmega88
#MCU_TARGET     = atmega168
MCU_TARGET     = attiny2313
OPTIMIZE       = -Os

DEFS           =
LIBS           = ./src/main.c

# You should not have to change anything below here.

CC             = avr-gcc

# Override is only needed by avr-lib build system.

override CFLAGS        = -g -Wall $(OPTIMIZE) -mmcu=$(MCU_TARGET) $(DEFS)
override LDFLAGS       = #-Wl,-Map,bin/$(PRG).map
all: $(PRG).elf

$(PRG).elf:
	$(CC) $(CFLAGS) $(LDFLAGS) -o bin/$@ $(LIBS)
	avr-size bin/$@
clean:
	rm -rf ./bin/$(PRG).elf
