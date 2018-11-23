# ======================================================================
# File: Makefile
# ======================================================================

DIR = lab04-uart
FILES = README.txt Makefile link.lds start.S uart.c uart.h print.c uart-test1.c uart-test2.c uart-test3.c

# ======================================================================

CC = arm-eabi-gcc
AS = arm-eabi-as
LD = arm-eabi-ld
OBJCOPY = arm-eabi-objcopy
OBJDUMP = arm-eabi-objdump

# ======================================================================

CFLAGS = -g -Wall -marm -mcpu=cortex-a8 -mfpu=neon -mfloat-abi=softfp -mabi=aapcs-linux -I.
ASFLAGS = -g -mcpu=cortex-a8 -mfpu=neon
LDFLAGS = -L $(shell dirname `$(CC) -print-libgcc-file-name`)
LIBRARIES = -lgcc
LINKSCRIPT = link.lds

# ======================================================================

all:	uart-test1.elf uart-test1.bin uart-test1.dis uart-test2.elf uart-test2.bin uart-test2.dis uart-test3.elf uart-test3.bin uart-test3.dis

# ======================================================================

uart-test1.elf:	$(LINKSCRIPT) start.o uart-test1.o uart.o uart.h print.o
	$(LD) -T $(LINKSCRIPT) start.o uart-test1.o uart.o print.o $(LIBRARIES) $(LDFLAGS) -o uart-test1.elf

uart-test1.bin:	uart-test1.elf
	$(OBJCOPY) -O binary uart-test1.elf uart-test1.bin

uart-test1.dis:	uart-test1.elf
	$(OBJDUMP) -DSx uart-test1.elf > uart-test1.dis

# ======================================================================

uart-test2.elf:	$(LINKSCRIPT) start.o uart-test2.o uart.o uart.h print.o
	$(LD) -T $(LINKSCRIPT) start.o uart-test2.o uart.o print.o $(LIBRARIES) $(LDFLAGS) -o uart-test2.elf

uart-test2.bin:	uart-test2.elf
	$(OBJCOPY) -O binary uart-test2.elf uart-test2.bin

uart-test2.dis:	uart-test2.elf
	$(OBJDUMP) -DSx uart-test2.elf > uart-test2.dis

# ======================================================================

uart-test3.elf:	$(LINKSCRIPT) start.o uart-test3.o uart.o uart.h print.o
	$(LD) -T $(LINKSCRIPT) start.o uart-test3.o uart.o print.o $(LIBRARIES) $(LDFLAGS) -o uart-test3.elf

uart-test3.bin:	uart-test3.elf
	$(OBJCOPY) -O binary uart-test3.elf uart-test3.bin

uart-test3.dis:	uart-test3.elf
	$(OBJDUMP) -DSx uart-test3.elf > uart-test3.dis

# ======================================================================

indent:
	indent -i2 -kr *.c *.h
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
