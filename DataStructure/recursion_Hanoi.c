#include <stdio.h>

/* 하노이의 탑 */

// n개의 접시를
// from에서 to까지 옮긴다.
// 이 때, tmp를 임시로 사용한다.


void hanoi(int n, int from, int tmp, int to)
{
	// exit condition
	if (n == 1)
	{
		printf("move one dish from %d to %d\n", from, to);
		return;
	}

	// recursive condition

	// 1. n-1개를 from --> tmp로 옮겨 놓는다. (임시 to)
	hanoi(n - 1, from, to, tmp);
	// 2. 1개를 from --> to로 옮긴다. (임시 tmp)
	hanoi(1, from, tmp, to);
	// 3. n-1개를 tmp --> to로 옮긴다. (임시 from)
	hanoi(n - 1, tmp, from, to);
}

int main(void)
{
	// 3개의 접시를 1번에서 3번으로 옮겨라.
	// 단, 2번을 임시로 사용 가능.
	hanoi(5, 1, 2, 3);
	return 0;
}