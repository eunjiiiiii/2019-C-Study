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
	printf("전기 사용량을 입력하세요(kw) : ");
	scanf("%lf", &kw);

	return kw;
}

void output(double pay)
{
	printf("전기 사용요금은 %lf 원 입니다.", pay);
	return;
}