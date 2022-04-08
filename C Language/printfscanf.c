#include <stdio.h>

int main(void)
{
	// 정수형 변수
	int age = 12;
	printf("%d\n", age);

	// 실수형 변수
	float f = 46.546;
	printf("%.2f\n", f); // 46.55, 반올림 되어 출력됨

	double d = 4.424;
	printf("%.2lf\n", d); // 4.42, 반올림 되어 출력됨

	// 상수
	const int YEAR = 2000;
	printf("year of birth : %d\n", YEAR);
	// YEAR = 2001; 변경 불가능

	// printf
	// 연산
	int add = 3 + 7; // 10
	printf("3 + 7 = %d\n", add);
	printf("%d + %d = %d\n", 3, 7, 3 + 7);
	printf("%d * %d = %d\n", 3, 7, 3 * 7);

	// scanf
	// 키보드 입력을 받아서 저장
	int input;
	printf("insert value : ");
	scanf_s("%d", &input);
	printf("the value is : %d\n", input);

	int one, two, three;
	printf("insert 3 integers : ");
	scanf_s("%d %d %d", &one, &two, &three);
	printf("one : %d\n", one);
	printf("two : %d\n", two);
	printf("three : %d\n", three);

	// 문자(한글자), 문자열(한 글자 이상의 여러 글자)
	char c = 'A';
	printf("%c\n", c);

	char str[256];
	printf("insert characters : ");
	scanf_s("%s", str, sizeof(str));
	printf("%s\n", str);

	return 0;
}