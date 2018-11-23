int main(void) {
	assert(sizeof(unsigned char) == 1);

	unsigned char uc1 = 0xff;
	unsigned char uc2 = 0;

	/* ======== ~연산시 char로 강제 형 변환 ======== */
	if (~((char)uc1) == uc2) {
		printf("%08x == %08x\n", ~((char)uc1), uc2);
	}
	else {
		printf("%08x != %08x\n", ~uc1, uc2);
	}

	return 0;
}