#pragma warning(disable:4996)
#include <stdio.h>

void myflush();


int main()
{
	int money, res, calmoney;
	int i, j, k;
	int rangei, rangej;

	while (1)
	{
		printf("���� ����� ���� �ݾ� �Է� : ");
		res = scanf("%d", &money);
		myflush();
		if (res != 1)
		{
			break;
		}

		rangei = money / 500; //ũ����
		rangej = money / 700; //�����
		//rangek = money / 400;

		calmoney = money;
		for (i = 1; i < rangei; i++)
		{
			for (j = 1; j < rangej; j++)
			{
				calmoney = money - 500 * i - 700 * j;

				if (calmoney % 400 == 0 && (calmoney/400) > 0)
				{
					printf("ũ����(%d��), �����(%d����), �ݶ�(%d��)\n", i, j, calmoney/400);
				}
				
			}
		}

		printf("��� �����Ͻðڽ��ϱ�?\n\n");

	}


	return 0;
}


//int input()
//{
//	int money, res;
//
//	while (1)
//	{
//		printf("���� ����� ���� �ݾ� �Է� : ");
//		res = scanf("%d", &money);
//		if (res != 1)
//		{
//			break;
//		}
//	}
//}

void myflush()
{
	while(getchar()!='\n')
	{
		;
	}
}