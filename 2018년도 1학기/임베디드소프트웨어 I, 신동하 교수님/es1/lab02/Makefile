# ======================================================================
# File: Makefile
# ======================================================================

DIR = lab02-assembly
FILES = README.txt Makefile link.lds start.S multi.c multi-arm.S fact.c fact-arm.S

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

all:	multi.elf multi.bin multi.dis fact.elf fact.bin fact.dis

# ======================================================================

multi.elf:	$(LINKSCRIPT) start.o multi.o multi-arm.o
	$(LD) -T $(LINKSCRIPT) start.o multi.o multi-arm.o $(LIBRARIES) $(LDFLAGS) -o multi.elf

multi.bin:	multi.elf
	$(OBJCOPY) -O binary multi.elf multi.bin

multi.dis:	multi.elf
	$(OBJDUMP) -DSx multi.elf > multi.dis

# ======================================================================

fact.elf:	$(LINKSCRIPT) start.o fact.o fact-arm.o
	$(LD) -T $(LINKSCRIPT) start.o fact.o fact-arm.o $(LIBRARIES) $(LDFLAGS) -o fact.elf

fact.bin:	fact.elf
	$(OBJCOPY) -O binary fact.elf fact.bin

fact.dis:	fact.elf
	$(OBJDUMP) -DSx fact.elf > fact.dis

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
