// ====================
// c startup
// ====================
0: ld gp, 0(0)
1: st 0, 0(0)
2: lda fp, -5(gp)
3: lda sp, -5(gp)
4: push fp
5: lda 0, 2(pc)
6: push 0
7: ldc pc, 100
8: halt
// ====================
// minloc()
// ====================
9: lda sp, -3(sp)
10: ld 0, -3(fp)
11: st 0, -7(fp)
12: ld 0, -3(fp)
13: ld 2, -2(fp)
14: add 1, 2, 0
15: ld 2, 0(1)
16: st 2, -6(fp)
17: ld 0, -3(fp)
18: ldc 1, 1
19: add 2, 0, 1
20: st 2, -5(fp)
21: ld 0, -5(fp)
22: ld 1, -4(fp)
23: lt 2, 0, 1
24: jle 2, 20(pc)
25: ld 0, -5(fp)
26: ld 2, -2(fp)
27: add 1, 2, 0
28: ld 2, 0(1)
29: ld 0, -6(fp)
30: lt 1, 2, 0
31: jle 1, 8(pc)
32: ld 0, -5(fp)
33: ld 2, -2(fp)
34: add 1, 2, 0
35: ld 2, 0(1)
36: st 2, -6(fp)
37: ld 0, -5(fp)
38: st 0, -7(fp)
39: ldc pc, 40
40: ld 0, -5(fp)
41: ldc 1, 1
42: add 2, 0, 1
43: st 2, -5(fp)
44: ldc pc, 21
45: ld 0, -7(fp)
46: lda 27, 0(0)
47: lda sp, 0(fp)
48: ld fp, 0(fp)
49: ld pc, -1(sp)
// ====================
// sort()
// ====================
50: lda sp, -3(sp)
51: ld 0, -3(fp)
52: st 0, -5(fp)
53: ld 0, -5(fp)
54: ld 1, -4(fp)
55: ldc 2, 1
56: sub 3, 1, 2
57: lt 1, 0, 3
58: jle 1, 37(pc)
59: lda sp, -2(sp)
60: ld 0, -2(fp)
61: push 0
62: ld 0, -5(fp)
63: push 0
64: ld 0, -4(fp)
65: push 0
66: st fp, -8(fp)
67: lda fp, -8(fp)
68: lda 0, 2(pc)
69: st 0, -1(fp)
70: ldc pc, 9
71: lda 0, 0(27)
72: st 0, -6(fp)
73: ld 0, -6(fp)
74: ld 2, -2(fp)
75: add 1, 2, 0
76: ld 2, 0(1)
77: st 2, -7(fp)
78: ld 0, -6(fp)
79: ld 1, -5(fp)
80: ld 3, -2(fp)
81: add 2, 3, 1
82: ld 3, 0(2)
83: ld 1, -2(fp)
84: add 2, 1, 0
85: st 3, 0(2)
86: ld 0, -5(fp)
87: ld 1, -7(fp)
88: ld 2, -2(fp)
89: add 3, 2, 0
90: st 1, 0(3)
91: ld 0, -5(fp)
92: ldc 1, 1
93: add 2, 0, 1
94: st 2, -5(fp)
95: ldc pc, 53
96: ldc 27, 0
97: lda sp, 0(fp)
98: ld fp, 0(fp)
99: ld pc, -1(sp)
// ====================
// main()
// ====================
100: lda sp, -1(sp)
101: ldc 0, 0
102: st 0, -2(fp)
103: ld 0, -2(fp)
104: ldc 1, 5
105: lt 2, 0, 1
106: jle 2, 9(pc)
107: ld 0, -2(fp)
108: in 1
109: add 2, gp, 0
110: st 1, -4(2)
111: ld 0, -2(fp)
112: ldc 1, 1
113: add 2, 0, 1
114: st 2, -2(fp)
115: ldc pc, 103
116: lda sp, -2(sp)
117: lda 0, -4(gp)
118: push 0
119: ldc 0, 0
120: push 0
121: ldc 0, 5
122: push 0
123: st fp, -3(fp)
124: lda fp, -3(fp)
125: lda 0, 2(pc)
126: st 0, -1(fp)
127: ldc pc, 50
128: lda 0, 0(27)
129: ldc 0, 0
130: st 0, -2(fp)
131: ld 0, -2(fp)
132: ldc 1, 5
133: lt 2, 0, 1
134: jle 2, 9(pc)
135: ld 0, -2(fp)
136: add 1, gp, 0
137: ld 2, -4(1)
138: out 2
139: ld 0, -2(fp)
140: ldc 1, 1
141: add 2, 0, 1
142: st 2, -2(fp)
143: ldc pc, 131
144: ldc 27, 0
145: lda sp, 0(fp)
146: ld fp, 0(fp)
147: ld pc, -1(sp)
// ====================
