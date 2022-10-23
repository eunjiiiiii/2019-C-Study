#pragma warning (disable : 4996)
#include <stdio.h>

int input();
int glossPay(int time);
int taxes(int gPay);
void output(int gPay, int tax);

int main()
{
	int time, gPay, tax;

	time = input(); //�ð��Է¹���

	gPay = glossPay(time);

	tax = taxes(gPay);

	output(gPay, tax);

	return 0;
}

int input() //�Է��Լ�
{
	int time;
	printf("1���ϰ��� �ٹ��ð��� �Է��Ͻÿ� : ");
	scanf("%d", &time);

	return time;
}

int glossPay(int time) //�Ѽ��� ����Լ�
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
	printf("#�Ѽ��� : %d��\n", gPay);
	printf("#��  �� : %d��\n", tax);
	printf("#�Ǽ��� : %d��\n", gPay - tax);
}