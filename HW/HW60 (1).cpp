#pragma warning(disable:4996)
#include<stdio.h>
#include<math.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define RESIDENT_NUMBER_LENGTH  13 /* 주민등록번호 길이*/
int availabilityCheck(char* resident_number);
int checkLengthCharacter(char* resident_number);
int checkDate(char* resident_number);
int checkIdentification(char* resident_number);
int checkGender(char* resident_number);
int checkYear(int year);
int createYear(char* resident_number);
int createMonth(char* resident_number);
int createDay(char* resident_number);


int main()
{
	/* 테스트할 주민등록번호 저장 배열*/
	char resident_number[][20] = { "0402291000008", "870401102321", "00031541949179",
		"0003154194917", "801203#201122", "7804155328845", "7804150328840",
		"9612241068382", "9902292194322", "0230174326176", "8811391042219",
		"8100122042213", "8112002042213", "9210101069415", "0802294012345",
"8806311069417","8807311069418"};
	int i, count;
	/* 검사할 주민등록번호의 개수 계산*/
	count = sizeof(resident_number) / sizeof(resident_number[0]);

	for (i = 0; i < count; i++) /* 주민등록번호 유효성 검사를 반복적으로 수행 함*/
	{
		if (availabilityCheck(resident_number[i]) == TRUE)
		{
			printf("(+) 주민번호%s는(은) 유효한 번호입니다.\n", resident_number[i]);
		}
		else
		{
			printf("(-) 주민번호%s는(은) 유효하지 않은 번호입니다.\n", resident_number[i]);
		}
	}
	return 0;
}
/*----------------------------------------------------------------
  availabilityCheck()함수: 주민등록번호 유효성 검사 함수
  전달인자: 유효성 검사할 주민등록번호(문자열)
  리턴값: 유효하면TRUE, 유효하지 않으면FALSE 리턴
------------------------------------------------------------------*/
int availabilityCheck(char* resident_number)
{
	int year, month, day;
	int leapOrNormal;
	year = createYear(resident_number);
	month = createMonth(resident_number);
	day = createDay(resident_number);

	if (checkLengthCharacter(resident_number) == TRUE)
	{
		if (checkDate(resident_number) == TRUE)
		{
			if (checkGender(resident_number) == TRUE)
			{
				if (checkIdentification(resident_number) == TRUE)
				{
					return 1;
				}
			}
		}
	}
	else
		return 0;

}
/*-------------------------------------------------------------------------
  checkLengthCharacter()함수: 주민등록번호 길이 및 문자 유효성검사 함수
  전달인자: 검사할 주민등록번호(문자열)
  리턴값: 주민등록번호의 길이가 맞고 숫자문자로만 구성되어 있으면TRUE,
		   길이가 짧거나 길고, 숫자 문자가 아닌 문자가 섞여 있으면FALSE 리턴
--------------------------------------------------------------------------*/
int checkLengthCharacter(char* resident_number)
{
	int i, size=0, cnt=0;
	for (i = 0; i < 20; i++)
	{
		if (resident_number[i] != 0)
		{
			size++;
		}
		if (48 <= resident_number[i] && resident_number[i] <= 57)
		{
			cnt++;
		}
	}

	if (size == cnt)
		return 1;
	else
		return 0;
}
/*----------------------------------------------------------------
  checkDate()함수: 첫6자리(연,월,일)의 유효성 검사 함수
  전달인자: 유효성 검사할 주민등록번호(문자열)
  리턴값: 유효한 날짜이면TRUE, 유효하지 않은 날짜이면FALSE 리턴
------------------------------------------------------------------*/
int checkDate(char* resident_number)
{
	int year, month, day;
	int leapOrNormal;
	year = createYear(resident_number);
	month = createMonth(resident_number);
	day = createDay(resident_number);

	if (year < 1900)
		return 0;

	if (month > 12 || month < 1) {
		return 0;
	}
	//윤평년일때 2월 day수 검사
	leapOrNormal = checkYear(year);
	if (month == 2 && 0 < day && day <= 29)
	{
		if (leapOrNormal == 0) //평년
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
/*----------------------------------------------------------------------
  checkGender()함수: 7번째 자리의 성별식별번호 유효성 검사함수
  전달인자: 유효성 검사할 주민등록번호(문자열)
  리턴값: 성별식별번호가'1'~'4'이면TRUE, 그 외 숫자 문자이면FALSE 리턴
-----------------------------------------------------------------------*/
int checkGender(char* resident_number)
{
	int year, month, day;
	char gender;
	year = createYear(resident_number);
	month = createMonth(resident_number);
	day = createDay(resident_number);
	gender = resident_number[6];

	if (1900 <= year && year < 2000)
	{
		if (gender == '1' || gender == '2')
		{
			return 1;
		}
		else return 0;
	}
	else if (2000 <= year && year < 2100)
	{
		if (gender == '3' || gender == '4')
		{
			return 1;
		}
		else return 0;
	}
}
/*------------------------------------------------------------------------
  checkIdentification()함수: 주민등록번호 끝자리(인식자) 유효성 검사 함수
  전달인자: 유효성 검사할 주민등록번호(문자열)
  리턴값: 유효한 인식자이면TRUE, 유효하지 않은 인식자이면 FALSE 리턴
-------------------------------------------------------------------------*/
int checkIdentification(char* resident_number)
{
	int year, month, day;
	int i, sum=0, len=0;
	year = createYear(resident_number);
	month = createMonth(resident_number);
	day = createDay(resident_number);

	len=strlen(resident_number);

	for (i = 0; i <= (len-2); i++)
	{
		sum += (resident_number[i]-'0');
	}

	if (sum % 10 == (resident_number[len-1]-'0'))
	{
		return 1;
	}
	else
		return 0;
}
/*----------------------------------------------------------------
 checkYear ()함수: 년도의 윤,평년 여부 검사
  전달인자: 윤,평년 검사할 년도
  리턴값: 윤년이면 TRUE(1), 평년이면FALSE(0) 리턴
------------------------------------------------------------------*/
int checkYear(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				return 1;
			else
				return 0;
		}
		else
			return 1;
	}
	else
		return 0;
}

//--------------------------------------
//연, 월, 일 int형 데이터로 생성
//--------------------------------------

int createYear(char*resident_number)
{

	int i, year = 0;
	//연
	if (resident_number[6] == '1' || resident_number[6] == '2') {
		year = 1900;
	}
	else if (resident_number[6] =='3' || resident_number[6] == '4') {
		year = 2000;
	}
	for (i = 0; i < 2; i++) {
		year += (resident_number[i] - '0') * pow(10, 1 - i);
	}

	return year;
}

int createMonth(char* resident_number)
{
	int i, month = 0;
	for (i = 2; i < 4; i++)
	{
		month += (resident_number[i] - '0') * pow(10, 3 - i);
	}
	return month;
}

int createDay(char* resident_number)
{
	int i, day = 0;
	for (i = 4; i < 6; i++)
	{
		day += (resident_number[i] - '0') * pow(10, 5 - i);
	}
	return day;
}