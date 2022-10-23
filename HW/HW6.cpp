#pragma warning (disable : 4996)
#include <stdio.h>

int inputf();
void output(double c);

int main()
{
	int f;
	double c;

	f = inputf();
	c = 5.0 / 9 * (f - 32);

	output(c);

	return 0;
}


int inputf()
{
	int f;
	printf("화씨 온도를 입력하세요 : ");
	scanf("%d", &f);
	
	return f;
}

void output(double c)
{
	printf("섭씨 온도는 %.1lf도 입니다.", c);

	return;
}