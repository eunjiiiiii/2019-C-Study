#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>

void myflush();

int main()
{
	char name[50];

	printf("�̸��� �Է��Ͻÿ� : ");
	fgets(name, sizeof(name), stdin);
	unsigned int len;
	len = strlen(name);
	name[len - 1] = '\0';

	printf("\"%s\"\n", name);
	printf("\"%20s\"\n", name);
	printf("\"%-20s\"\n", name);

	return 0;
}

void myflush()
{
	while (getchar() != '\n')
	{
		;
	}
}