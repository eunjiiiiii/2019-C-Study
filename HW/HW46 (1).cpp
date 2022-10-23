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

	while (1){ //�Է¹޴� �ݺ�loop
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

	printf("* �� �� ���� �Է��Ͻÿ� : ");
	res = scanf("%d %d %d", yp, mp, dp);
	myflush();
	return res;
}

int validateDate(int year, int month, int day)
{
	//0�� ����, 1�� ��
	int leapOrNormal;
	if (year < 1900)
		return 0;

	if (month > 12 || month < 1) {
		return 0;
	}
	//������϶� 2�� day�� �˻�
	leapOrNormal = checkYear(year);
	if (month == 2 && 0<day && day<=29)
	{
		if (leapOrNormal == 1) //���
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
	// 1.�⵵�� �� �� �� ���
	for (i = 1900; i < year; i++)
	{
		leapOrNormal = checkYear(i);
		if (leapOrNormal == 0) // ���� : 366��
		{
			totDay += 366;
		}

		else totDay += 365; //��� : 365��
	}
	// 2. ���� �� ���� ���
	for (i = 1; i < month; i++)
		totDay += dayOfMonth[i-1];

	//year�� �����̰� month�� 3�� �̻��̸� 2/29 �Ϸ�ġ �� ����
	leapOrNormal = checkYear(year);
	if (leapOrNormal == 0 && month >= 3) //����
		totDay++;

	// 3. �� �� ����
	totDay += day;

	return totDay;
}

int checkYear(int year) //���� : 0, ��� : 1
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
	printf("%6d�� %d�� %d���� ", year, month, day);
	
	switch (totDay % 7)
	{
	case 0: printf("�Ͽ��� �Դϴ�.\n"); break;
	case 1: printf("������ �Դϴ�.\n"); break;
	case 2: printf("ȭ���� �Դϴ�.\n"); break;
	case 3: printf("������ �Դϴ�.\n"); break;
	case 4: printf("����� �Դϴ�.\n"); break;
	case 5: printf("�ݿ��� �Դϴ�.\n"); break;
	case 6: printf("����� �Դϴ�.\n"); break;
	default:;
	}
}