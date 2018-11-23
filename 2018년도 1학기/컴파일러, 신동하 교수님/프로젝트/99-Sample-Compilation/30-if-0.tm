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
10: ldc 0, 10
11: st 0, -2(fp)
12: ldc 0, 20
13: st 0, -3(fp)
14: ld 0, -2(fp)
15: ld 1, -3(fp)
16: lt 2, 0, 1
17: jle 2, 3(pc)
18: ld 0, -3(fp)
19: out 0
20: ldc pc, 23
21: ld 0, -2(fp)
22: out 0
23: ldc 27, 0
24: lda sp, 0(fp)
25: ld fp, 0(fp)
26: ld pc, -1(sp)
// ====================
