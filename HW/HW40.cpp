#pragma warning(disable:4996)
#include <stdio.h>


int main()
{
	int i, j, line, res;

	while (1)
	{
		printf("# ��� ���μ��� �Է��Ͻÿ� : ");
		res = scanf("%d", &line);
		if (res != 1)
		{
			break;
		}

		for (i = 0; i < line; i++) //���μ�
		{
			for (j = 0; j <= i; j++) //��
			{
				printf("*");
			}

			for (j = (2 * (line-i)); j >= 0; j--) //����
			{
				printf(" ");
			}
			
			for (j = 0; j <= i; j++) //��
			{
				printf("*");
			}

			printf("\n");
		}
		printf("\n");
	}
	

	return 0;
}