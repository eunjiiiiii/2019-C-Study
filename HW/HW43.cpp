#pragma warning(disable:4996)
#include <stdio.h>
#include <math.h>

int input();
void myflush();
int primeNumber(int number);

int main()
{
	int number, i, primeRes, primeN = 0;

	number = input();

	printf("1~%d까지의 소수 값은 다음과 같습니다.\n", number);

	for (i = 2; i <= number; i++)
	{
		primeRes = primeNumber(i);
		if (primeRes == 1)
		{
			printf("%-5d", i);
			primeN++;
			if (primeN % 5 == 0)
			{
				printf("\n");
			}
		}

	}
	printf("\n");
	printf("1~%d까지의 총 소수는 %d개 입니다.\n", number, primeN);

	return 0;
}

int input()
{
	int n, res;
	while (1)
	{
		printf("*정수값 하나를 입력하시오 : ");
		res = scanf("%d", &n);
		myflush();
		if (res == 1)
		{
			break;
		}
	}
	return n;
}

void myflush()
{
	while (getchar() != '\n') {
		;
	}
}

int primeNumber(int number)
{
	int cmp, i, primeRes= 0;
	cmp = sqrt(number);
	for (i = 1; i <= cmp; i++)
	{
		if (number % i == 0)
		{
			primeRes++;
		}
	}
	if (primeRes == 1)
	{
		return 1;
	}
	else
		return 0;
}