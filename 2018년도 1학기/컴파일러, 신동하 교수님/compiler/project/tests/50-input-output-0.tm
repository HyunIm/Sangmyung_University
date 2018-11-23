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
9: lda sp, -11(sp)
10: in 0
11: st 0, -2(fp)
12: ld 0, -2(fp)
13: out 0
14: ldc 0, 8
15: add 1, fp, 0
16: in 2
17: st 2, -12(1)
18: ldc 1, 8
19: add 2, fp, 1
20: ld 3, -12(2)
21: out 3
22: ldc 27, 0
23: lda sp, 0(fp)
24: ld fp, 0(fp)
25: ld pc, -1(sp)
// ====================
