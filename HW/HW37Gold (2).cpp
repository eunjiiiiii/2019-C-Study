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
		a[i] = i * (i + 1) / 2; //������ �� �濡 ���� ����
	}
	for(i=0; i<200; i++)
	{

		if (a[i] <= workday && workday <= a[i + 1])
		{
			rest = workday - a[i];
			gold = (i * (i + 1) * (2 * i + 1) / 6) + (i + 1) * rest;
		}
	}

	printf("  �ٹ��� : %d�� / �� ��ȭ �� : %d ��", workday, gold);

	return 0;
}

int input()
{
	int workday, res;
	while (1)
	{
		printf("* ����� �ٹ��ϼ��� �Է��Ͻÿ� : ");
		res = scanf("%d", &workday);
		myflush();
		if (res == 1)
		{
			break;
		}
		printf("* �߸� �Է��ϼ̽��ϴ�. ������ �Է����ּ���");
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