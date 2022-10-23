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
	int balance = 0; //�ܾ�
	int dMoney, wMoney;

	printf("* ���� �ܾ��� %d�� �Դϴ�.\n\n", balance); 

	userMenu = menu();


	actMenu(balance, userMenu);
		

	
	return 0;
}

char menu()
{
	char menu;
	while (1)
	{
		printf("# �޴��� �����Ͻÿ�(i-�Ա�, o-���, q-����) : ");
		scanf("%c", &menu);
		myflush();

		if (menu == 'i' || menu == 'o' || menu == 'q')
		{
			break;
		}
		printf("* �߸� �Է��ϼ̽��ϴ�.\n\n");
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
	char printS[] = "# �Աݾ��� �Է��ϼ��� : ";
	size = sizeof(printS) / sizeof(printS[0]);

	dMoney = inputInt(printS, size);

	balance += dMoney;

	printf("* ���� �ܾ��� %d�� �Դϴ�.\n\n", balance);

	return balance;
}

int withdraw(int balance)
{
	int wMoney, size;
	char userMenu;
	char printS[] = "# ��ݾ��� �Է��ϼ��� : ";
	size = sizeof(printS) / sizeof(printS[0]);

	wMoney = inputInt(printS, size);

	if (balance >= wMoney)
	{
		balance -= wMoney;
		printf("* ���� �ܾ��� %d�� �Դϴ�.\n\n", balance);
		return balance;
	}
	else
	{
		printf("* �ܾ��� �����մϴ�.\n");
		printf("* ���� �ܾ��� %d�� �Դϴ�.\n\n", balance);
		userMenu= menu();
		actMenu(balance,userMenu);
	}
}

int inputInt(char*printS, int size)  //�����Է��Լ�
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
		printf("* �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻʽÿ� : ");
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

