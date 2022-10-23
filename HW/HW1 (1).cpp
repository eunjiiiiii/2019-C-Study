#include <stdio.h>

void printAge(int age);
void printHeight(double height);


int main()
{
	char name[20] = "김은지";
	int age = 21;
	double height = 156.7;

	printf("성명 : %s\n", name);
	printAge(age);
	printHeight(height);


	return 0;
}

void printAge(int age)
{
	printf("나이 : %d\n", age);
}

void printHeight(double height)
{
	printf("키 : %f", height);
}