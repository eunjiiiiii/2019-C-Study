#pragma warning (disable : 4996)
#include <stdio.h>
#define stdfee 660


double input();
void output(double pay);


int main()
{
	double kw;
	double total, pay;

	kw = input();

	total = stdfee + kw * 88.5;

	pay = total + total * 0.09;

	output(pay);

	return 0;
}

double input()
{
	double kw;
	printf("���� ��뷮�� �Է��ϼ���(kw) : ");
	scanf("%lf", &kw);

	return kw;
}

void output(double pay)
{
	printf("���� ������� %lf �� �Դϴ�.", pay);
	return;
}