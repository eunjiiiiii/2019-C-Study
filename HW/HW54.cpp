#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void input(char* sp);
void myflush();
int calnum(char* sp, int len);
void output(char* sp, int sum);

int main()
{
	char str[100] = { 0 };
	int len, tot=0;
	//문자열 입력

	while (1){
		tot = 0;
		input(str);

		if (strcmp(str, "end") == 0)
		{
			break;
		}
		len = strlen(str);
		//숫자부분 계산함수
		tot=calnum(str, len);

		output(str, tot);
	}

	return 0;
}

void input(char *sp)
{
	printf("# 문장을 입력하시오 : ");
	scanf("%s", sp);
	myflush();
}

void myflush()
{
	while (getchar() != '\n') {
		;
	}
}

int calnum(char* sp, int len)
{
	int i, j, sum[100] = { 0 }, tot=0;

		for (i = 0; i < len; i++)
		{

			if (48 <= sp[i] && sp[i] <= 57) // 48<=sp[j]<=57 이면 숫자
			{
				j = 1;
				sum[i] = (sp[i]-'0');
				while (48 <= sp[i + j] && sp[i + j] <= 57)
				{
					if (48 <= sp[i + j] && sp[i + j] <= 57) //다음 배열도 숫자
					j++;
				}//j=2
				sum[i] *= pow(10, j-1); //자리수 부여하기
			}
		}

		for (i = 0; i < 100; i++) //sum배열의 요소의 총합
		{
			tot += sum[i];
		}
	
	return tot;
}

void output(char* sp, int tot)
{
	printf("  \"%s\" 내의 총 숫자는 [%d]입니다.\n\n", sp, tot);
}