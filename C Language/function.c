#include <stdio.h>

// 함수 선언
void p(int num);

void function_without_return();
int function_with_return();
void function_without_params();
void function_with_params(int num1, int num2, int num3);

int apple(int total, int ate); // 전체 total개에서 ate개를 먹고 남은 수를 반환

int main(void)
{
	// function

	int num = 2;
	//printf("num은 %d 입니다.\n", num); // 2
	p(num);

	// 2 + 3 은?
	num = num + 3;
	//printf("num은 %d 입니다.\n", num); // 5
	p(num);

	// 5 - 1 은?
	num -= 1; // num = num - 1;
	//printf("num은 %d 입니다.\n", num); // 4
	p(num);

	// 4 * 3 은?
	num *= 3;
	//printf("num은 %d 입니다.\n", num); // 12
	p(num);

	// 12 / 6 은?
	num /= 6;
	//printf("num은 %d 입니다.\n", num); // 2
	p(num);

	//함수의 종류
	//	- 반환값이 없는 함수
	function_without_return();
	//	- 반환값이 있는 함수
	int ret = function_with_return();
	p(ret);

	// 파라미터(전달값)가 없는 함수
	function_without_params();

	// 파라미터(전달값)가 있는 함수
	function_with_params(1, 2, 3);

	// 파라미터(전달값)도 받고, 반환값도 보내주는 함수
	int ret2 = apple(5, 2); // 5개의 사과 중에서 2개를 먹었어요
	printf("사과 5개 중에 2개를 먹으면 %d개가 남아요.", ret2);
	printf("사과 %d개 중에 %d개를 먹으면 %d개가 남아요.", 10, 4, apple(10, 4));
	return 0;
}

// 함수 정의
void p(int num)
{
	printf("num은 %d 입니다.\n", num);
}

void function_without_return()
{
	printf("반환값이 없는 함수입니다.\n");
}

int function_with_return()
{
	printf("반환값이 있는 함수입니다.\n");
	return 10;
}

void function_without_params()
{
	printf("전달값이 없는 함수입니다.\n");
}

void function_with_params(int num1, int num2, int num3)
{
	printf("전달값이 있는 함수이며 전달받은 값은 %d, %d, %d 입니다.\n", num1, num2, num3);
}

int apple(int total, int ate)
{
	printf("전달값과 반환값이 있는 함수입니다.\n");
	return total - ate;
}
