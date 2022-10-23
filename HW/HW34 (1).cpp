#pragma warning (disable : 4996)
#include <stdio.h>

int inputCode();
int inputUse();
void myflush();
int calcFee(int code, int use);
void output(int code, int use, int fee);

int main()
{
	int code, fee, use;

	code = inputCode();
	use = inputUse();

	fee = calcFee(code, use);

	output(code, use, fee);

	return 0;
}

int inputCode()
{
	int code, res;

	while (1)
	{
		printf("* 사용자 코드를 입력하시오(1:가정용/2:상업용/3:공업용) : ");
		res = scanf("%d", &code);
		myflush();
		if (res == 1 && code <= 3 && 1 <= code)
		{
			break;
		}
		printf("* 잘못입력하셨습니다. 다시입력해주세요.\n");
	}

	return code;
}

int inputUse()
{
	int use, res;

	while (1)
	{
		printf("* 사용량을 입력하시오(ton단위) : ");
		res = scanf("%d", &use);
		myflush();
		if (res == 1)
		{
			break;
		}
		printf("* 잘못입력하셨습니다. 다시입력해주세요.\n");
	}
	

	return use;
}

void myflush()
{
	while (getchar() != '\n')
	{
		;
	}
}

int calcFee(int code, int use)
{
	int fee;
	if (code == 1) //가정용 사용요금
	{
		fee = 50*use;
	}
	else if (code == 2) //상업용 사용요금
	{
		fee = 45 * use;
	}
	else if (code == 3) //공업용 사용요금
	{
		fee = 30 * use;
	}

	fee *= 1.05; // 총 수도요금
	return fee;
}

void output(int code, int use, int fee)
{
	if (code == 1)
	{
		printf("\n\n# 사용자 코드 : %d(가정용)\n", code);
	}
	else if (code == 2)
	{
		printf("\n\n# 사용자 코드 : %d(상업용)\n", code);
	}
	else if (code == 3)
	{
		printf("\n\n# 사용자 코드 : %d(공업용)\n", code);
	}

	printf("# 사용량 : %d ton\n", use);
	printf("# 총수도요금 : %d원\n", fee);
}