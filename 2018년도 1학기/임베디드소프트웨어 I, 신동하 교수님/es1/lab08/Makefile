# ======================================================================
# File: Makefile
# ======================================================================

DIR = lab08-ucos-tasks
FILES = Makefile link.lds start.S tasks.c tasks-order.c tasks-statistic.c
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

all:	tasks.elf tasks.bin tasks.dis tasks-order.elf tasks-order.bin tasks-order.dis tasks-statistic.elf tasks-statistic.bin tasks-statistic.dis

# ======================================================================

tasks.elf:	$(LINKSCRIPT) start.o tasks.o $(UCOS_OBJS) $(UCOS_PORT_OBJS)
	$(LD) -T $(LINKSCRIPT) start.o tasks.o $(UCOS_OBJS) $(UCOS_PORT_OBJS) $(LIBRARIES) $(LDFLAGS) -o tasks.elf

tasks.bin:	tasks.elf
	$(OBJCOPY) -O binary tasks.elf tasks.bin

tasks.dis:	tasks.elf
	$(OBJDUMP) -DSx tasks.elf > tasks.dis

# ======================================================================

tasks-order.elf:	$(LINKSCRIPT) start.o tasks-order.o $(UCOS_OBJS) $(UCOS_PORT_OBJS)
	$(LD) -T $(LINKSCRIPT) start.o tasks-order.o $(UCOS_OBJS) $(UCOS_PORT_OBJS) $(LIBRARIES) $(LDFLAGS) -o tasks-order.elf

tasks-order.bin:	tasks-order.elf
	$(OBJCOPY) -O binary tasks-order.elf tasks-order.bin

tasks-order.dis:	tasks-order.elf
	$(OBJDUMP) -DSx tasks-order.elf > tasks-order.dis

# ======================================================================

tasks-statistic.elf:	$(LINKSCRIPT) start.o tasks-statistic.o $(UCOS_OBJS) $(UCOS_PORT_OBJS)
	$(LD) -T $(LINKSCRIPT) start.o tasks-statistic.o $(UCOS_OBJS) $(UCOS_PORT_OBJS) $(LIBRARIES) $(LDFLAGS) -o tasks-statistic.elf

tasks-statistic.bin:	tasks-statistic.elf
	$(OBJCOPY) -O binary tasks-statistic.elf tasks-statistic.bin

tasks-statistic.dis:	tasks-statistic.elf
	$(OBJDUMP) -DSx tasks-statistic.elf > tasks-statistic.dis

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
