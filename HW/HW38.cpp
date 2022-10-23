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
		printf("현재 당신의 소유 금액 입력 : ");
		res = scanf("%d", &money);
		myflush();
		if (res != 1)
		{
			break;
		}

		rangei = money / 500; //크림빵
		rangej = money / 700; //새우깡
		//rangek = money / 400;

		calmoney = money;
		for (i = 1; i < rangei; i++)
		{
			for (j = 1; j < rangej; j++)
			{
				calmoney = money - 500 * i - 700 * j;

				if (calmoney % 400 == 0 && (calmoney/400) > 0)
				{
					printf("크림빵(%d개), 새우깡(%d봉지), 콜라(%d병)\n", i, j, calmoney/400);
				}
				
			}
		}

		printf("어떻게 구입하시겠습니까?\n\n");

	}


	return 0;
}


//int input()
//{
//	int money, res;
//
//	while (1)
//	{
//		printf("현재 당신의 소유 금액 입력 : ");
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