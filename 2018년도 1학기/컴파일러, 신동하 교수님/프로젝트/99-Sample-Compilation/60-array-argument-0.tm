// ====================
// c startup
// ====================
0: ld gp, 0(0)
1: st 0, 0(0)
2: lda fp, -10(gp)
3: lda sp, -10(gp)
4: push fp
5: lda 0, 2(pc)
6: push 0
7: ldc pc, 19
8: halt
// ====================
// fun()
// ====================
9: lda sp, -0(sp)
10: ldc 0, 4
11: ld 2, -2(fp)
12: add 1, 2, 0
13: ld 2, 0(1)
14: out 2
15: ldc 27, 0
16: lda sp, 0(fp)
17: ld fp, 0(fp)
18: ld pc, -1(sp)
// ====================
// main()
// ====================
19: lda sp, -0(sp)
20: ldc 0, 4
21: ldc 1, 444
22: add 2, gp, 0
23: st 1, -9(2)
24: ldc 0, 4
25: add 1, gp, 0
26: ld 2, -9(1)
27: out 2
28: lda sp, -2(sp)
29: lda 0, -9(gp)
30: push 0
31: st fp, -2(fp)
32: lda fp, -2(fp)
33: lda 0, 2(pc)
34: st 0, -1(fp)
35: ldc pc, 9
36: lda 0, 0(27)
37: ldc 27, 0
38: lda sp, 0(fp)
39: ld fp, 0(fp)
40: ld pc, -1(sp)
// ====================
