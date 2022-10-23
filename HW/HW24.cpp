#pragma warning (disable : 4996)
#include <stdio.h>

int input();
int escapeDay(int d);
void output(int d, int day);

int main()
{
	int d, day; //우물의 깊이
	d = input();

	day = escapeDay(d);

	output(d, day);

	return 0;
}

int input()
{
	int d;
	printf("*우물의 깊이를 입력하시오(cm단위) : ");
	scanf("%d", &d);

	return d;
}

int escapeDay(int d)
{
	int day = 1;
	if (d == 0)
	{
		day = 0;
	}
	else if (1<=d && d <= 50)
	{
		day = 1;
	}
	else 
	{
		int i = 1;
		while (d > 50)
		{
			d = d - 30;
			day++;
		}

	}
	return day;
	
}

void output(int d, int day)
{
	printf("%.2lf 미터 깊이의 우물을 탈출하기 위해서는 %d일이 걸립니다.", d * 0.01, day);
}
