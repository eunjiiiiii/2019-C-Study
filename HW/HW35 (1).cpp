#pragma warning(disable:4996)
#include <stdio.h>


int main()
{
	int i, n, res;
	int sum = 0;

	for (i = 1; i <= 5; i++)
	{
		while (1)
		{
			printf("0보다 큰수를 입력하시오(%d 번째) : ", i);
			res=scanf("%d", &n);
			while (getchar() != '\n')
			{
				;
			}
			if (res == 1 && n > 0)
			{
				break;
			}
		}
		sum += n;
	}

	printf("입력된 값의 총 합 : %d\n", sum);




	return 0;
}