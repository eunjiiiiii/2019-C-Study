#pragma warning(disable:4996)
#include <stdio.h>


int main()
{
	int i, j;
	char ch;

	while (1)
	{
		printf("# ������ �빮�� �Է�('A'~'Z') : ");
		scanf("%c", &ch);
		while (getchar() != '\n')
		{
			;
		}

		if (ch<65 && 90<ch)
		{
			break;
		}

		for (i = ch; i >= 65; i--)
		{
			for (j = ch; j >= i; j--) 
			{
				printf("%c", j);
			}
			printf("\n");
		}
		printf("\n");
	}
	

	return 0;
}