#pragma warning(disable:4996)
#include <stdio.h>


int main()
{
	int i, j;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 100; j += 10)
		{
			printf("%d  ", j+i);
		}
		printf("\n");

	}


	return 0;
}