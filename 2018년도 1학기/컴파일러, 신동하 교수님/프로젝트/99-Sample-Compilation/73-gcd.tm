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
7: ldc pc, 40
8: halt
// ====================
// gcd()
// ====================
9: lda sp, -1(sp)
10: ld 0, -3(fp)
11: ldc 1, 0
12: eq 2, 0, 1
13: jle 2, 3(pc)
14: ld 0, -2(fp)
15: st 0, -4(fp)
16: ldc pc, 35
17: lda sp, -2(sp)
18: ld 0, -3(fp)
19: push 0
20: ld 0, -2(fp)
21: ld 1, -2(fp)
22: ld 2, -3(fp)
23: div 3, 1, 2
24: ld 1, -3(fp)
25: mul 2, 3, 1
26: sub 1, 0, 2
27: push 1
28: st fp, -5(fp)
29: lda fp, -5(fp)
30: lda 0, 2(pc)
31: st 0, -1(fp)
32: ldc pc, 9
33: lda 0, 0(27)
34: st 0, -4(fp)
35: ld 0, -4(fp)
36: lda 27, 0(0)
37: lda sp, 0(fp)
38: ld fp, 0(fp)
39: ld pc, -1(sp)
// ====================
// main()
// ====================
40: lda sp, -3(sp)
41: in 0
42: st 0, -2(fp)
43: in 0
44: st 0, -3(fp)
45: lda sp, -2(sp)
46: ld 0, -2(fp)
47: push 0
48: ld 0, -3(fp)
49: push 0
50: st fp, -5(fp)
51: lda fp, -5(fp)
52: lda 0, 2(pc)
53: st 0, -1(fp)
54: ldc pc, 9
55: lda 0, 0(27)
56: st 0, -4(fp)
57: ld 0, -4(fp)
58: out 0
59: ldc 27, 0
60: lda sp, 0(fp)
61: ld fp, 0(fp)
62: ld pc, -1(sp)
// ====================
