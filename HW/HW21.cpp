#pragma warning(disable : 4996)
#include <stdio.h>

int main()
{
	double s1, s2, s3, s4, s5;
	double hsum=0, havg;

	printf("- 1�� �л��� Ű��? ");
	scanf("%lf", &s1);
	hsum += s1;
	printf("- 2�� �л��� Ű��? ");
	scanf("%lf", &s2);
	hsum += s2;
	printf("- 3�� �л��� Ű��? ");
	scanf("%lf", &s3);
	hsum += s3;
	printf("- 4�� �л��� Ű��? ");
	scanf("%lf", &s4);
	hsum += s4;
	printf("- 5�� �л��� Ű��? ");
	scanf("%lf", &s5);
	hsum += s5;

	havg = hsum / 5;

	printf("�ټ� ���� ��� Ű�� %.1lf cm �Դϴ�.", havg);



	return 0;
}