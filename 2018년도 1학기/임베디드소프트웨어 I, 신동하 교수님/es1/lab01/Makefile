# ======================================================================
# File: Makefile
# ======================================================================

DIR = lab01-beaglebone
FILES = README.txt Makefile link.lds start.S beaglebone.c

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

all:	beaglebone.elf beaglebone.bin beaglebone.dis

# ======================================================================

beaglebone.elf:	$(LINKSCRIPT) start.o beaglebone.o
	$(LD) -T $(LINKSCRIPT) start.o beaglebone.o $(LIBRARIES) $(LDFLAGS) -o beaglebone.elf

beaglebone.bin:	beaglebone.elf
	$(OBJCOPY) -O binary beaglebone.elf beaglebone.bin

beaglebone.dis:	beaglebone.elf
	$(OBJDUMP) -DSx beaglebone.elf > beaglebone.dis

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
