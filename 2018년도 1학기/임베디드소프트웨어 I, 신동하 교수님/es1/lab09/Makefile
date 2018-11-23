# ======================================================================
# File: Makefile
# ======================================================================

DIR = lab09-ucos-sync
FILES = Makefile link.lds start.S sync-delay.c sync-semaphore.c
UCOS_ROOT_DIR = /home/es1/uCOS-II-2.83

# ======================================================================

UCOS_SRC_DIR = $(UCOS_ROOT_DIR)/Source
UCOS_PORT_DIR = $(UCOS_ROOT_DIR)/Port-Beaglebone
UCOS_LIB_DIR = $(UCOS_ROOT_DIR)/uC-LIB

# ======================================================================

UCOS_OBJS = $(UCOS_SRC_DIR)/os_core.o $(UCOS_SRC_DIR)/os_flag.o $(UCOS_SRC_DIR)/os_mbox.o $(UCOS_SRC_DIR)/os_mem.o $(UCOS_SRC_DIR)/os_mutex.o $(UCOS_SRC_DIR)/os_q.o $(UCOS_SRC_DIR)/os_sem.o $(UCOS_SRC_DIR)/os_task.o $(UCOS_SRC_DIR)/os_time.o $(UCOS_SRC_DIR)/os_tmr.o
UCOS_PORT_OBJS = $(UCOS_PORT_DIR)/os_cpu_c.o $(UCOS_PORT_DIR)/os_dbg.o $(UCOS_PORT_DIR)/os_cpu_s.o $(UCOS_PORT_DIR)/os_timer.o

# ======================================================================

CC = arm-eabi-gcc
AS = arm-eabi-as
LD = arm-eabi-ld
OBJCOPY = arm-eabi-objcopy
OBJDUMP = arm-eabi-objdump

# ======================================================================

CFLAGS = -g -Wall -marm -mcpu=cortex-a8 -mfpu=neon -mfloat-abi=softfp -mabi=aapcs-linux -I. -I$(UCOS_SRC_DIR) -I$(UCOS_PORT_DIR) -I$(UCOS_LIB_DIR) -I../libuart
ASFLAGS = -g -mcpu=cortex-a8 -mfpu=neon
LDFLAGS = -L ../libuart -L $(shell dirname `$(CC) -print-libgcc-file-name`)
LIBRARIES = -luart -lgcc
LINKSCRIPT = link.lds

# ======================================================================

all:	sync-delay.elf sync-delay.bin sync-delay.dis sync-semaphore.elf sync-semaphore.bin sync-semaphore.dis

# ======================================================================

sync-delay.elf:	$(LINKSCRIPT) start.o sync-delay.o $(UCOS_OBJS) $(UCOS_PORT_OBJS)
	$(LD) -T $(LINKSCRIPT) start.o sync-delay.o $(UCOS_OBJS) $(UCOS_PORT_OBJS) $(LIBRARIES) $(LDFLAGS) -o sync-delay.elf

sync-delay.bin:	sync-delay.elf
	$(OBJCOPY) -O binary sync-delay.elf sync-delay.bin

sync-delay.dis:	sync-delay.elf
	$(OBJDUMP) -DSx sync-delay.elf > sync-delay.dis

# ======================================================================

sync-semaphore.elf:	$(LINKSCRIPT) start.o sync-semaphore.o $(UCOS_OBJS) $(UCOS_PORT_OBJS)
	$(LD) -T $(LINKSCRIPT) start.o sync-semaphore.o $(UCOS_OBJS) $(UCOS_PORT_OBJS) $(LIBRARIES) $(LDFLAGS) -o sync-semaphore.elf

sync-semaphore.bin:	sync-semaphore.elf
	$(OBJCOPY) -O binary sync-semaphore.elf sync-semaphore.bin

sync-semaphore.dis:	sync-semaphore.elf
	$(OBJDUMP) -DSx sync-semaphore.elf > sync-semaphore.dis

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
