#pragma warning(disable : 4996)
#include <stdio.h>

void output(int alp, int num, int blank, int etc);

int main()
{
	char ch;
	int alp=0, num=0, blank=0, etc=0;

	printf("# ���� ������ �Է��Ͻÿ� : \n");
	while ((ch = getchar()) != EOF)
	{
		if ('A' <= ch && ch <= 'z')
		{
			if ('Z' < ch && ch < 'a') //�߰� ��Ÿ����
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
	printf("* ������ ��ҹ��� ���� : %d��\n", alp);
	printf("* ���ڹ��� ���� : %d��\n", num);
	printf("* ���鹮��(space, tab, enter) ���� : %d��\n", blank);
	printf("* �� �� ��Ÿ���� ���� : %d��\n", etc);
}