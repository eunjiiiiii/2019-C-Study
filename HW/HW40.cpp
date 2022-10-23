#pragma warning(disable:4996)
#include <stdio.h>


int main()
{
	int i, j, line, res;

	while (1)
	{
		printf("# 출력 라인수를 입력하시오 : ");
		res = scanf("%d", &line);
		if (res != 1)
		{
			break;
		}

		for (i = 0; i < line; i++) //라인수
		{
			for (j = 0; j <= i; j++) //별
			{
				printf("*");
			}

			for (j = (2 * (line-i)); j >= 0; j--) //공백
			{
				printf(" ");
			}
			
			for (j = 0; j <= i; j++) //별
			{
				printf("*");
			}

			printf("\n");
		}
		printf("\n");
	}
	

	return 0;
}