#include <stdio.h>

/* 순환 Recursion */

// 자기 자신을 호출하는 것
// 3! = 3 * 2 * 1
// n! = n * (n - 1) * ... * 2 * 1

int fact(int n)
{
	if (n <= 1) // 탈출 조건
	{
		return 1;
	}
	else // 재귀호출
	{
		return n * fact(n - 1);
	}
}

// 장점
// 코드가 짧다
// 이해가 쉽다

// 단점
// 메모리를 많이 차지한다
// 시간이 많이 걸린다

// 장단점은 일반적인 특성이지 모든 알고리즘에 해당하지는 않는다

int main(void)
{
	int v = fact(5);

	printf("result is %d", v); // 120

	return 0;
}