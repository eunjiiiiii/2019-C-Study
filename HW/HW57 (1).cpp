#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#define LEN lp[i]

void inputStr(char(*p)[20], int size);
void myflush();
void sortStr(char(*p)[20], int size, int* lp);
void output(char(*p)[20], int* lp);
void calcLen(int* lp, int size, char(*p)[20]);

int main()
{
	int i, size, len[5];
	char str[5][20] = { 0 };
	
	size = sizeof(str) / sizeof(str[20]); //행 size
	
	inputStr(&str[0], size);
	calcLen(len, size, str);
	sortStr(str, size, len);
	calcLen(len, size, str);
	output(str, len);

	return 0;
}


void inputStr(char (*p)[20], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("# %d번 문자열을 입력하시오 : ", i+1);
		scanf("%s", p[i]);
		myflush();
	}
}

void myflush()
{
	while (getchar() != '\n'){
		;
	}
}

void sortStr(char(*p)[20], int size, int*lp)
{
	int i,j;
	char temp[20] = { 0 };
	for (i = 0; i < size-1; i++)
	{
		for (j = i + 1; j < LEN-1; j++)
		{
			if (strcmp(p[i], p[j]) > 0)
			{
				strcpy(temp, p[i]);
				strcpy(p[i], p[j]);
				strcpy(p[j], temp);
			}
		}
	}
}

void output(char(*p)[20], int *lp)
{
	int i;
	printf("\n");
	for (i = 0; i < LEN; i++)
	{
		printf("str[%d] = %s %3c %3c\n", i, p[i], p[i][0], p[i][LEN - 1]);
	}
}

void calcLen(int *lp, int size, char(*p)[20])
{
	int i;
	for (i = 0; i < size; i++)
	{
		lp[i] = strlen(p[i]);
	}
}