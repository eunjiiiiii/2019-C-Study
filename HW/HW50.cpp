#pragma warning (disable:4996)
#include<stdio.h>
#include <string.h>

void strInput(char* strp);
char charInput();
int strcheck(char* strp, char ch, int size);
void myflush();

int main()
{
	char str[99] = { 0 };
	char end[] = "end";
	char ch;
	int size, check, i, res=0;

	while (1)
	{

		strInput(str);
		size = strlen(str) + 1;


		if (strcmp(str, "end") == 0)
		{
			break;
		}

		ch = charInput();


		size = strlen(str)+1;

		check = strcheck(str, ch, size);

		if (check == -1)
		{
			printf("\"%s\"���ڿ� �ȿ� '%c'���ڴ� �������� �ʽ��ϴ�.\n\n", str, ch);
		}
		else
		{
			printf("\"%s\"���ڿ� �ȿ� '%c'���ڴ� %d�� ��ġ�� �����մϴ�.\n\n", str, ch, check);
		}
	}
	return 0;
}

void strInput(char *strp)
{
	int i;
	printf("# ���ڿ��� �Է��Ͻÿ� : ");
	scanf("%s", strp);
	myflush();

}

char charInput() //���� �Է��Լ�
{
	char ch;
	printf("# ���ڸ� �Է��Ͻÿ� : ");
	scanf("%c", &ch);
	myflush();

	return ch;
}

void myflush()
{
	while (getchar() != '\n')
	{
		;
	}
}

int strcheck(char* strp, char ch, int size)
{
	int i=0;
	for(i=0; i<size; i++)
	{
		if (strp[i] == ch)
		{
			return i;
		}

	}

	return -1;

}