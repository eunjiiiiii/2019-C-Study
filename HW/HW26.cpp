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
	user_input = input(); //����� �Է�
	
	if (user_input == 1)
		strcpy(user, "����");
	else if (user_input == 2)
		strcpy(user, "����");
	else
		strcpy(user, "��");

	if (com_input == 1)
		strcpy(com, "����");
	else if (com_input == 2)
		strcpy(com, "����");
	else
		strcpy(com, "��");

	srand((unsigned int)time(NULL));
	com_input = random(3)+1;

	while (res==-1)
	{
		if (user_input == 1) //����
		{
			if (com_input == 1)
				res = 0;
			else if (com_input == 2)
				res = 1;
			else
				res = -1;
		}

		else if(user_input==2)	//����
		{
			if (com_input == 1)
				res = -1;
			else if (com_input == 2)
				res = 0;
			else
				res = 1;
		}

		else //��
		{
			if (com_input == 1)
				res = 1;
			else if (com_input == 2)
				res = -1;
			else
				res = 0;
		}

	}
	
	printf("���Ӱ�� : %d �� %d �� %��", )

	return 0;
}

int input()
{
	int user_input, res;
	
	while (1)
	{
		printf("#������ 1. ������ 2, ���� 3 �߿��� �����ϼ��� : ");
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

int random(int n) //���� ����
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
		printf("����� %s ����, ��ǻ�ʹ� %s ���� : �̰���ϴ�.", user, com);
	else if (res==0)
		printf("����� %s ����, ��ǻ�ʹ� %s ���� : �����ϴ�.", user, com);
	else
	printf("����� %s ����, ��ǻ�ʹ� %s ���� : �����ϴ�.", user, com);
}