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

	srand((unsigned int)time(NULL)); //rand()함수의 씨앗(seed)를 time 으로 설정
	num = random(100)+1;	//난수생성
	//printf("%d\n", num);
	i = 0;

	n = input();
	if (num > 50)
	{
		n_ = 100;
		min=n, max = 100;
		printf("%d 보다는 크고 %d 보다는 작습니다.\n", n, max);
	}
	else
	{
		n_ = 0;
		min = 0, max=n;
		printf("%d 보다는 크고 %d 보다는 작습니다.\n", min, n);

	}
	
	do
	{
		n = 0;
		n = input(); //사용자 입력받음


		if (n_ < n)
		{
			if (n_ < num && num < n)
			{
				if (n_ < min)
				{
					printf("%d 보다는 크고 %d 보다는 작습니다.\n", min, n);
					max = n;
					n_ = n;
				}
				else if (max < n)
				{
					printf("%d 보다는 크고 %d 보다는 작습니다.\n", min, max);
				}
				else 
				printf("%d 보다는 크고 %d 보다는 작습니다.\n", n_, n);
				min = n_, max = n;
				n_ = n;
			}

			else if(n<num)
			{
				printf("%d 보다는 크고 %d 보다는 작습니다.\n", n, max);
				min = n;
				n_ = n;
			}
			
			else if (num < n_)
			{
				printf("%d 보다는 크고 %d 보다는 작습니다.\n", min, max);
			}
		}
		
		else
		{
			if (n < num && num < n_) //n<num<n_
			{
				if (n < min)
				{
					printf("%d 보다는 크고 %d 보다는 작습니다.\n", min, max);
				}
				else if (max < n_)
				{
					printf("%d 보다는 크고 %d 보다는 작습니다.\n", n, max);
					min = n;
					n_ = n;
				}
				else
					printf("%d 보다는 크고 %d 보다는 작습니다.\n", n, n_);
				min = n, max = n_;
				n_ = n;
			}

			else if (n > num)
			{
				printf("%d 보다는 크고 %d 보다는 작습니다.\n", min, n);
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
		printf("#숫자를 입력하시오 : ");
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
	printf("우와~맞았당~~~ 추카추카~~ %d 번째 만에 맞추셨습니다.", i);
}

void myflush()
{
	while(getchar()!='\n')
	{
		;
	}

}