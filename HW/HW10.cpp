#pragma warning(disable: 4996)
#include <stdio.h>

int main()
{
	int n1, n2, res1;
	double res2; //정수끼리의 연산 중 덧셈,뺼셈,곱셈은 결과 값이 항상 정수가 나오지만, 나눗셈은 항상 정수가 나오지 않으므로 res변수 나눔.
	printf("두 개의 정수를 입력하시오 : ");
	scanf("%d %d", &n1, &n2);
	
	res1 = n1 + n2;
	printf("%d+%d = %d\n", n1, n2, res1);
	res1 = n1 - n2;
	printf("%d-%d = %d\n", n1, n2, res1);
	res1 = n1 * n2;
	printf("%d*%d = %d\n", n1, n2, res1);
	res2 = double(n1) / n2;
	printf("%d/%d = %.2f\n", n1, n2, res2);

	return 0;
}

/* res 변수 안 쓴 경우
int main()
{
	int n1, n2;
	printf("두 개의 정수를 입력하시오 : ");
	scanf("%d %d", &n1, &n2);

	printf("%d+%d = %d\n", n1, n2, n1 + n2);
	printf("%d-%d = %d\n", n1, n2, n1 - n2);
	printf("%d*%d = %d\n", n1, n2, n1 * n2);
	printf("%d/%d = %.2f\n", n1, n2, double(n1) / n2);

	return 0;
}

*/