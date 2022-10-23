#pragma warning(disable : 4996)
#include <stdio.h>

int input();

int main()
{
	int n, i=0, j=0;
	n = input();

	while (i < (n / 5))
	{
		j = 0;
		while (j < 5)
		{
			printf("*");
			j++;
		}
		printf("\n");
		i++;
	}

	if (i == (n / 5))
	{
		j = 0;
		while (j < (n % 5))
		{
			printf("*");
			j++;
		}		
	}

	return 0;
}

int input()
{
	int n;
	printf("# 정수값을 입력하세요 : ");
	scanf("%d", &n);

	return n;
}