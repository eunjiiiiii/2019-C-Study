#pragma warning(disable : 4996)
#include <stdio.h>

int inputAge();
int inputN();
void print(int totMoney, int discMoney, int payMoney);

int main()
{
	int age, n, fee, discMoney, totMoney, payMoney;
	
	age = inputAge();
	n = inputN();

	printf("\n \n");
	if (age <= 7)
		fee = 500;
	else if (age < 14)
		fee = 700;
	else if (age < 20)
		fee = 1000;
	else if (age < 56)
		fee = 1500;
	else
		fee = 500;

	totMoney = fee * n;
	if (n >= 5)
		discMoney = totMoney * 0.1;
	else
		discMoney = 0;
	payMoney = totMoney - discMoney;

	print(totMoney, discMoney, payMoney);
}

int inputAge()
{
	int age;
	printf("���尴�� ���̸� �Է��Ͻÿ� : ");
	scanf("%d", &age);
	return age;
}

int inputN()
{
	int n;
	printf("���尴�� ���� �Է��Ͻÿ� : ");
	scanf("%d", &n);
	return n;
}

void print(int totMoney, int discMoney, int payMoney)
{
	printf("����� => %d��\n", totMoney);
	printf("���αݾ� => %d��\n", discMoney);
	printf("�����ݾ� => %d��\n", payMoney);
}