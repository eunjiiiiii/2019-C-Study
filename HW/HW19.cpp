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
	printf("년도를 입력하시오 : ");
	scanf("%d", &year);
	return year;
}

int yearCheck(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0) //400으로 나눠떨어져서 100으로도 나눠떨어지나 검사
				return 1; //윤년
			else
				return 0; //4와 100으로만 나눠떨어지므로 평년
		}
		else
			return 1; //4로는 나눠떨어지는데 100으로는 나눠떨어지지 않는다는 윤년의 조건 만족

	}
	else
		return 0; //평년
}

void output(int year, int k)
{
	if (k == 1)
		printf("%d년은 윤년(Leap year)입니다.", year);
	else
		printf("%d년은 평년(Common year)입니다.", year);
}