#pragma warning (disable: 4996)
#include <stdio.h>

int inputN();
void myflush();


int main()
{

	int n, i;
	n = inputN();

	long long fibo[30], sum;
	fibo[0] = 1;
	fibo[1] = 1;
	sum = fibo[0] + fibo[1];

	printf("%lld + %lld + ", fibo[0], fibo[1]);

	for (i = 0; i <= (n - 3); i++)
	{
		fibo[i + 2] = fibo[i] + fibo[i + 1];
		printf("%lld + ", fibo[i+2]);
		sum += fibo[i + 2];
	}
	printf("%\b\b=%lld\n",  sum);

	return 0;
}

int inputN()
{
	int n, res;
	while (1)
	{
		printf("피보나치 수열의 항수를 입력하시오 : ");
		res = scanf("%d", &n);
		myflush();
		if (res == 1 && n<=30 && n>=1) {
			break;
		}
	}
	return n;
}

void myflush()
{
	while (getchar() != '\n')
	{
		;
	}
}