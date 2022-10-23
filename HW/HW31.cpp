#pragma warning (disable : 4996)
#include<stdio.h>

char menu();
void actMenu(int balance, char menu);
int deposit(int money);
int withdraw(int money);
int inputInt(char*printS, int size);
void myflush();


int main()
{
	char userMenu;
	int balance = 0; //잔액
	int dMoney, wMoney;

	printf("* 현재 잔액은 %d원 입니다.\n\n", balance); 

	userMenu = menu();


	actMenu(balance, userMenu);
		

	
	return 0;
}

char menu()
{
	char menu;
	while (1)
	{
		printf("# 메뉴를 선택하시오(i-입금, o-출금, q-종료) : ");
		scanf("%c", &menu);
		myflush();

		if (menu == 'i' || menu == 'o' || menu == 'q')
		{
			break;
		}
		printf("* 잘못 입력하셨습니다.\n\n");
	}
	

	return menu;
}

void actMenu(int balance, char userMenu)
{
	while (userMenu != 'q')
	{
		if (userMenu == 'i')
		{
			balance = deposit(balance);
			userMenu = menu();
			if (userMenu != 'q')
			{
				actMenu(balance, userMenu);
			}
			else break;
		}
		

		else if (userMenu == 'o')
		{
			balance = withdraw(balance);
			userMenu = menu();
			if (userMenu != 'q')
			{
				actMenu(balance, userMenu);
			}

			else break;
		}
		userMenu = 'q';
	}
}

int deposit(int balance)
{
	int dMoney, size;
	char printS[] = "# 입금액을 입력하세요 : ";
	size = sizeof(printS) / sizeof(printS[0]);

	dMoney = inputInt(printS, size);

	balance += dMoney;

	printf("* 현재 잔액은 %d원 입니다.\n\n", balance);

	return balance;
}

int withdraw(int balance)
{
	int wMoney, size;
	char userMenu;
	char printS[] = "# 출금액을 입력하세요 : ";
	size = sizeof(printS) / sizeof(printS[0]);

	wMoney = inputInt(printS, size);

	if (balance >= wMoney)
	{
		balance -= wMoney;
		printf("* 현재 잔액은 %d원 입니다.\n\n", balance);
		return balance;
	}
	else
	{
		printf("* 잔액이 부족합니다.\n");
		printf("* 현재 잔액은 %d원 입니다.\n\n", balance);
		userMenu= menu();
		actMenu(balance,userMenu);
	}
}

int inputInt(char*printS, int size)  //정수입력함수
{
	int res, money;
	int i;

	for (i = 0; i < size; i++)
	{
		printf("%c", printS[i]);
	}

	while (1)
	{
		res = scanf("%d", &money);
		myflush();
		if (res == 1 && money > 0)
		{
			break;
		}
		printf("* 잘못 입력하셨습니다. 다시 입력하십시오 : ");
	}

	return money;
}

void myflush()
{
	while (getchar() != '\n')
	{
		;
	}
}

