#pragma warning(disable:4996)
#include <stdio.h>

double inputd();
double inputs();
void output(double d, int h, int m, double s);

int main()
{
	double d, s, time, second;
	int hour, minute;
	d = inputd();
	s = inputs();

	time = d / s;
	hour = (int)time;
	minute = (int)((time - hour) * 60);
	second = (time - hour - (double)minute/60) * 3600;
	
	output(d, hour, minute, second);

	return 0;
}

double inputd()
{
	double d;
	printf("*�Ÿ��� �Է��Ͻÿ�(km����) : ");
	scanf("%lf", &d);

	return d;
}

double inputs()
{
	double s;
	printf("*�ü��� �Է��Ͻÿ�(km/h����) : ");
	scanf("%lf", &s);

	return s;
}

void output(double d, int h, int m, double s)
{
	printf("%.2lf km = >%d�ð� %d�� %.3lf �� �ҿ��", d, h, m, s);
}