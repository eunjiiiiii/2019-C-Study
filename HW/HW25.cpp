#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int input();
int random(int);
void output(int i);
void myflush();


int main()
{
	int n=0, num, n_, min, max;
	int i;

	srand((unsigned int)time(NULL)); //rand()�Լ��� ����(seed)�� time ���� ����
	num = random(100)+1;	//��������
	//printf("%d\n", num);
	i = 0;

	n = input();
	if (num > 50)
	{
		n_ = 100;
		min=n, max = 100;
		printf("%d ���ٴ� ũ�� %d ���ٴ� �۽��ϴ�.\n", n, max);
	}
	else
	{
		n_ = 0;
		min = 0, max=n;
		printf("%d ���ٴ� ũ�� %d ���ٴ� �۽��ϴ�.\n", min, n);

	}
	
	do
	{
		n = 0;
		n = input(); //����� �Է¹���


		if (n_ < n)
		{
			if (n_ < num && num < n)
			{
				if (n_ < min)
				{
					printf("%d ���ٴ� ũ�� %d ���ٴ� �۽��ϴ�.\n", min, n);
					max = n;
					n_ = n;
				}
				else if (max < n)
				{
					printf("%d ���ٴ� ũ�� %d ���ٴ� �۽��ϴ�.\n", min, max);
				}
				else 
				printf("%d ���ٴ� ũ�� %d ���ٴ� �۽��ϴ�.\n", n_, n);
				min = n_, max = n;
				n_ = n;
			}

			else if(n<num)
			{
				printf("%d ���ٴ� ũ�� %d ���ٴ� �۽��ϴ�.\n", n, max);
				min = n;
				n_ = n;
			}
			
			else if (num < n_)
			{
				printf("%d ���ٴ� ũ�� %d ���ٴ� �۽��ϴ�.\n", min, max);
			}
		}
		
		else
		{
			if (n < num && num < n_) //n<num<n_
			{
				if (n < min)
				{
					printf("%d ���ٴ� ũ�� %d ���ٴ� �۽��ϴ�.\n", min, max);
				}
				else if (max < n_)
				{
					printf("%d ���ٴ� ũ�� %d ���ٴ� �۽��ϴ�.\n", n, max);
					min = n;
					n_ = n;
				}
				else
					printf("%d ���ٴ� ũ�� %d ���ٴ� �۽��ϴ�.\n", n, n_);
				min = n, max = n_;
				n_ = n;
			}

			else if (n > num)
			{
				printf("%d ���ٴ� ũ�� %d ���ٴ� �۽��ϴ�.\n", min, n);
				max = n;
				n_ = n;
			}
			
		}
		
		i++;
	} while (n != num);

	output(i+1);


	return 0;
}


int input()
{
	int n=0, res;

	while (1)
	{
		printf("#���ڸ� �Է��Ͻÿ� : ");
		res=scanf("%d", &n);
		if (res == 1)
		{
			break;
		}
		myflush();
	}
		return n;
}

int random(int n)
{
	int res;
	res = rand() % n;
	return res;

}

void output(int i)
{
	printf("���~�¾Ҵ�~~~ ��ī��ī~~ %d ��° ���� ���߼̽��ϴ�.", i);
}

void myflush()
{
	while(getchar()!='\n')
	{
		;
	}

}