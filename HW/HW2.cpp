#pragma warning(disable:4996)

#include <stdio.h>

int main()
{
	int money, calmoney=0, m50000, m10000, m5000, m1000, m500, m100, m50, m10;

	printf("�뵷(��)�� �Է��Ͻÿ�. : ");
	scanf("%d", &money);

	m50000 = money / 50000;
	calmoney = money - 50000 * m50000;

	m10000 = calmoney / 10000;
	calmoney = calmoney - 10000 * m10000;

	m5000 = calmoney / 5000;
	calmoney = calmoney - 5000 * m5000;

	m1000 = calmoney / 1000;
	calmoney = calmoney - 1000 * m1000;

	m500 = calmoney / 500;
	calmoney = calmoney - 500 * m500;

	m100 = calmoney / 100;
	calmoney = calmoney - 100 * m100;

	m50 = calmoney / 50;
	calmoney = calmoney - 50 * m50;

	m10 = calmoney / 10;
	calmoney = calmoney - 10 * m10;

	printf("50000���� => %d��\n", m50000);
	printf("10000���� => %d��\n", m10000);
	printf("5000���� => %d��\n", m5000);
	printf("1000���� => %d��\n", m1000);
	printf("500���� => %d��\n", m500);
	printf("100���� => %d��\n", m100);
	printf("50���� => %d��\n", m50);
	printf("10���� => %d��\n", m10);

	return 0;
}
