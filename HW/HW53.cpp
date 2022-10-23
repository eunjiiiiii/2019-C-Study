#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<ctype.h>

void input(char* sp);
void myflush();
int strCheck(char* cp, int len);
void output(char* sp, int res);

int main()
{
	char str[100] = { 0 };
	char cmp[100] = { 0 };
	int i, len, res;

	while (1)
	{
		input(str); //�迭 str �ʱ�ȭ

		strcpy(cmp, str); //cmp�� str ����

		if (strcmp(str, "end") == 0) //�������� : "end" �Է½�
		{
			break;
		}
		len = strlen(str); //���ڿ��� ũ�� ���

		res=strCheck(cmp, len); //ȸ�� �˻� 1:ȸ��, 0:ȸ�� �ƴ�

		output(str, res); //res���� ���ڿ� ���
	}

	return 0;
}

void input(char* sp)
{
	printf("# �ܾ� �Է� : ");
	scanf("%s", sp);
	myflush();
}

void myflush()
{
	while (getchar() != '\n') {
		;
	}
}

int strCheck(char* cp, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		cp[i]=toupper(cp[i]);
	}

	for (i = 0; i < len/2; i++)
	{
		if (cp[i] != cp[len - i - 1])
		{
			return 0;
		}
	}

	return 1;
}


void output(char* sp, int res)
{
	if (res == 1)
	{
		printf("  \"%s\" : ȸ���Դϴ�!\n", sp);
	}
	else
	{
		printf("  \"%s\" : ȸ���� �ƴմϴ�!\n", sp);
	}
	printf("\n");
}