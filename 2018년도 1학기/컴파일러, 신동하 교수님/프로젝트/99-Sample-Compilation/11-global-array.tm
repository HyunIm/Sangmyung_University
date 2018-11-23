// ====================
// c startup
// ====================
0: ld gp, 0(0)
1: st 0, 0(0)
2: lda fp, -11(gp)
3: lda sp, -11(gp)
4: push fp
5: lda 0, 2(pc)
6: push 0
7: ldc pc, 9
8: halt
// ====================
// main()
// ====================
9: lda sp, -0(sp)
10: ldc 0, 0
11: st 0, -0(gp)
12: ldc 0, 4
13: ldc 1, 1
14: add 2, gp, 0
15: st 1, -10(2)
16: ld 0, -0(gp)
17: out 0
18: ldc 0, 4
19: add 1, gp, 0
20: ld 2, -10(1)
21: out 2
22: ldc 27, 0
23: lda sp, 0(fp)
24: ld fp, 0(fp)
25: ld pc, -1(sp)
// ====================
