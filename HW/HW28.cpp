#pragma warning(disable : 4996)
#include <stdio.h>

void output(int alp, int num, int blank, int etc);

int main()
{
	char ch;
	int alp=0, num=0, blank=0, etc=0;

	printf("# 영문 문장을 입력하시오 : \n");
	while ((ch = getchar()) != EOF)
	{
		if ('A' <= ch && ch <= 'z')
		{
			if ('Z' < ch && ch < 'a') //중간 기타문자
				etc++;
			else alp++;
		}
		else if (48 <= ch && ch <= 57)
			num++;
		else if (ch == ' ' || ch == '\t' || ch == '\n')
			blank++;
		else
			etc++;
	}
	output(alp, num, blank, etc);
	
	return 0;
}


void output(int alp, int num, int blank, int etc)
{
	printf("* 영문자 대소문자 개수 : %d개\n", alp);
	printf("* 숫자문자 개수 : %d개\n", num);
	printf("* 여백문자(space, tab, enter) 개수 : %d개\n", blank);
	printf("* 그 외 기타문자 개수 : %d개\n", etc);
}