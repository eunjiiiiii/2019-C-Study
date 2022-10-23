#pragma warning (disable:4996)
#include <stdio.h>

int main()
{
	int ASCIIcode;
	printf("ASCII code값을 입력하시오 : ");
	scanf("%d", &ASCIIcode);

	printf("%d은 '%c'의 ASCII code 입니다.", ASCIIcode, ASCIIcode);



	return 0;
}