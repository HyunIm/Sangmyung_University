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
10: ldc 0, 0
11: st 0, -2(fp)
12: ldc 0, 1
13: st 0, -3(fp)
14: ld 0, -2(fp)
15: out 0
16: ld 0, -3(fp)
17: out 0
18: ldc 27, 0
19: lda sp, 0(fp)
20: ld fp, 0(fp)
21: ld pc, -1(sp)
// ====================
