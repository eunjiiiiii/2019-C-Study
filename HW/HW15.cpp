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

	weight = inputWeight(); //입력 받는 부분
	height = inputHeight();

	BMI = calBMI(weight, height); //BMI 계산 하는 부분

	print(BMI); //출력 하는 부분

	return 0;
}

double inputWeight() //입력
{
	double w;
	printf("몸무게를 입력하세요(kg) : ");
	scanf("%lf", &w);
	return w;

}
double inputHeight() //입력
{
	double h;
	printf("키를 입력하세요(m) : ");
	scanf("%lf", &h);
	return h;
}

double calBMI(double w, double h) //bmi계산
{
	double bmi;
	bmi = w / pow(h, 2);
	return bmi;

}

void print(double bmi) //출력
{
	if (bmi < 18.5)
		printf("당신의 BMI는 %.1f으로 저체중입니다", bmi);
	else if (bmi < 25.0)
		printf("당신의 BMI는 %.1f으로 정상체중입니다", bmi);
	else if (bmi < 30.0)
		printf("당신의 BMI는 %.1f으로 과체중입니다", bmi);
	else if (bmi < 40.0)
		printf("당신의 BMI는 %.1f으로 비만입니다", bmi);
	else
		printf("당신의 BMI는 %.1f으로 고도비만입니다", bmi);

	return;
}