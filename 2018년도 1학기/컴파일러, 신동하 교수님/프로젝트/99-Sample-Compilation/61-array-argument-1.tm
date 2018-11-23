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
10: ldc 0, 5
11: ldc 1, 555
12: ld 2, -2(fp)
13: add 3, 2, 0
14: st 1, 0(3)
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
28: ldc 0, 5
29: add 1, gp, 0
30: ld 2, -9(1)
31: out 2
32: lda sp, -2(sp)
33: lda 0, -9(gp)
34: push 0
35: st fp, -2(fp)
36: lda fp, -2(fp)
37: lda 0, 2(pc)
38: st 0, -1(fp)
39: ldc pc, 9
40: lda 0, 0(27)
41: ldc 0, 4
42: add 1, gp, 0
43: ld 2, -9(1)
44: out 2
45: ldc 0, 5
46: add 1, gp, 0
47: ld 2, -9(1)
48: out 2
49: ldc 27, 0
50: lda sp, 0(fp)
51: ld fp, 0(fp)
52: ld pc, -1(sp)
// ====================
