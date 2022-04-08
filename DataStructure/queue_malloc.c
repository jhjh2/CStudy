#include <stdio.h> // printf, scanf
#include <string.h> // strcpy
#include <stdlib.h> // malloc, free


#define QUEUE_SIZE 10
char* queue[QUEUE_SIZE];
int front = 0, rear = 0;

int isQueueFull()
{
	return (rear + 1) % QUEUE_SIZE == front ? 1 : 0;
}

int isQueueEmpty()
{
	return front == rear ? 1 : 0;
}

int enqueue(char* v)
{
	if ((rear + 1) % QUEUE_SIZE == front)
	{
		printf("queue is full\n");
		return 0;
	}
	else
	{
		rear = (rear + 1) % QUEUE_SIZE;
		queue[rear] = v;
		return 1;
	}
}

char* dequeue()
{
	if (front == rear)
	{
		printf("queue is empty\n");
		return 0;
	}
	else
	{
		front = (front + 1) % QUEUE_SIZE;
		return queue[front];
	}
}

int main(void)
{	
	char temp[30]; // 30byte, 29byte의 글자 저장 가능
	char* v;

	while (1)
	{
		printf("Enter word: ");
		scanf("%s", temp);

		v = (char*)malloc(strlen(temp + 1)); // +1은 문자열 끝을 나타내는 \0 (NULL)을 위한 공간
		strcpy(v, temp); // temp의 내용이 v로 복사된다

		if (enqueue(v) == 0)
		{
			printf("queue is full\n");

			while ((v = dequeue()) != 0)
			{
				printf("%s \n", v);
				free(v);
			}
		}
		
	}
	

	return 0;
}