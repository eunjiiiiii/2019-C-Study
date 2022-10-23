#pragma warning(disable : 4996)
#include <stdio.h>

int main()
{
	double day = 365.2422, isecond;
	int iday, ihour, iminute;

	iday = (int) day;
	ihour = (int)((day - iday) * 24);
	iminute = (int)((day - iday) * 1440- (int)ihour * 60);
	isecond = (day - iday) * 86400 - (int)ihour * 3600 - (int)iminute * 60;

	printf("%.4lf일은 %d일 %d시간 %d분 %.2lf초입니다.", day, iday, ihour, iminute, isecond);

	return 0;
}