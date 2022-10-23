#pragma warning(disable:4996)
#include<stdio.h>

int main()
{
	int i, j, n;

	for (i = 0; i < 10; i++)
	{
		for (j = 1; j <= 10; j++)
		{
			n = (i * 10 + j);

			if (n % 3 == 0 && n % 5 == 0)
			{
				printf("%d\t", n);
			}
			else if (n % 3 == 0)
			{
				printf("*\t");
			}
			else if (n % 5 == 0)
			{
				printf("#\t");
			}
			else
			printf("%d\t", n);
		}
		printf("\n");
	}



	return 0;
}