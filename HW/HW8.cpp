#pragma warning(disable : 4996)
#include <stdio.h>

int main()
{
	int score_s, score_l, score_e, total;
	double average;

	printf("역사, 문학, 예능 점수를 입력하세요 : ");
	scanf("%d %d %d", &score_s, &score_l, &score_e);

	total = score_s + score_l + score_e;
	average = total / 3.0;

	printf("총점은 %d 이고 평균은 %.2f 입니다.", total, average);
	
	return 0;
}