#pragma warning (disable : 4996)
#include <stdio.h>

void myflush();
unsigned int inputUInt();
int transNumber(int num);


int main()
{
	unsigned int P1,P2,num, calNum;
	int N, calN=0, i=0;
	printf("시작 값(P1)과 끝 값(P2)를 입력하시오. (단, 100<=P1, P2<=10000)\n");
	printf("시작 값(P1) : ");
	P1 = inputUInt();
	printf("끝 값(P2) : ");
	P2 = inputUInt();
	printf("고집수(N) : ");
	scanf("%d", &N);
	
	num = P1;
	printf("고집수가 %d인 숫자 출력\n", N);

	while (num <= P2)
	{
		calN = 0;
		calNum = num; //calNum에 num값 복사
		while (transNumber(calNum) >= 10) //한자리수일때 빠져나옴
		{
			calNum=transNumber(calNum);
			calN++; //고집수 count
		}
		
		if (N == (calN + 1)) //고집수가 N 이면
		{
			printf("%d\n", num);
			i++; //고집수 N인 수들의 개수
		}
		num++;
	}

	printf("총 개수 : %d개", i);
	return 0;
}

unsigned int inputUInt()
{
	int res;
	unsigned int p;
	while (1)
	{
		res = scanf("%u", &p);
		myflush();
		if ((int)p > 0 && res == 1)
		{
			break;
		}
	}
	return p;
}

void myflush()
{
	while (getchar() != '\n');
	{
		;
	}
}

int transNumber(int num)
{
	int thousand, hundred, ten, unit;

		//천의 자리일 경우
		if (1000 <= num && num < 9999)
		{
			thousand = num / 1000;
			hundred = (num % 1000) / 100;
			ten = (num % 100) / 10;
			unit = num % 10;

			num = thousand * hundred * ten * unit;
		
		}
		//백의 자리일 경우
		else if (100 <= num && num < 1000)
		{
			hundred = num / 100;
			ten = (num % 100) / 10;
			unit = num % 10;

			num = hundred * ten * unit;
	
		}

		//십의 자리일 경우
		else if (10 <= num && num < 100)
		{
			ten = num / 10;
			unit = num % 10;

			num = ten * unit;
		}

	return num;
}