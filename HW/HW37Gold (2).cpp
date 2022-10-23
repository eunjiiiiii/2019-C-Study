#pragma warning (disable: 4996)
#include <stdio.h>

int input();
void myflush();

int main()
{
	int i, workday, range, rest, gold;
	int a[200];
	//range = i * (i + 1) / 2;

	
	workday = input();

	for (i = 0; i < 200; i++)
	{
		a[i] = i * (i + 1) / 2; //수열의 각 방에 수열 저장
	}
	for(i=0; i<200; i++)
	{

		if (a[i] <= workday && workday <= a[i + 1])
		{
			rest = workday - a[i];
			gold = (i * (i + 1) * (2 * i + 1) / 6) + (i + 1) * rest;
		}
	}

	printf("  근무일 : %d일 / 총 금화 수 : %d 개", workday, gold);

	return 0;
}

int input()
{
	int workday, res;
	while (1)
	{
		printf("* 기사의 근무일수를 입력하시오 : ");
		res = scanf("%d", &workday);
		myflush();
		if (res == 1)
		{
			break;
		}
		printf("* 잘못 입력하셨습니다. 정수를 입력해주세요");
	}
	
	return workday;
}

void myflush()
{
	while (getchar() != '\n')
	{
		;
	}
}