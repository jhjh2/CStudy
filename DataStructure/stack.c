#include <stdio.h>

/* Stack */

// ADT (Abstract Data Type) : 저장방식 + Operation

// 저장방식
// 가장 나중에 저장된 데이터를 가장 먼저 꺼낼 수 있는 자료구조
// LIFO (Last In First Out)

// Stack operation
// 1.데이터를 넣는 것 push
// 2.데이터를 꺼내는 것 pop
// isEmpty, isFull...

void func3() // 3rd
{
	printf("this is func3\n"); // 1st
}

void func2() // 2nd
{
	func3();
	printf("this is func2\n"); // 2nd
}

void func1() // 1st
{
	func2();
	printf("this is func1\n"); // 3rd
}

// Stack for postfix notation
/*
수식 계산
중위표기법 수식 : 3 + 4,	3 - 1,	(3+4)*5,	3 + 4 * 5,	3*2 - 7*2
후위표기법 수식 : 34+,		31-,	34+5*,		45*3+,		32*72*-
*/
// 후위표기법 수식은 항상 왼쪽에서 오른쪽으로 계산해 나간다
// 후위표기법의 장점 : 컴퓨터가 쉽게 계산할 수 있다

typedef int boolean;

#define MAXIMUM_STACK_SIZE	10
#define INVALID_VALUE		-999
#define true				1
#define false				0

int stack[MAXIMUM_STACK_SIZE];
int top = -1;

boolean isEmpty(void);
boolean isFull(void);
boolean push(int v);
int pop(void);

int main(void)
{
	func1();

	int i;

	push(1);
	push(2);
	push(3);
	push(4);
	push(5);

	push(6);
	push(7);
	push(8);
	push(9);
	push(0);

	push(5);

	for (i = 0; i < 10; i++)
	{
		printf("%d\n", pop()); // 5, 4, 3, 2, 1
	}

	return 0;
}

boolean isEmpty(void)
{
	if (top == -1)
	{
		return true;
	}

	return false;
}

boolean isFull(void)
{
	if (top == MAXIMUM_STACK_SIZE - 1)
	{
		return true;
	}

	return false;
}

boolean push(int v)
{
	if (isFull() == true)
	{
		// stack is full, so it cannot push v
		printf("stack is full!\n");
		return false;
	}
	else
	{
		top++;
		stack[top] = v;
		return true;
	}
}

int pop(void)
{
	// check whether the stack is empty
	if (isEmpty() == true)
	{
		return INVALID_VALUE;
	}
	else
	{
		int temp = stack[top];
		top--;
		return temp;
	}
}