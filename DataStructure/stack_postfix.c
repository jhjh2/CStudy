#include <stdio.h>

// 후위표기법 계산 구현

// 조건
// 1. 한자리 숫자만 입력
// 2. +, -, *, /

// 입력 방법
// >3
// >4
// >*
// >5
// >+
// >e (end) // 17 출력

#define STACK_SIZE 2

int stack[STACK_SIZE]; // index 0, 1

int top = -1;

// return 1 if YES
//        0 if NO
int isEmpty()
{
	return top == - 1 ? 1 : 0;
	/*
	if (top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	*/
}

// return 1 if YES
//        0 if NO
int isFull()
{
	return top == STACK_SIZE - 1 ? 1 : 0;
	/*
	if (top == STACK_SIZE - 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	*/
}

void push(int v)
{
	if (isFull() != 1)
	{
		top++;
		stack[top] = v;
	}
	else
	{
		printf("stack if full.\n");
	}
}

// return -999 if nothing to pop
int pop()
{
	if (isEmpty() != 1)
	{
		int v = stack[top];
		top--;
		return v;
	}
	else
	{
		return -999;
	}
}

int main(void)
{
	char c;

	while (1)
	{
		printf("Enter: ");
		scanf_s("%c", &c);
		while (getchar() != '\n');

		switch (c)
		{
		case '+':
		case '-':
		case '*':
		case '/':
		{ // 새로운 변수를 선언하기 위해 { } 필요하다
			int v2 = pop();
			int v1 = pop();
			if (v2 == -999)
			{
				printf("no number on stack.\n");
			}
			else if (v1 == -999)
			{
				printf("not enough numbers on stack.\n");
				printf("push %d back on stack.\n", v2);
				push(v2);
			}
			else
			{
				switch (c)
				{
				case '+':
					push(v1 + v2);
					break;
				case '-':
					push(v1 - v2);
					break;
				case '*':
					push(v1 * v2);
					break;
				case '/':
					if (v2 == 0)
					{
						printf("can not divided by 0.\n");
						printf("push %d back on stack.\n", v1);
						push(v1);
						break;
					}
					else
					{
						push(v1 / v2);
						break;
					}
				}
			}
		}
		break;
		case 'E':
		case 'e':
			printf("The result is %d\n", pop());
			return;
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case '0':
			{ // 새로운 변수를 선언하기 위해 { } 필요하다
				int v = c - '0';
				push(v);
			}
			break;
		default:
			printf("not a correct input.\n");
			break;
		}
	}

	return 0;
}