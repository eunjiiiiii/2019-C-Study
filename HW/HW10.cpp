#pragma warning(disable: 4996)
#include <stdio.h>

int main()
{
	int n1, n2, res1;
	double res2; //���������� ���� �� ����,�E��,������ ��� ���� �׻� ������ ��������, �������� �׻� ������ ������ �����Ƿ� res���� ����.
	printf("�� ���� ������ �Է��Ͻÿ� : ");
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

/* res ���� �� �� ���
int main()
{
	int n1, n2;
	printf("�� ���� ������ �Է��Ͻÿ� : ");
	scanf("%d %d", &n1, &n2);

	printf("%d+%d = %d\n", n1, n2, n1 + n2);
	printf("%d-%d = %d\n", n1, n2, n1 - n2);
	printf("%d*%d = %d\n", n1, n2, n1 * n2);
	printf("%d/%d = %.2f\n", n1, n2, double(n1) / n2);

	return 0;
}

*/