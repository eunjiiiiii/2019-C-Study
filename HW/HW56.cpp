#pragma warning(disable:4996)
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int random(int);
void inputAry(int(*ap)[5]);


int main()
{
	int ary[5][5];
	int i, j;
	int sum1 = 0, sum2 = 0, sum3 = 0;

	inputAry(ary);

	for (i = 0; i < 5; i++)
	{
		printf("%d¹ø Çà : ", i);
		for (j = 0; j < 5; j++)
		{
			if (j < i) {
				sum3 += ary[i][j];
			}
			else if (j > i) {
				sum2 += ary[i][j];
			}
			else { //i==j
				sum1 += ary[i][j];
			}
			printf("%-5d", ary[i][j]);
		}
		printf("\n");
	}

	printf("\n\nsum1= %d", sum1);
	printf("\nsum2= %d", sum2);
	printf("\nsum3= %d", sum3);

	return 0;
}

void inputAry(int(*ap)[5])
{
	int i,j;
	srand((unsigned int)time(NULL));

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			ap[i][j] = random(20) + 1;
		}
	}
	
}

int random(int n)
{
	int res;
	res = rand() % n;
	return res;
}