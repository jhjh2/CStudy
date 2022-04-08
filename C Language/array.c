#include <stdio.h>

int main(void)
{
	// 배열
	int subway1 = 30; // 지하철 1호차에 30명이 타고 있다
	int subway2 = 40;
	int subway3 = 51;

	printf("지하철 1호차에 %d명이 타고 있습니다\n", subway1);
	printf("지하철 2호차에 %d명이 타고 있습니다\n", subway2);
	printf("지하철 3호차에 %d명이 타고 있습니다\n", subway3);

	// 여러개의 변수를 함께, 동시에 생성
	int subway_array[3]; // [0][1][2]
	subway_array[0] = 30;
	subway_array[1] = 40;
	subway_array[2] = 50;

	for (int i = 0; i < 3; i++)
	{
		printf("지하철 %d호차에 %d명이 타고 있습니다\n", i + 1, subway_array[i]);
	}

	// 값 설정 방법
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arr[i]);
	}

	// 값은 반드시 초기화 해야 함
	int arr2[10];
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arr2[i]); // 알 수 없는 값이 출력된다
	}

	// 배열 크기는 항상 상수로 선언
	int size = 10;
	//int arr3[size]; // 에러 발생! 배열 생성 시 상수값을 입력해야 한다

	// 3번째 값부터는 자동으로 '0'으로 초기화됨
	int arr4[10] = { 1, 2 };
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arr4[i]);
	}

	int arr5[] = { 1, 2 }; // arr5[2], 자동으로 배열크기를 만들어줌

	float arr_f[5] = { 1.0f, 2.0f, 3 };
	for (int i = 0; i < sizeof(arr_f); i++)
	{
		printf("%.1f\n", arr_f[i]); // 1.0, 2.0, 3.0, 0.0, 0.0
	}

	// 문자 vs 문자열
	char c = 'A';
	printf("%c\n", c);

	// 문자열 끝에는 '끝'을 의미하는 NULL 문자 '\0'이 포함되어야 함
	//char str[6] = "coding"; // 오류 발생!
	char str[7] = "coding"; // [c][o][d][i][n][g][\0]
	printf("%s\n", str);

	char str2[] = "coding";
	printf("%s\n", str2);
	printf("%d\n", sizeof(str2)); // 7

	for (int i = 0; i < sizeof(str2); i++)
	{
		printf("%c\n", str2[i]);
	}

	char kor[] = "한글문자열";
	printf("%s\n", kor);
	printf("%d\n", sizeof(kor)); // 11
	// 영어 1글자 : 1 byte
	// 한글 1글자 : 2 byte
	// char 크기 : 1 byte

	char c_array[7] = { 'c','o','d','i','n','g','\0' };
	printf("%s\n", c_array);

	// 배열에 남는 공간이 있다면 문자열 '끝'이 자동으로 들어간다
	char c_array2[10] = { 'c','o','d','i','n','g' };
	printf("%s\n", c_array2);
	for (int i = 0; i < sizeof(c_array2); i++)
	{
		printf("%c\n", c_array2[i]);
	}

	for (int i = 0; i < sizeof(c_array2); i++)
	{
		printf("%d\n", c_array2[i]); // %d, ASCII 코드 값 출력 (NULL문자 0으로 입력됨)
	}

	// 참고 : ASCII 코드란 ANSI(미국표준협회)에서 제시한 표준 코드 체계
	// 7bit, 총 128개 코드 (0-127)
	// a : 97 (문자 a의 아스키코드 정수값)
	// A : 65
	// 0 : 48

	printf("%c\n", 'a'); // a
	printf("%d\n", 'a'); // 97

	printf("%c\n", 'b'); // b
	printf("%d\n", 'b'); // 98

	printf("%c\n", 'A'); // A
	printf("%d\n", 'A'); // 65

	printf("%c\n", '\0');
	printf("%d\n", '\0'); // 정수 0 출력

	// 참고2 : 0-127 사이의 아스키코드 정수값에 해당하는 문자 확인
	for (int i = 0; i < 128; i++)
	{
		printf("아스키코드 정수 %d : %c\n", i, i);
	}

	return 0;
}