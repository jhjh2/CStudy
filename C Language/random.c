#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	printf("난수 초기화 이전..\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", rand() % 10); // 0 ~ 9 사이의 정수
	}

	printf("\n");

	srand(time(NULL)); // 난수 초기화
	printf("난수 초기화 이후..\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", rand() % 10); // 0 ~ 9
	}

	int num = rand() % 3; // 0 ~ 2
	int num2 = rand() % 3 + 1; // 1 ~ 3
	float fnum = (float)(rand() % 45) / 10; // 0 ~ 4.5 사이의 실수

	return 0;
}