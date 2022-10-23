#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int main()
{
	int user_input, res;
	int com_input;
	char user[20], com[20];
	user_input = input(); //사용자 입력
	
	if (user_input == 1)
		strcpy(user, "바위");
	else if (user_input == 2)
		strcpy(user, "가위");
	else
		strcpy(user, "보");

	if (com_input == 1)
		strcpy(com, "바위");
	else if (com_input == 2)
		strcpy(com, "가위");
	else
		strcpy(com, "보");

	srand((unsigned int)time(NULL));
	com_input = random(3)+1;

	while (res==-1)
	{
		if (user_input == 1) //바위
		{
			if (com_input == 1)
				res = 0;
			else if (com_input == 2)
				res = 1;
			else
				res = -1;
		}

		else if(user_input==2)	//가위
		{
			if (com_input == 1)
				res = -1;
			else if (com_input == 2)
				res = 0;
			else
				res = 1;
		}

		else //보
		{
			if (com_input == 1)
				res = 1;
			else if (com_input == 2)
				res = -1;
			else
				res = 0;
		}

	}
	
	printf("게임결과 : %d 승 %d 무 %패", )

	return 0;
}

int input()
{
	int user_input, res;
	
	while (1)
	{
		printf("#바위는 1. 가위는 2, 보는 3 중에서 선택하세요 : ");
		res=scanf("%d", &user_input);

		if (res == 1)
		{
			if (1 <= user_input && user_input <= 3)
			{
				break;
			}
		}
		myflush();
	}

	return user_input;
}

int random(int n) //난수 생성
{
	int res;
	res = rand() % n;
	return res;
}

void myflush()
{
	while (getchar() != '\n')
	{
		;
	}
}

void output(char*user, char*com, int res)
{
	if(res==1)
		printf("당신은 %s 선택, 컴퓨터는 %s 선택 : 이겼습니다.", user, com);
	else if (res==0)
		printf("당신은 %s 선택, 컴퓨터는 %s 선택 : 비겼습니다.", user, com);
	else
	printf("당신은 %s 선택, 컴퓨터는 %s 선택 : 졌습니다.", user, com);
}