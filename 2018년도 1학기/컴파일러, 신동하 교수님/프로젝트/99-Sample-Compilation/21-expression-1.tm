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
12: gt 2, 0, 1
13: st 2, -0(gp)
14: ld 0, -0(gp)
15: out 0
16: ldc 0, 1
17: ldc 1, 2
18: ge 2, 0, 1
19: st 2, -0(gp)
20: ld 0, -0(gp)
21: out 0
22: ldc 0, 1
23: ldc 1, 2
24: lt 2, 0, 1
25: st 2, -0(gp)
26: ld 0, -0(gp)
27: out 0
28: ldc 0, 2
29: ldc 1, 2
30: le 2, 0, 1
31: st 2, -0(gp)
32: ld 0, -0(gp)
33: out 0
34: ldc 0, 1
35: ldc 1, 2
36: eq 2, 0, 1
37: st 2, -0(gp)
38: ld 0, -0(gp)
39: out 0
40: ldc 0, 1
41: ldc 1, 2
42: ne 2, 0, 1
43: st 2, -0(gp)
44: ld 0, -0(gp)
45: out 0
46: ldc 27, 0
47: lda sp, 0(fp)
48: ld fp, 0(fp)
49: ld pc, -1(sp)
// ====================
