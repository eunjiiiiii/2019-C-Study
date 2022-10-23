#pragma warning(disable:4996)
#include <stdio.h>

int inputYYMMDD(int* yp, int* mp, int* dp);
int validateDate(int year, int month, int day);
void myflush();
int checkYear(int year);
int totalDay(int year, int month, int day);
void output(int year, int month, int day, int totDay);

int main()
{
	int year, month, day, res, totDay;

	while (1){ //입력받는 반복loop
		res=inputYYMMDD(&year, &month, &day);

		if (res == 3 && validateDate(year, month, day) != 0)
		{
			break;
		}
	
	}
	totDay = totalDay(year, month, day);

	output(year, month, day, totDay);

	return 0;
}

int inputYYMMDD(int *yp, int*mp, int*dp)
{
	int res;
	int year, month, day;

	printf("* 년 월 일을 입력하시오 : ");
	res = scanf("%d %d %d", yp, mp, dp);
	myflush();
	return res;
}

int validateDate(int year, int month, int day)
{
	//0이 거짓, 1이 참
	int leapOrNormal;
	if (year < 1900)
		return 0;

	if (month > 12 || month < 1) {
		return 0;
	}
	//윤평년일때 2월 day수 검사
	leapOrNormal = checkYear(year);
	if (month == 2 && 0<day && day<=29)
	{
		if (leapOrNormal == 1) //평년
		{
			if (day > 28)
				return 0;
		}
		else //윤년
			return 1;
	}
	if (month > 0 && day > 0)
	{
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day > 30)
				return 0;
			else
				return 1;
		}
		else
		{
			if (day > 31)
				return 0;
			else
				return 1;
		}
	}
	else
		return 0;
}

void myflush()
{
	while (getchar() != '\n'){
		;
	}
}

int totalDay(int year, int month, int day)
{
	int totDay=0, i, leapOrNormal;
	int dayOfMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	// 1.년도의 총 날 수 계산
	for (i = 1900; i < year; i++)
	{
		leapOrNormal = checkYear(i);
		if (leapOrNormal == 0) // 윤년 : 366일
		{
			totDay += 366;
		}

		else totDay += 365; //평년 : 365일
	}
	// 2. 월의 총 날수 계산
	for (i = 1; i < month; i++)
		totDay += dayOfMonth[i-1];

	//year가 윤년이고 month가 3월 이상이면 2/29 하루치 더 누적
	leapOrNormal = checkYear(year);
	if (leapOrNormal == 0 && month >= 3) //윤년
		totDay++;

	// 3. 일 수 누적
	totDay += day;

	return totDay;
}

int checkYear(int year) //윤년 : 0, 평년 : 1
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				return 0;
			else 
				return 1;
		}
		else 
			return 0;
	}
	else 
		return 1;
}

void output(int year, int month, int day, int totDay)
{
	printf("%6d년 %d월 %d일은 ", year, month, day);
	
	switch (totDay % 7)
	{
	case 0: printf("일요일 입니다.\n"); break;
	case 1: printf("월요일 입니다.\n"); break;
	case 2: printf("화요일 입니다.\n"); break;
	case 3: printf("수요일 입니다.\n"); break;
	case 4: printf("목요일 입니다.\n"); break;
	case 5: printf("금요일 입니다.\n"); break;
	case 6: printf("토요일 입니다.\n"); break;
	default:;
	}
}