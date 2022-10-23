#pragma warning(disable:4996)

#include <stdio.h>

int main()
{
	int money, calmoney=0, m50000, m10000, m5000, m1000, m500, m100, m50, m10;

	printf("용돈(원)을 입력하시오. : ");
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

	printf("50000원권 => %d개\n", m50000);
	printf("10000원권 => %d개\n", m10000);
	printf("5000원권 => %d개\n", m5000);
	printf("1000원권 => %d개\n", m1000);
	printf("500원권 => %d개\n", m500);
	printf("100원권 => %d개\n", m100);
	printf("50원권 => %d개\n", m50);
	printf("10원권 => %d개\n", m10);

	return 0;
}
