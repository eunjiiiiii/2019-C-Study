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
		printf("# ���� ���� �Է��Ͻÿ� : ");
		res1 = scanf("%d", fp);
		myflush();
		if (res1 == 1 && *fp >= 0) //���ڳ� ���� �Է� ����
		{
			break;
		}
	}

	while(1)
	{
		printf("# �� ���� �Է��Ͻÿ� : ");
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
		printf("* %d~%d ������ ¦���� ���� ���ұ��? Ȧ���� ���� ���ұ��?(¦��:e/Ȧ��:o) : ", first, last);
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

	if (ch == 'e') //¦���Է�
	{
		printf("  %d~%d ������ ¦��(", first, last);
		if (first % 2 != 0)
		{
			first++;
		}
	}

	else if (ch == 'o')
	{
		printf("  %d~%d ������ Ȧ��(", first, last);
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

	printf("\b)�� ���� %d �Դϴ�.", sum);

}