#pragma warning (disable : 4996)
#include <stdio.h>

int main()
{
	int n1, n2, res;

	while (1)
	{
		printf("# 두개의 정수를 입력하세요 : ");
		res= scanf("%d %d", &n1, &n2);

		if (res != 2)
			break;

		if (n1 > n2)
		{
			res = n1 - n2;
			printf("%d - %d = %d\n", n1, n2, res);
		}
		else
		{
			res = n2 - n1;
			printf("%d - %d = %d\n", n2, n1, res);
		}

	}
	

	return 0;
}