#include <string.h>
#include <stdio.h>

void normal_function(const char* input)
{
	char buf[10];
	
	printf("Stack before input :\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n\n");
	// strcpy �Լ��� ���� input���� buf�� ����
	// strcpy �Լ��� NTBS ������ �� �ϱ� ������ ��� ����
	strcpy(buf, input);
	printf("%s\n", buf);
	printf("Stack after input :\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n\n");
}

// ��ŷ ������ Test �غ� �Լ�
// �ش� �Լ��� �ּ� ��(0x8048498)���� ret���� �����
void hacked_function(void)
{
	printf("I am hacked!\n");
}

int main(int argc, char* argv[])
{
	// normal_function�� hacked_function�� ���� �ּ� ���
	printf("The address of normal_function = %p\n", normal_function);
	printf("The address of hacked_function = %p\n", hacked_function);

	// ����� ���ڰ� 2���� �ƴ϶�� ������ ����
	if (argc != 2)
	{
		printf("Input one argument\n");
		return -1;
	}

	// 2��° ����� ���ڸ� normal_function �Ű������� ����
	normal_function(argv[1]);
	
	return 0;
}
