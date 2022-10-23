#pragma warning (disable:4996)
#include<stdio.h>

int main()
{
	int ary[] = { 2,8,15,1,8,10,5,19,19,3,5,6,6,2,8,2,12,16,3,8,17,
	12,5,3,14,13,3,2,17,19,16,8,7,12,19,10,13,8,20,
	16,15,4,12,3,14,14,5,2,12,14,9,8,5,3,18,18,20,4 };
	int size, i, j;
	int count[20] = { 0 };

	//int sum = 0; 개수 확인

	size = sizeof(ary) / sizeof(ary[0]);

	for (i = 0; i < size; i++) //방 인덱스는 0부터 19
	{
		for (j = 1; j <= 20; j++) //숫자
		{
			if (ary[i] == j) //숫자는 1부터 20이므로
			{
				count[j-1] += 1;
			}
		}

	}

	for (i = 0; i < 20; i++){
		printf("%2d - %d개\n", i + 1, count[i]);
		//sum += count[i]; 개수 맞는지 확인해보려고 잠시 넣어놨습니다.
	}
	//printf("size %d sum %d", size, sum); 개수확인 출력코드
	return 0;
}