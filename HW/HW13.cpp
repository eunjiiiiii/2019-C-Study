#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>

int main()
{
	char firstname[20];
	char lastname[20];
	int flen, llen;
	printf("#성을 입력하시오 : ");
	scanf("%s", firstname);
	printf("#이름을 입력하시오 : ");
	scanf("%s", lastname);

	flen = strlen(firstname);
	llen = strlen(lastname);
	
	printf("%s %s\n", firstname, lastname);
	printf("%*d %*d", flen, flen, llen, llen);

	return 0;
}

