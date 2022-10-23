#pragma warning (disable : 4996)
#include <stdio.h>

char menu();
int inputInt(char* printS, int size);
void myflush();
void deposit(int* balance);
void withdraw(int* balance);


int main()
{
	char userMenu;
	int balance = 0;

	printf("* 현재 잔액은 %d원 입니다.\n\n", balance);

	while (1)
	{

		userMenu = menu();

		if (userMenu == 'q')
		{
			break;
		}
		else if (userMenu == 'i')
		{
			deposit(&balance);
		}
		else
		{
			withdraw(&balance);
		}

	}



	return 0;
}

char menu() //메뉴 출력 후 사용자가 선택한 메뉴 문자를 리턴하는 함수 메뉴 문자(i,o,q)외의 문자 입력시 재입력 요구
{
	char userMenu;



	while (1)
	{
		printf("# 메뉴를 선택하시오(i-입금, o-출금, q-종료) : ");
		scanf("%c", &userMenu);
		myflush();
		if (userMenu == 'i' || userMenu == 'o' || userMenu == 'q')
		{
			break;
		}
		printf("* 잘못 입력하셨습니다.\n\n");
	}

	return userMenu;
}


int inputInt(char* printS, int size)
{
	int money, i, res;

	for (i = 0; i < size; i++)
	{
		printf("%c", printS[i]);
	}

	while (1)
	{
		money = 0;
		res = scanf("%d", &money);

		myflush(); // stdin 에 있는 문자들 지움
		if (res == 1 && money > 0) //문자가 아니고, 양수일 때
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

void deposit(int* balance)
{
	int money, size;
	char printS[] = "# 입금액을 입력하세요 : ";

	size = sizeof(printS) / sizeof(printS[0]);

	money = inputInt(printS, size);

	*balance += money;

	printf("* 현재 잔액은 %d원 입니다.\n\n", *balance);

}

void withdraw(int* balance)
{
	int money, size;
	char printS[] = "# 출금액을 입력하세요 : ";

	size = sizeof(printS) / sizeof(printS[0]);

	money = inputInt(printS, size);

	if (*balance >= money)
	{
		*balance -= money;
	}
	else
	{
		printf("* 잔액이 부족합니다.\n");
	}

	printf("* 현재 잔액은 %d원 입니다.\n\n", *balance);

}