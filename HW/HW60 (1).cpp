#pragma warning(disable:4996)
#include<stdio.h>
#include<math.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define RESIDENT_NUMBER_LENGTH  13 /* �ֹε�Ϲ�ȣ ����*/
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
	/* �׽�Ʈ�� �ֹε�Ϲ�ȣ ���� �迭*/
	char resident_number[][20] = { "0402291000008", "870401102321", "00031541949179",
		"0003154194917", "801203#201122", "7804155328845", "7804150328840",
		"9612241068382", "9902292194322", "0230174326176", "8811391042219",
		"8100122042213", "8112002042213", "9210101069415", "0802294012345",
"8806311069417","8807311069418"};
	int i, count;
	/* �˻��� �ֹε�Ϲ�ȣ�� ���� ���*/
	count = sizeof(resident_number) / sizeof(resident_number[0]);

	for (i = 0; i < count; i++) /* �ֹε�Ϲ�ȣ ��ȿ�� �˻縦 �ݺ������� ���� ��*/
	{
		if (availabilityCheck(resident_number[i]) == TRUE)
		{
			printf("(+) �ֹι�ȣ%s��(��) ��ȿ�� ��ȣ�Դϴ�.\n", resident_number[i]);
		}
		else
		{
			printf("(-) �ֹι�ȣ%s��(��) ��ȿ���� ���� ��ȣ�Դϴ�.\n", resident_number[i]);
		}
	}
	return 0;
}
/*----------------------------------------------------------------
  availabilityCheck()�Լ�: �ֹε�Ϲ�ȣ ��ȿ�� �˻� �Լ�
  ��������: ��ȿ�� �˻��� �ֹε�Ϲ�ȣ(���ڿ�)
  ���ϰ�: ��ȿ�ϸ�TRUE, ��ȿ���� ������FALSE ����
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
  checkLengthCharacter()�Լ�: �ֹε�Ϲ�ȣ ���� �� ���� ��ȿ���˻� �Լ�
  ��������: �˻��� �ֹε�Ϲ�ȣ(���ڿ�)
  ���ϰ�: �ֹε�Ϲ�ȣ�� ���̰� �°� ���ڹ��ڷθ� �����Ǿ� ������TRUE,
		   ���̰� ª�ų� ���, ���� ���ڰ� �ƴ� ���ڰ� ���� ������FALSE ����
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
  checkDate()�Լ�: ù6�ڸ�(��,��,��)�� ��ȿ�� �˻� �Լ�
  ��������: ��ȿ�� �˻��� �ֹε�Ϲ�ȣ(���ڿ�)
  ���ϰ�: ��ȿ�� ��¥�̸�TRUE, ��ȿ���� ���� ��¥�̸�FALSE ����
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
	//������϶� 2�� day�� �˻�
	leapOrNormal = checkYear(year);
	if (month == 2 && 0 < day && day <= 29)
	{
		if (leapOrNormal == 0) //���
		{
			if (day > 28)
				return 0;
		}
		else //����
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
  checkGender()�Լ�: 7��° �ڸ��� �����ĺ���ȣ ��ȿ�� �˻��Լ�
  ��������: ��ȿ�� �˻��� �ֹε�Ϲ�ȣ(���ڿ�)
  ���ϰ�: �����ĺ���ȣ��'1'~'4'�̸�TRUE, �� �� ���� �����̸�FALSE ����
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
  checkIdentification()�Լ�: �ֹε�Ϲ�ȣ ���ڸ�(�ν���) ��ȿ�� �˻� �Լ�
  ��������: ��ȿ�� �˻��� �ֹε�Ϲ�ȣ(���ڿ�)
  ���ϰ�: ��ȿ�� �ν����̸�TRUE, ��ȿ���� ���� �ν����̸� FALSE ����
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
 checkYear ()�Լ�: �⵵�� ��,��� ���� �˻�
  ��������: ��,��� �˻��� �⵵
  ���ϰ�: �����̸� TRUE(1), ����̸�FALSE(0) ����
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
//��, ��, �� int�� �����ͷ� ����
//--------------------------------------

int createYear(char*resident_number)
{

	int i, year = 0;
	//��
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