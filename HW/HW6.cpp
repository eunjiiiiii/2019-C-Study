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
	printf("ȭ�� �µ��� �Է��ϼ��� : ");
	scanf("%d", &f);
	
	return f;
}

void output(double c)
{
	printf("���� �µ��� %.1lf�� �Դϴ�.", c);

	return;
}