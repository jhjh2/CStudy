/* Fibonacci 수열 구하기 with recursion */

// fibo(n) : 피보나치 수열의 n번째 숫자를 반환
// 1, 1, 2, 3, 5, 8, ...

#include <stdio.h>

int fibo(int n)
{
	// exit condition
	if (n == 1 || n == 2)
	{
		return 1;
	}

	// recursive condition
	return fibo(n - 1) + fibo(n - 2);
}

int main(void)
{
	printf("fibo(6) = %d\n", fibo(6));
	printf("fibo(10) = %d\n", fibo(10));
	return 0;
}