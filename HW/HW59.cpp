#pragma warning(disable:4996)
#include<stdio.h>

void inputN(int *N, int* res);
void inputNumbers(int* num, int N, int* res2);
int differNum(int* num, int N);
void output(int N);
int checkStdin();

int main()
{
	int num[100] = { 0 };
	int N, res, res2, cnt, i, strange;
	
	while (1)
	{
		res2 = 0;
		inputN(&N, &res);
		if (checkStdin() > 0)
		{
			break;
		}
		if (res != 1 || N < 2 || N>1000)
		{
			break;
		}
		inputNumbers(num, N, &res2);
		if (checkStdin() > 0)
		{
			break;
		}
		if (res2!=N)
		{
			break;
		}
		//if (res2 != N)
		//{
		//	break;
		//}
		cnt=differNum(num, N);

		output(cnt);

	}
	return 0;
}

void inputN(int* N, int* res)
{
	int i;
	printf("* 입력할 숫자의 개수 : ");
	*res = scanf("%d", N);
}

void inputNumbers(int *num, int N, int* res2)
{
	int i;
	printf("* 숫자 입력 : ");
	for (i = 0; i < N; i++)
	{
		*res2+=scanf(" %d", &num[i]);
		if (num[i] < 1 || num[i]>10000)
		{
			*res2 += 1;
		}
	}
}

int differNum(int* num, int N)
{
	int i, j, cnt=N;

	for (i = 0; i < N; i++)
	{
		for (j = 1; j < N - i; j++)
		{
			if (num[i] == num[i + j] && num[i]>=1)
			{
				num[i + j] = 0;
				cnt--;
			}
		}
	}
	return cnt;
}

void output(int N)
{
	printf("   서로 다른 수의 개수 : %d\n\n", N);
}

int checkStdin()
{
	int strange=0;
	while (getchar() != '\n') {
		strange++;
	}
	return strange;
}