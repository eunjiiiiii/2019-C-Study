#include <stdio.h>

void printAge(int age);
void printHeight(double height);


int main()
{
	char name[20] = "������";
	int age = 21;
	double height = 156.7;

	printf("���� : %s\n", name);
	printAge(age);
	printHeight(height);


	return 0;
}

void printAge(int age)
{
	printf("���� : %d\n", age);
}

void printHeight(double height)
{
	printf("Ű : %f", height);
}