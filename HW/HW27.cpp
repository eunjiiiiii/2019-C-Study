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
			printf("*���� �ް��� �� : %d\n", eggN);
		}
		else if (eggW < 150)
		{
			printf("*���߸��� ������ �峭ġ�� ���ÿ�~^^\n");
		}
		else
		{
			printf("*Ÿ���� ������ �峭ġ�� ���ÿ�~^^\n");
		}

	}
	printf("\n*** �ް� ������ �������ϴ�.");


	return 0;
}

int input()
{
	int eggW, res;
	while (1)
	{
		printf("#����� ���Ը� �Է��ϼ���(���� : g) : ");
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