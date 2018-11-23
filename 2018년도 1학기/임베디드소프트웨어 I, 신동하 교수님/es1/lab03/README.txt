# ======================================================================
# File: README.txt
# ======================================================================

lab objectives
==============

- The role of "start.S".
- Argument passing from u-boot to main(int argc, char *argv[]).
- Sections: text, rodata, data, bss.
- The role of linkscript.
- Memory map (512M).

Memory map
==========

0xA0000000
           +----------+
           |          |
           |          |
           |//////////| lab bss
           |//////////| lab data
           |//////////| lab rodata
0x82000000 |//////////| lab text
           +----------+
           |/////|////| lab stack
           |     v    |
           |          |
           |..........| u-boot bss
           |..........| u-boot data
           |..........| u-boot rodata
0x80E80000 |..........| u-boot text
           +----------+
           |.... |....| u-boot stack
           |     v    |
0x80000000 |          |
           +----------+

# ======================================================================
