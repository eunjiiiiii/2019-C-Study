#pragma warning(disable:4996)
#include <stdio.h>

int yearCheck(int year);
int input();
void output(int year, int k);

int main()
{
	int k, year;

	year=input();

	k = yearCheck(year);

	output(year, k);

	return 0;
}

int input()
{
	int year;
	printf("�⵵�� �Է��Ͻÿ� : ");
	scanf("%d", &year);
	return year;
}

int yearCheck(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0) //400���� ������������ 100���ε� ������������ �˻�
				return 1; //����
			else
				return 0; //4�� 100���θ� �����������Ƿ� ���
		}
		else
			return 1; //4�δ� �����������µ� 100���δ� ������������ �ʴ´ٴ� ������ ���� ����

	}
	else
		return 0; //���
}

void output(int year, int k)
{
	if (k == 1)
		printf("%d���� ����(Leap year)�Դϴ�.", year);
	else
		printf("%d���� ���(Common year)�Դϴ�.", year);
}