#include <stdio.h>

int main()
{
	int sec = 54321;
	int hour, minute, tsec;

	hour = sec / 3600;
	minute = (sec % 3600) / 60;
	tsec = (sec % 60);

	printf("54321�ʴ� %d�ð� %d�� %d�� �Դϴ�.", hour, minute, tsec);

	return 0;
}