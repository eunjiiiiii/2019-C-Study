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
		printf("* ����� �ڵ带 �Է��Ͻÿ�(1:������/2:�����/3:������) : ");
		res = scanf("%d", &code);
		myflush();
		if (res == 1 && code <= 3 && 1 <= code)
		{
			break;
		}
		printf("* �߸��Է��ϼ̽��ϴ�. �ٽ��Է����ּ���.\n");
	}

	return code;
}

int inputUse()
{
	int use, res;

	while (1)
	{
		printf("* ��뷮�� �Է��Ͻÿ�(ton����) : ");
		res = scanf("%d", &use);
		myflush();
		if (res == 1)
		{
			break;
		}
		printf("* �߸��Է��ϼ̽��ϴ�. �ٽ��Է����ּ���.\n");
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
	if (code == 1) //������ �����
	{
		fee = 50*use;
	}
	else if (code == 2) //����� �����
	{
		fee = 45 * use;
	}
	else if (code == 3) //������ �����
	{
		fee = 30 * use;
	}

	fee *= 1.05; // �� �������
	return fee;
}

void output(int code, int use, int fee)
{
	if (code == 1)
	{
		printf("\n\n# ����� �ڵ� : %d(������)\n", code);
	}
	else if (code == 2)
	{
		printf("\n\n# ����� �ڵ� : %d(�����)\n", code);
	}
	else if (code == 3)
	{
		printf("\n\n# ����� �ڵ� : %d(������)\n", code);
	}

	printf("# ��뷮 : %d ton\n", use);
	printf("# �Ѽ������ : %d��\n", fee);
}