#pragma warning (disable : 4996)
#include <stdio.h>
int main()
{
	int i, j, k;
	printf("<2�� for���� �̿��� ���>\n");
	
	for (i = 1; i <= 9; i++)
	{
		for (j = 2; j <= 5; j++)
		{
			printf("%d*%d= %d\t\t", j, i, j * i);
		}
		printf("\n");
	}
	printf("\n");
	for (i = 1; i <= 9; i++)
	{
		for (j = 6; j <= 9; j++)
		{
			printf("%d*%d= %d\t\t", j, i, j * i);
		}
		printf("\n");
	}

	printf("\n---------------------------------------------------------------------\n\n");
	printf("<3�� for���� �̿��� ���>\n");
	for (i = 1; i <= 2; i++)
	{
		for (k = 1; k <= 9; k++)
		{
			for (j = (4 * i - 2); j <= (4 * i + 1); j++)
			{
				printf("%d*%d= %d\t\t", j, k, j * k);
			}
			printf("\n");
		}
		printf("\n");
	}
		return 0;
}