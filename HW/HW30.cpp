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
		printf("%d", (n >> ((len -1)-i)) & 1); //밀었을 때의 수만 비교할거니까 1과 비교
	}
	printf("(2)\n");

	return 0;
}

int input()
{
	int n, res;
	while(1)
	{
		printf("*10진수 정수를 입력하시오 : ");
		res=scanf("%d", &n);
		if (res == 1)
		{
			break;
		}
		printf("다시 입력해주세요.");
	}
	
	return n;
}
	