#pragma warning(disable : 4996)
#include <stdio.h>

int input();

int main()
{
	int n, d, i, len;
	n = input();

	len = sizeof(int) * 8; //32bit
	
	printf("%d(10) = ", n);

	for (i = 0; i < len; i++)
	{
		printf("%d", (n >> ((len -1)-i)) & 1); //�о��� ���� ���� ���ҰŴϱ� 1�� ��
	}
	printf("(2)\n");

	return 0;
}

int input()
{
	int n, res;
	while(1)
	{
		printf("*10���� ������ �Է��Ͻÿ� : ");
		res=scanf("%d", &n);
		if (res == 1)
		{
			break;
		}
		printf("�ٽ� �Է����ּ���.");
	}
	
	return n;
}
	