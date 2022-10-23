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
		input(str); //배열 str 초기화

		strcpy(cmp, str); //cmp에 str 복사

		if (strcmp(str, "end") == 0) //종료조건 : "end" 입력시
		{
			break;
		}
		len = strlen(str); //문자열의 크기 계산

		res=strCheck(cmp, len); //회문 검사 1:회문, 0:회문 아님

		output(str, res); //res별로 문자열 출력
	}

	return 0;
}

void input(char* sp)
{
	printf("# 단어 입력 : ");
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
		printf("  \"%s\" : 회문입니다!\n", sp);
	}
	else
	{
		printf("  \"%s\" : 회문이 아닙니다!\n", sp);
	}
	printf("\n");
}