#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <math.h>


int menu();
void myflush();
unsigned char openFan();
unsigned char offFan();
unsigned char reverseFan(unsigned char fan);
void displayFan(unsigned char fanCon);
int inputFanNum(char* fnum, int fnumSize);


int main()
{
	unsigned char fan = 0; //��� �����ִ� ����(0)���� �ʱ�ȭ, ����(0), ����(1)
	unsigned char open, off;
	int userMenu;

	while (1)
	{
		userMenu = menu();
		if (userMenu == 1) //Fan open
		{
			open = openFan();
			fan = fan | open;
			displayFan(fan);
		}
		else if (userMenu == 2) //Fan off
		{
			off = offFan();
			fan = fan & ~off;
			displayFan(fan);
		}
		else if(userMenu ==3) //Fan reverse
		{
			fan = reverseFan(fan);
			displayFan(fan);
		}
		else if(userMenu ==4) //quit
		{
			break;
		}
		else
		{
			printf("* �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���\n");
		}
	}

	return 0;
}


int menu()
{
	int menu, res;

	while (1)
	{
		printf("1. ȯǳ�� ���� / 2. ȯǳ�� �ݱ� / 3. ȯǳ�� ��ü ��ȯ / 4. ���� : ");
		res = scanf("%d", &menu);
		myflush();

		if (res == 1 && 1 <= res && res <= 4)
		{
			break;
		}

		printf("* �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n");
	}


	return menu;
}

void myflush()
{	
	while (getchar() != '\n')
	{
		;
	}
}

unsigned char openFan()
{
	unsigned char open;
	int fanNum, fnumSize;
	char fnum[] = "* OPEN�� FAN ��ȣ�� �Է��Ͻÿ�(1-8) : ";

	fnumSize = sizeof(fnum) / sizeof(fnum[0]);

	printf("----------------------------------------------------------------\n");
	printf("\t\tFan  ���� �۾� ���� ȭ��\n");
	printf("----------------------------------------------------------------\n");

	fanNum = inputFanNum(fnum, fnumSize);


	open = (unsigned char)1 << (fanNum - 1);

	return open;
}

unsigned char offFan()
{
	unsigned char off;
	int fanNum, fnumSize;
	char fnum[] = "* CLOSE�� FAN ��ȣ�� �Է��Ͻÿ�(1-8) : ";

	fnumSize = sizeof(fnum) / sizeof(fnum[0]);

	printf("----------------------------------------------------------------\n");
	printf("\t\tFan  �ݱ� �۾� ���� ȭ��\n");
	printf("----------------------------------------------------------------\n");

	fanNum = inputFanNum(fnum, fnumSize);


	off = (unsigned char)1 << (fanNum - 1);

	return off;
}

unsigned char reverseFan(unsigned char fan)
{
	unsigned char reverse;

	printf("----------------------------------------------------------------\n");
	printf("\t\tFan  ��ü ��ȯ �۾� ���� ȭ��\n");
	printf("----------------------------------------------------------------\n");
	printf("��ü FAN�� ���°� ��ȯ�Ǿ����ϴ�. (ON, OFF ���� �ڹٲ�)\n");
	printf("----------------------------------------------------------------\n");

	fan = ~fan;

	return fan;


}


int inputFanNum(char * fnum, int fnumSize) //FAN ��ȣ ���ϴ� �Լ�
{
	int fanNum, i, res;

	while (1)
	{
		for (i = 0; i < fnumSize; i++) //���� ���
		{
			printf("%c", fnum[i]);
		}

		//�Է�
		res = scanf("%d", &fanNum);
		myflush();
		if (res == 1 && 1 <= fanNum && fanNum <= 8)
		{
			break;
		}

		printf("* �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��ϼ���.\n");
	}


	return fanNum;
}


void displayFan(unsigned char fan)
{
	int i, j, field=4;
	char on[] = "ON";
	char off[] = "OFF";

	printf("----------------------------------------------------------------\n");

	for (i = 8; i >= 1; i--)
	{
		printf("%d��FAN\t", i);
	}

	printf("\n");

		for (j = 128; j >= 1; j /= 2)
		{
			
			if ((fan & j) == j)
			{
				printf("%*s\t ", field, on);
			}
			else
			{
				printf("%*s\t ", field, off);
			}
		}
	

	printf("\n");
	printf("----------------------------------------------------------------\n");

}

