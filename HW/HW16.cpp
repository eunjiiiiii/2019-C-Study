#pragma warning(disable : 4996)
#include <stdio.h>

int input(void);
void print(int n);

int main()
{
	int i=0, n, fee, k;


	while (i < 5)
	{
		n=input();
		if (n <= 5)
		{
			fee = 600;
			print(fee);
		}

		else if (n <= 10)
		{
			fee = 800;
			print(fee);
		}

		else if (n > 10)
		{
			k = n - 10;
			if (k % 2 != 0)
				fee = 800 + (k/2 + 1) * 100;
			else
				fee = 800 + (k/2) * 100;
			print(fee);
		}
		i++;
	}

	return 0;
}

int input(void)
{
	int n;
	printf("역수를 입력하시오 : ");
	scanf("%d", &n);
	return n;
}

void print(int fee)
{
	printf("요금 : %d원\n", fee);
}