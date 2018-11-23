# ======================================================================
# File: Makefile
# ======================================================================

DIR = lab03-sections
FILES = README.txt Makefile link.lds start.S args.c text.c data.c stack.c

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

all:	args.elf args.bin args.dis text.elf text.bin text.dis data.elf data.bin data.dis stack.elf stack.bin stack.dis

# ======================================================================

args.elf:	$(LINKSCRIPT) start.o args.o
	$(LD) -T $(LINKSCRIPT) start.o args.o $(LIBRARIES) $(LDFLAGS) -o args.elf

args.bin:	args.elf
	$(OBJCOPY) -O binary args.elf args.bin

args.dis:	args.elf
	$(OBJDUMP) -DSx args.elf > args.dis

# ======================================================================

text.elf:	$(LINKSCRIPT) start.o text.o
	$(LD) -T $(LINKSCRIPT) start.o text.o $(LIBRARIES) $(LDFLAGS) -o text.elf

text.bin:	text.elf
	$(OBJCOPY) -O binary text.elf text.bin

text.dis:	text.elf
	$(OBJDUMP) -DSx text.elf > text.dis

# ======================================================================

data.elf:	$(LINKSCRIPT) start.o data.o
	$(LD) -T $(LINKSCRIPT) start.o data.o $(LIBRARIES) $(LDFLAGS) -o data.elf

data.bin:	data.elf
	$(OBJCOPY) -O binary data.elf data.bin

data.dis:	data.elf
	$(OBJDUMP) -DSx data.elf > data.dis

# ======================================================================

stack.elf:	$(LINKSCRIPT) start.o stack.o
	$(LD) -T $(LINKSCRIPT) start.o stack.o $(LIBRARIES) $(LDFLAGS) -o stack.elf

stack.bin:	stack.elf
	$(OBJCOPY) -O binary stack.elf stack.bin

stack.dis:	stack.elf
	$(OBJDUMP) -DSx stack.elf > stack.dis

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
