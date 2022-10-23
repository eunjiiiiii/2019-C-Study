#pragma warning(disable : 4996)
#include <stdio.h>
#include <math.h>

double inputWeight();
double inputHeight();
double calBMI(double w, double h);
void print(double bmi);

int main()
{
	double weight, height, BMI;

	weight = inputWeight(); //�Է� �޴� �κ�
	height = inputHeight();

	BMI = calBMI(weight, height); //BMI ��� �ϴ� �κ�

	print(BMI); //��� �ϴ� �κ�

	return 0;
}

double inputWeight() //�Է�
{
	double w;
	printf("�����Ը� �Է��ϼ���(kg) : ");
	scanf("%lf", &w);
	return w;

}
double inputHeight() //�Է�
{
	double h;
	printf("Ű�� �Է��ϼ���(m) : ");
	scanf("%lf", &h);
	return h;
}

double calBMI(double w, double h) //bmi���
{
	double bmi;
	bmi = w / pow(h, 2);
	return bmi;

}

void print(double bmi) //���
{
	if (bmi < 18.5)
		printf("����� BMI�� %.1f���� ��ü���Դϴ�", bmi);
	else if (bmi < 25.0)
		printf("����� BMI�� %.1f���� ����ü���Դϴ�", bmi);
	else if (bmi < 30.0)
		printf("����� BMI�� %.1f���� ��ü���Դϴ�", bmi);
	else if (bmi < 40.0)
		printf("����� BMI�� %.1f���� ���Դϴ�", bmi);
	else
		printf("����� BMI�� %.1f���� �����Դϴ�", bmi);

	return;
}