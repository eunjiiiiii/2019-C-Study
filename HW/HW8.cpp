#pragma warning(disable : 4996)
#include <stdio.h>

int main()
{
	int score_s, score_l, score_e, total;
	double average;

	printf("����, ����, ���� ������ �Է��ϼ��� : ");
	scanf("%d %d %d", &score_s, &score_l, &score_e);

	total = score_s + score_l + score_e;
	average = total / 3.0;

	printf("������ %d �̰� ����� %.2f �Դϴ�.", total, average);
	
	return 0;
}