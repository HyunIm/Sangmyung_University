# ======================================================================
# File: README.txt
# ======================================================================

lab objectives
==============

- ARM exception vector and vector base register.
- ARM exceptions and modes: reset(supervisor), undefined
  instructions(undefined), software interrupt(supervisor), prefetch
  abort(abort), data abort(abort), irq(irq), fiq(fiq).
- Exception handlers.
- ARM current program status register and mode bits.

Memory map
==========

0xa0000000
           +----------+
           |          |
           |          |
           |//////////| lab bss
           |//////////| lab data
           |//////////| lab rodata
0x82000000 |//////////| lab text
           +----------+
           |/////|////| fiq stack
           |/////v////| irq stack
           |/////v////| abt stack
           |/////v////| und stack
           |/////v////| usr stack
           |/////v////| svc stack
           |          |
           |..........| u-boot bss
           |..........| u-boot data
           |..........| u-boot rodata
0x80e80000 |..........| u-boot text
           +----------+
           |.... |....| u-boot stack
           |     v    |
0x80000000 |          |
           +----------+

# ======================================================================
