#pragma warning (disable : 4996)
#include <stdio.h>

int input();
int escapeDay(int d);
void output(int d, int day);

int main()
{
	int d, day; //�칰�� ����
	d = input();

	day = escapeDay(d);

	output(d, day);

	return 0;
}

int input()
{
	int d;
	printf("*�칰�� ���̸� �Է��Ͻÿ�(cm����) : ");
	scanf("%d", &d);

	return d;
}

int escapeDay(int d)
{
	int day = 1;
	if (d == 0)
	{
		day = 0;
	}
	else if (1<=d && d <= 50)
	{
		day = 1;
	}
	else 
	{
		int i = 1;
		while (d > 50)
		{
			d = d - 30;
			day++;
		}

	}
	return day;
	
}

void output(int d, int day)
{
	printf("%.2lf ���� ������ �칰�� Ż���ϱ� ���ؼ��� %d���� �ɸ��ϴ�.", d * 0.01, day);
}
