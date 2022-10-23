#pragma warning(disable : 4996)
#include <stdio.h>

int input();
void myflush();

int main()
{
	int eggW;
	int eggN = 0;

	while (eggN < 10)
	{
		eggW = 0;
		eggW = input();
		if (150 <= eggW && eggW <= 500)
		{
			eggN++;
			printf("*현재 달걀의 수 : %d\n", eggN);
		}
		else if (eggW < 150)
		{
			printf("*메추리알 가지고 장난치지 마시오~^^\n");
		}
		else
		{
			printf("*타조알 가지고 장난치지 마시오~^^\n");
		}

	}
	printf("\n*** 달걀 포장이 끝났습니다.");


	return 0;
}

int input()
{
	int eggW, res;
	while (1)
	{
		printf("#계란의 무게를 입력하세요(단위 : g) : ");
		res=scanf("%d", &eggW);
		myflush();
		if (res == 1)
		{
			break;
		}
	}
	return eggW;
}

void myflush()
{
	while (getchar() != '\n');
	{
		;
	}
}