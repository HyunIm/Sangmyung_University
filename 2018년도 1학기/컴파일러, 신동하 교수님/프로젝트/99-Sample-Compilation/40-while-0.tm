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
9: lda sp, -1(sp)
10: ldc 0, 0
11: st 0, -2(fp)
12: ld 0, -2(fp)
13: ldc 1, 10
14: lt 2, 0, 1
15: jle 2, 7(pc)
16: ld 0, -2(fp)
17: out 0
18: ld 0, -2(fp)
19: ldc 1, 1
20: add 2, 0, 1
21: st 2, -2(fp)
22: ldc pc, 12
23: ldc 27, 0
24: lda sp, 0(fp)
25: ld fp, 0(fp)
26: ld pc, -1(sp)
// ====================
