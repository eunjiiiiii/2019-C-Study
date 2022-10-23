#pragma warning(disable:4996)
#include<stdio.h>

void inputScope(int* fp, int* lp);
void myflush();
char inputEorO(int first, int last);
void output(int first, int last, char ch);

int main()
{
	int first, last;
	char ch;

	inputScope(&first, &last);

	ch = inputEorO(first, last);

	output(first, last, ch);

	return 0;
}

void inputScope(int* fp, int* lp)
{
	int res1, res2;
	while (1)
	{
		printf("# 시작 값을 입력하시오 : ");
		res1 = scanf("%d", fp);
		myflush();
		if (res1 == 1 && *fp >= 0) //문자나 음수 입력 금지
		{
			break;
		}
	}

	while(1)
	{
		printf("# 끝 값을 입력하시오 : ");
		res2 = scanf("%d", lp);
		myflush();
		if (res2==1  && *lp>*fp)
		{
			break;
		}
	}
}

void myflush()
{
	while (getchar() != '\n') {
		;
	}
}

char inputEorO(int first, int last)
{
	char ch;
	while (1)
	{
		printf("* %d~%d 까지의 짝수의 합을 구할까요? 홀수의 합을 구할까요?(짝수:e/홀수:o) : ", first, last);
		scanf("%c", &ch);
		myflush();
		if (ch == 'e' || ch == 'o')
		{
			break;
		}
	}
	return ch;
}

void output(int first, int last, char ch) //call by value
{
	int i, sum=0;

	if (ch == 'e') //짝수입력
	{
		printf("  %d~%d 까지의 짝수(", first, last);
		if (first % 2 != 0)
		{
			first++;
		}
	}

	else if (ch == 'o')
	{
		printf("  %d~%d 까지의 홀수(", first, last);
		if (first % 2 == 0)
		{
			first++;
		}
	}

	for (i = first; i <= last; i += 2)
	{
		printf("%d ", i);
		sum += i;
	}

	printf("\b)의 합은 %d 입니다.", sum);

}