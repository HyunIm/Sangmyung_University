# ======================================================================
# File: Makefile
# ======================================================================

DIR = lab05-exceptions
FILES = README.txt Makefile link.lds start.S exceptions.c handlers.c

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

all:	exceptions.elf exceptions.bin exceptions.dis

# ======================================================================

exceptions.elf:	$(LINKSCRIPT) start.o exceptions.o handlers.o
	$(LD) -T $(LINKSCRIPT) start.o exceptions.o handlers.o $(LIBRARIES) $(LDFLAGS) -o exceptions.elf

exceptions.bin:	exceptions.elf
	$(OBJCOPY) -O binary exceptions.elf exceptions.bin

exceptions.dis:	exceptions.elf
	$(OBJDUMP) -DSx exceptions.elf > exceptions.dis

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
