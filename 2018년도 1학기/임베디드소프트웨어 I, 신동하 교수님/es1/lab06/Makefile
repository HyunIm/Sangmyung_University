# ======================================================================
# File: Makefile
# ======================================================================

DIR = lab06-swi
FILES = README.txt Makefile link.lds start.S swi.c handlers.c

# ======================================================================

CC = arm-eabi-gcc
AS = arm-eabi-as
LD = arm-eabi-ld
OBJCOPY = arm-eabi-objcopy
OBJDUMP = arm-eabi-objdump

# ======================================================================

CFLAGS = -g -Wall -marm -mcpu=cortex-a8 -mfpu=neon -mfloat-abi=softfp -mabi=aapcs-linux -I. -I../libuart
ASFLAGS = -g -mcpu=cortex-a8 -mfpu=neon
LDFLAGS = -L ../libuart -L $(shell dirname `$(CC) -print-libgcc-file-name`)
LIBRARIES = -luart -lgcc
LINKSCRIPT = link.lds

# ======================================================================

all:	swi.elf swi.bin swi.dis

# ======================================================================

swi.elf:	$(LINKSCRIPT) start.o swi.o handlers.o
	$(LD) -T $(LINKSCRIPT) start.o swi.o handlers.o $(LIBRARIES) $(LDFLAGS) -o swi.elf

swi.bin:	swi.elf
	$(OBJCOPY) -O binary swi.elf swi.bin

swi.dis:	swi.elf
	$(OBJDUMP) -DSx swi.elf > swi.dis

# ======================================================================

indent:
	indent -i2 -kr *.c
	@rm -f *~

# ======================================================================

pdf:	$(FILES)
	a2ps --medium=A4 --line-numbers=1 $(FILES) -o $(DIR).ps
	ps2pdf -sPAPERSIZE=a4 $(DIR).ps $(DIR).pdf
	@rm -f $(DIR).ps

# ======================================================================

clean:
	@rm -f *.o *.elf *.bin *.dis *.pdf *~

# ======================================================================
