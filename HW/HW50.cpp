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
			printf("\"%s\"문자열 안에 '%c'문자는 존재하지 않습니다.\n\n", str, ch);
		}
		else
		{
			printf("\"%s\"문자열 안에 '%c'문자는 %d번 위치에 존재합니다.\n\n", str, ch, check);
		}
	}
	return 0;
}

void strInput(char *strp)
{
	int i;
	printf("# 문자열을 입력하시오 : ");
	scanf("%s", strp);
	myflush();

}

char charInput() //문자 입력함수
{
	char ch;
	printf("# 문자를 입력하시오 : ");
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