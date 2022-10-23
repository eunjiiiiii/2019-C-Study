#pragma warning (disable:4996)
#include<stdio.h>


void swap(int* (ap), int size);

int main()
{
	int i=0, res, size;
	int a[] = {1,2,3,4,5};

	size = sizeof(a) / sizeof(a[0]);

	printf("처음 배열에 저장된 값 : ");
	for (i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	swap(a, size);
	return 0;
}

void swap(int *(ap), int size)
{
	int i, temp;
	printf("바뀐 배열에 저장된 값 :");
	for (i = 0; i < (size/2); i++)
	{
		temp = ap[i];
		ap[i] = ap[size - i - 1];
		ap[size - i - 1] = temp;
	}
	for (i = 0; i < size; i++)
	{
		printf("%d ", ap[i]);
	}
	return;
}

