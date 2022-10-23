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

	printf("* ���� �ܾ��� %d�� �Դϴ�.\n\n", balance);

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

char menu() //�޴� ��� �� ����ڰ� ������ �޴� ���ڸ� �����ϴ� �Լ� �޴� ����(i,o,q)���� ���� �Է½� ���Է� �䱸
{
	char userMenu;



	while (1)
	{
		printf("# �޴��� �����Ͻÿ�(i-�Ա�, o-���, q-����) : ");
		scanf("%c", &userMenu);
		myflush();
		if (userMenu == 'i' || userMenu == 'o' || userMenu == 'q')
		{
			break;
		}
		printf("* �߸� �Է��ϼ̽��ϴ�.\n\n");
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

		myflush(); // stdin �� �ִ� ���ڵ� ����
		if (res == 1 && money > 0) //���ڰ� �ƴϰ�, ����� ��
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

void deposit(int* balance)
{
	int money, size;
	char printS[] = "# �Աݾ��� �Է��ϼ��� : ";

	size = sizeof(printS) / sizeof(printS[0]);

	money = inputInt(printS, size);

	*balance += money;

	printf("* ���� �ܾ��� %d�� �Դϴ�.\n\n", *balance);

}

void withdraw(int* balance)
{
	int money, size;
	char printS[] = "# ��ݾ��� �Է��ϼ��� : ";

	size = sizeof(printS) / sizeof(printS[0]);

	money = inputInt(printS, size);

	if (*balance >= money)
	{
		*balance -= money;
	}
	else
	{
		printf("* �ܾ��� �����մϴ�.\n");
	}

	printf("* ���� �ܾ��� %d�� �Դϴ�.\n\n", *balance);

}