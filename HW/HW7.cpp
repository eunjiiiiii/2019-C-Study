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
	printf("*거리를 입력하시오(km단위) : ");
	scanf("%lf", &d);

	return d;
}

double inputs()
{
	double s;
	printf("*시속을 입력하시오(km/h단위) : ");
	scanf("%lf", &s);

	return s;
}

void output(double d, int h, int m, double s)
{
	printf("%.2lf km = >%d시간 %d분 %.3lf 초 소요됨", d, h, m, s);
}