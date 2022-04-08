#include <stdio.h>

/* 거듭제곱 계산하기 */
// non-recursive
int calc_power(int x, int n)
{
	int result = 1;
	for (int i = 0; i < n; i++)
	{
		result *= x;
	}

	return result;
}

// recursive
// n이 0인 경우
// x^n = 1, 탈출조건
// n이 짝수인 경우
// x^n = (x^2)^(n/2)
// n이 홀수인 경우
// x^n = x*(x^2)^((n-1)/2)
int calc_power_by_recursion(int x, int n)
{
	// 탈출조건
	if (n == 0)
	{
		return 1;
	}

	// 재귀 호출
	if (n % 2 == 0) // 짝수
	{
		return calc_power_by_recursion(x * x, n / 2);
	}
	else // 홀수
	{
		return x * calc_power_by_recursion(x * x, (n - 1) / 2);
	}
}

int main(void)
{
	// 2^4
	printf("2 power 4 = %d\n", calc_power_by_recursion(2, 4));
	// 3^5
	printf("3 power 5 = %d\n", calc_power_by_recursion(3, 5));
	// 100^0
	printf("100 power 0 = %d\n", calc_power_by_recursion(100, 0));

	return 0;
}