#pragma warning(disable:4996)
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void random(int(*np)[4]);
void output(int(*np)[4]);

int main()
{
	int num[3][4];
	int n;
	int i,j;

	random(num);
	output(num);


	return 0;
}

void random(int (*np)[4])
{
	int res, i, j;
	srand((unsigned int)time(NULL));
	i = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			np[i][j] = rand() % 9 + 1;
		}
	}
}

void output(int(*np)[4])
{
	int i, j;
	int rowsum = 0, colsum[4] = { 0 };

	for (i = 0; i < 3; i++)
	{
		rowsum = 0;
		printf("%d행\t:  ", i);
		for (j = 0; j < 4; j++)
		{
			printf("%d\t ", np[i][j]);
			rowsum += np[i][j];
			colsum[j] += np[i][j];
		}
		printf("%d 행의 합 : %d\n", i, rowsum);
	}

	printf("%열의 합 : ");

	for (i = 0; i < 4; i++)
	{
		printf("%d\t", colsum[i]);
	}

}