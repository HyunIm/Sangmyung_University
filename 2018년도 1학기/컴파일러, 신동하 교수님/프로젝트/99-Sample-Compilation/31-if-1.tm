// ====================
// c startup
// ====================
0: ld gp, 0(0)
1: st 0, 0(0)
2: lda fp, -0(gp)
3: lda sp, -0(gp)
4: push fp
5: lda 0, 2(pc)
6: push 0
7: ldc pc, 9
8: halt
// ====================
// main()
// ====================
9: lda sp, -3(sp)
10: ldc 0, 10
11: st 0, -2(fp)
12: ldc 0, 999
13: st 0, -3(fp)
14: ldc 0, 30
15: st 0, -4(fp)
16: ld 0, -2(fp)
17: ld 1, -3(fp)
18: lt 2, 0, 1
19: jle 2, 10(pc)
20: ld 0, -3(fp)
21: ld 1, -4(fp)
22: lt 2, 0, 1
23: jle 2, 3(pc)
24: ld 0, -4(fp)
25: out 0
26: ldc pc, 29
27: ld 0, -3(fp)
28: out 0
29: ldc pc, 39
30: ld 0, -2(fp)
31: ld 1, -4(fp)
32: lt 2, 0, 1
33: jle 2, 3(pc)
34: ld 0, -4(fp)
35: out 0
36: ldc pc, 39
37: ld 0, -2(fp)
38: out 0
39: ldc 27, 0
40: lda sp, 0(fp)
41: ld fp, 0(fp)
42: ld pc, -1(sp)
// ====================
