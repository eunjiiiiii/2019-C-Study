#pragma warning (disable: 4996)
#include <stdio.h>


void input(double* ary, int size);
void myflush();
double findMAX(double* ary, int size);
double findMIN(double* ary, int size);
void output(double MAX, double MIN);

int main()
{
	double ary[5];
	int size;
	double MAX, MIN;

	size = sizeof(ary) / sizeof(ary[0]); //배열 요소의 개수

	input(ary, size); //입력 받아옴

	MAX = findMAX(ary, size);
	MIN = findMIN(ary, size);

	output(MAX, MIN);

	return 0;
}

void input(double * ary, int size)
{
	int i, res;

	for (i = 0; i < size; i++)
	{
		while (1)
		{
			printf("%i번 방 값 : ", i);
			res=scanf("%lf", ary+i);
			myflush();
			if (res == 1)
			{
				break;
			}
			printf("** 잘못 입력하셨습니다. 실수를 입력해주세요.\n");
		}
	}

}

void myflush()
{
	while (getchar() != '\n')
	{
		;
	}
}

double findMAX(double* ary, int size)
{
	double MAX;
	int i;
	MAX = ary[0];

	for (i = 1; i < size; i++)
	{
		if (ary[i] > MAX)
		{
			MAX = ary[i];
		}
	}

	return MAX;
}

double findMIN(double* ary, int size)
{
	double MIN;
	int i;
	MIN = ary[0];

	for (i = 1; i < size; i++)
	{
		if (ary[i] < MIN)
		{
			MIN = ary[i];
		}
	}

	return MIN;
}

void output(double MAX, double MIN)
{
	printf("\n\n");
	printf("가장 큰 값 : %.2lf\n", MAX);
	printf("가장 작은 값 : %.2lf\n", MIN);
}