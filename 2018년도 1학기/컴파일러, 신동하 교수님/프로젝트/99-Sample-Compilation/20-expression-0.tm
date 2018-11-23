// ====================
// c startup
// ====================
0: ld gp, 0(0)
1: st 0, 0(0)
2: lda fp, -1(gp)
3: lda sp, -1(gp)
4: push fp
5: lda 0, 2(pc)
6: push 0
7: ldc pc, 9
8: halt
// ====================
// main()
// ====================
9: lda sp, -0(sp)
10: ldc 0, 1
11: ldc 1, 2
12: add 2, 0, 1
13: ldc 0, 3
14: sub 1, 2, 0
15: st 1, -0(gp)
16: ld 0, -0(gp)
17: out 0
18: ldc 0, 1
19: ldc 1, 2
20: ldc 2, 3
21: mul 3, 1, 2
22: sub 1, 0, 3
23: st 1, -0(gp)
24: ld 0, -0(gp)
25: out 0
26: ldc 0, 1
27: ldc 1, 2
28: sub 2, 0, 1
29: ldc 0, 3
30: mul 1, 2, 0
31: st 1, -0(gp)
32: ld 0, -0(gp)
33: out 0
34: ldc 0, 1
35: ldc 1, 2
36: ldc 2, 3
37: div 3, 1, 2
38: add 1, 0, 3
39: st 1, -0(gp)
40: ld 0, -0(gp)
41: out 0
42: ldc 0, 4
43: ldc 1, 2
44: add 2, 0, 1
45: ldc 0, 3
46: div 1, 2, 0
47: st 1, -0(gp)
48: ld 0, -0(gp)
49: out 0
50: ldc 27, 0
51: lda sp, 0(fp)
52: ld fp, 0(fp)
53: ld pc, -1(sp)
// ====================
