#include <stdio.h>

int main(void)
{
	printf("Hello World\n");

	// ++
	int a = 10;
	printf("%d\n", a);
	a++;
	printf("%d\n", a);

	int b = 20;
	printf("%d\n", ++b);
	printf("%d\n", b++);
	printf("%d\n", b);

	// 반복문
	// for, while, do while

	// for (선언; 조건; 증감) { }
	for (int i = 1; i <= 10; i++)
	{
		printf("Hello World %d\n", i);
	}

	// while (조건) { }
	int i = 1;
	while (i <= 10)
	{
		printf("Hello world %d\n", i++);
	}

	// do { } while (조건)
	int k = 1;
	do
	{
		printf("Hello world %2d\n", k++);
	} while (k <= 10);

	// 2중 반복문
	for (int i = 1; i <= 3; i++)
	{
		printf("first loop : %d\n", i);

		for (int i = 1; i <= 5; i++)
		{
			printf("second loop : %d\n", i);
		}

	}

	// 구구단
	for (int i = 2; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			printf("%d * %d = %2d\n", i, j, i * j);
		}
	}

	/*
	*
	**
	***
	****
	*****
	*/
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	/*
	ssss*
	sss**
	ss***
	s****
	*****
	*/
	for (int i = 0; i < 5; i++)
	{
		for (int j = i; j < 5 - 1; j++)
		{
			printf("s");
		}
		for (int k = 0; k <= i; k++)
		{
			printf("*");
		}
		printf("\n");
	}

	// 피라미드
	int floor;
	printf("how many floors? : ");
	scanf_s("%d", &floor);
	for (int i = 0; i < floor; i++)
	{
		for (int j = i; j < floor - 1; j++)
		{
			printf("s");
		}

		for (int k = 0; k < 2 * i + 1; k++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}