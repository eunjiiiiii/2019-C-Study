#pragma warning(disable:4996)
#include<stdio.h>

int input(int(*sp)[10], int* np);
void makeJolly(int(*jp), int* sp, int n);
void sort(int* jp, int n);
int checkJolly(int* jp, int n);
void output(int(*sp), int res, int n);
void myflush();

int main()
{
	int seq[5][10] = { 0 };
	int tc, n[5] = { 0 }, i, res;
	int jolly[5][9] = { 0 };
	int sorted[5][9]={ 0 };

	tc = input(seq, n);
	printf("\n");
	for (i = 0; i < tc; i++)
	{
		makeJolly(&jolly[i][0], &seq[i][0], n[i]);
		sort(&jolly[i][0], n[i]);
		res = checkJolly(&jolly[i][0], n[i]);
 		output(&seq[i][0], res, n[i]);
	}

	return 0;
}

int input(int(*sp)[10], int*np)
{
	int tc, i, j;

	scanf("%d", &tc);

	for (i = 0; i < tc; i++)
	{
		scanf(" %d", &np[i]);
		for (j = 0; j < np[i]; j++)
		{
			scanf(" %d", &sp[i][j]);
		}
		myflush();
	}	
	return tc;
}

void makeJolly(int (*jp), int*sp, int n)
{
	int i;

	for (i = 0; i < n-1; i++)
	{
		if (sp[i] > sp[i+1])
		{
			jp[i] = sp[i] - sp[i+1];
		}
		else
		{
			jp[i] = sp[i + 1] - sp[i];
		}
	}	
}

void sort(int* jp, int n)
{
	int i, j, temp;
	for (i = 0; i < n-1; i++)
	{
		for (j = i + 1; j < n-1; j++)
		{
			if (jp[i] > jp[j])
			{
				temp = jp[i];
				jp[i] = jp[j];
				jp[j] = temp;
			}
		}
	}
}

int checkJolly(int* jp, int n)
{
	int i, res=0;
	for (i = 0; i < n-2; i++)
	{
		if ((jp[i + 1] - jp[i]) == 1)
		{
			res++;
		}
	}

	if (res == (n - 2))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void output(int(*sp), int res, int n)
{
	int i;

	printf("검사한 수열 : ");
	for (i = 0; i < n; i++)
	{
		printf("%d ", sp[i]);
	}
	
	if (res == 1)
	{
		printf("(Jolly jumper)\n");
	}
	else
	{
		printf("(Not jolly jumper)\n");
	}
}

void myflush()
{
	while(getchar() != '\n') {
		;
	}
}