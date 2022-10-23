#pragma warning(disable : 4996)
#include <stdio.h>

int main()
{
	double s1, s2, s3, s4, s5;
	double hsum=0, havg;

	printf("- 1번 학생의 키는? ");
	scanf("%lf", &s1);
	hsum += s1;
	printf("- 2번 학생의 키는? ");
	scanf("%lf", &s2);
	hsum += s2;
	printf("- 3번 학생의 키는? ");
	scanf("%lf", &s3);
	hsum += s3;
	printf("- 4번 학생의 키는? ");
	scanf("%lf", &s4);
	hsum += s4;
	printf("- 5번 학생의 키는? ");
	scanf("%lf", &s5);
	hsum += s5;

	havg = hsum / 5;

	printf("다섯 명의 평균 키는 %.1lf cm 입니다.", havg);



	return 0;
}