#pragma warning (disable:4996)
#include<stdio.h>

void myflush();
void sort(int* ap, int dataN);

int main()
{

	int tc;
	int i, count = 0;
	int ary[11];
	freopen("c:\\data\\hw52_sortData.txt", "rt", stdin);
	scanf("%d", &tc);
	printf("tc = %d\n", tc); //3 저장

	for (i = 0; i < tc; i++)
	{
		scanf("%d", ary[i]);
		while (ary[i] == 0)
		{
			count++; //데이터개수 세기
		}
		sort(ary, count);
	}

	/*		TC1건 읽어서 배열에 저장하기
		sort()함수를 호출해서 정렬하기
		배열의 내용 출력하기*/



	return 0;
}

void myflush()
{
	while (getchar() != '\n') {
		;
	}
}

void sort(int* ap, int dataN)
{
	int i, j, tmp;
	for (i = 0; i < dataN; i++)
	{
		for (j = i + 1; j < dataN; j++)
		{
			if (ap[i] > ap[j])
			{
				tmp = ap[i];
				ap[i] = ap[j];
				ap[j] = tmp;
			}
		}
	}
}

void output(int* ap, int* sp, int dataN)
{
	int i;
	printf("# 소트 전 데이터 : ");
	for (i = 0; i < dataN; i++)
	{
		printf("%d ", *(ap + i));
	}
	printf("# 소트 후 데이터 : ");
	for (i = 0; i < dataN; i++)
	{
		printf("%d ", *(sp + i));
	}
}