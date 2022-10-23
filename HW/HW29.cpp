#pragma warning (disable : 4996)
#include <stdio.h>

void myflush();
unsigned int inputUInt();
int transNumber(int num);


int main()
{
	unsigned int P1,P2,num, calNum;
	int N, calN=0, i=0;
	printf("���� ��(P1)�� �� ��(P2)�� �Է��Ͻÿ�. (��, 100<=P1, P2<=10000)\n");
	printf("���� ��(P1) : ");
	P1 = inputUInt();
	printf("�� ��(P2) : ");
	P2 = inputUInt();
	printf("������(N) : ");
	scanf("%d", &N);
	
	num = P1;
	printf("�������� %d�� ���� ���\n", N);

	while (num <= P2)
	{
		calN = 0;
		calNum = num; //calNum�� num�� ����
		while (transNumber(calNum) >= 10) //���ڸ����϶� ��������
		{
			calNum=transNumber(calNum);
			calN++; //������ count
		}
		
		if (N == (calN + 1)) //�������� N �̸�
		{
			printf("%d\n", num);
			i++; //������ N�� ������ ����
		}
		num++;
	}

	printf("�� ���� : %d��", i);
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

		//õ�� �ڸ��� ���
		if (1000 <= num && num < 9999)
		{
			thousand = num / 1000;
			hundred = (num % 1000) / 100;
			ten = (num % 100) / 10;
			unit = num % 10;

			num = thousand * hundred * ten * unit;
		
		}
		//���� �ڸ��� ���
		else if (100 <= num && num < 1000)
		{
			hundred = num / 100;
			ten = (num % 100) / 10;
			unit = num % 10;

			num = hundred * ten * unit;
	
		}

		//���� �ڸ��� ���
		else if (10 <= num && num < 100)
		{
			ten = num / 10;
			unit = num % 10;

			num = ten * unit;
		}

	return num;
}