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
	unsigned char fan = 0; //모두 닫혀있는 상태(0)으로 초기화, 닫힘(0), 열림(1)
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
			printf("* 잘못 입력하셨습니다. 다시 입력해주세요\n");
		}
	}

	return 0;
}


int menu()
{
	int menu, res;

	while (1)
	{
		printf("1. 환풍구 열기 / 2. 환풍구 닫기 / 3. 환풍구 전체 전환 / 4. 종료 : ");
		res = scanf("%d", &menu);
		myflush();

		if (res == 1 && 1 <= res && res <= 4)
		{
			break;
		}

		printf("* 잘못 입력하셨습니다. 다시 입력해주세요.\n");
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
	char fnum[] = "* OPEN할 FAN 번호를 입력하시오(1-8) : ";

	fnumSize = sizeof(fnum) / sizeof(fnum[0]);

	printf("----------------------------------------------------------------\n");
	printf("\t\tFan  열기 작업 실행 화면\n");
	printf("----------------------------------------------------------------\n");

	fanNum = inputFanNum(fnum, fnumSize);


	open = (unsigned char)1 << (fanNum - 1);

	return open;
}

unsigned char offFan()
{
	unsigned char off;
	int fanNum, fnumSize;
	char fnum[] = "* CLOSE할 FAN 번호를 입력하시오(1-8) : ";

	fnumSize = sizeof(fnum) / sizeof(fnum[0]);

	printf("----------------------------------------------------------------\n");
	printf("\t\tFan  닫기 작업 실행 화면\n");
	printf("----------------------------------------------------------------\n");

	fanNum = inputFanNum(fnum, fnumSize);


	off = (unsigned char)1 << (fanNum - 1);

	return off;
}

unsigned char reverseFan(unsigned char fan)
{
	unsigned char reverse;

	printf("----------------------------------------------------------------\n");
	printf("\t\tFan  전체 전환 작업 실행 화면\n");
	printf("----------------------------------------------------------------\n");
	printf("전체 FAN의 상태가 전환되었습니다. (ON, OFF 상태 뒤바뀜)\n");
	printf("----------------------------------------------------------------\n");

	fan = ~fan;

	return fan;


}


int inputFanNum(char * fnum, int fnumSize) //FAN 번호 구하는 함수
{
	int fanNum, i, res;

	while (1)
	{
		for (i = 0; i < fnumSize; i++) //문장 출력
		{
			printf("%c", fnum[i]);
		}

		//입력
		res = scanf("%d", &fanNum);
		myflush();
		if (res == 1 && 1 <= fanNum && fanNum <= 8)
		{
			break;
		}

		printf("* 잘못 입력하셨습니다. 다시 입력하세요.\n");
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
		printf("%d번FAN\t", i);
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

