#pragma warning (disable : 4996)
#include <stdio.h>

int input();
int glossPay(int time);
int taxes(int gPay);
void output(int gPay, int tax);

int main()
{
	int time, gPay, tax;

	time = input(); //시간입력받음

	gPay = glossPay(time);

	tax = taxes(gPay);

	output(gPay, tax);

	return 0;
}

int input() //입력함수
{
	int time;
	printf("1주일간의 근무시간을 입력하시오 : ");
	scanf("%d", &time);

	return time;
}

int glossPay(int time) //총수입 계산함수
{
	int gpay;

	if (time > 40)
		gpay = 3000 * 40 + (int)((time - 40) * (3000 * 1.5));
	else
		gpay = 3000 * time;

	
	return gpay;
}

int taxes(int gPay)
{
	int tax;

	if (gPay > 100000)
		tax = (int)(100000 * 0.15) + (int)((gPay - 100000) * 0.25);
	else
		tax = (int)(gPay * 0.15);
	
	return tax;
}

void output(int gPay, int tax)
{
	printf("#총수입 : %d원\n", gPay);
	printf("#세  금 : %d원\n", tax);
	printf("#실수입 : %d원\n", gPay - tax);
}