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
9: lda sp, -2(sp)
10: ldc 0, 1
11: st 0, -2(fp)
12: ldc 0, 0
13: st 0, -3(fp)
14: ld 0, -2(fp)
15: ldc 1, 10
16: le 2, 0, 1
17: jle 2, 9(pc)
18: ld 0, -3(fp)
19: ld 1, -2(fp)
20: add 2, 0, 1
21: st 2, -3(fp)
22: ld 0, -2(fp)
23: ldc 1, 1
24: add 2, 0, 1
25: st 2, -2(fp)
26: ldc pc, 14
27: ld 0, -3(fp)
28: out 0
29: ldc 27, 0
30: lda sp, 0(fp)
31: ld fp, 0(fp)
32: ld pc, -1(sp)
// ====================
