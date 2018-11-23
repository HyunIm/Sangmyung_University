// ======================================================================
// File: handlers.h
// ======================================================================

#define IO_READ(addr)		(*(volatile unsigned int *)(addr))
#define IO_WRITE(addr, val)	(*(volatile unsigned int *)(addr) = (val))
#define IO_RCW(addr, mask, val)	IO_WRITE(addr, (IO_READ(addr) & ~(mask)) | ((val) & (mask)))

// ======================================================================
// Clock module wakeup Registers.

#define	CM_WKUP_BASE		0x44e00400
#define	TIMER1_CLKCTRL		0xc4

// ======================================================================
// Clock module PLL registers.

#define	CM_DPLL_BASE		0x44e00500
#define	CLKSEL_TIMER1MS_CLK	0x28

// ======================================================================
// Dual Module Timer 1 Registers.

#define DMTIMER1_BASE		0x44e31000
#define	TISR			0x18
#define	TIER			0x1c
#define TCLR			0x24
#define TCRR			0x28
#define TLDR			0x2c
#define	TPIR			0x48
#define	TNIR			0x4c

// ======================================================================
// Interrupt controller registers.

#define INTCPS_BASE		0x48200000
#define INTC_CONTROL		0x48
#define INTC_MIR0		0x84
#define INTC_MIR1		0xa4
#define INTC_MIR2		0xc4
#define INTC_MIR3		0xe4

// ======================================================================
