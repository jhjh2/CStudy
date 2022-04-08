#include <stdio.h>

/* Queue */
// ADT (Abstract Data Type) : 저장방식 + Operation

// 저장방식
// 가장 먼저 저장된 데이터를 가장 먼저 꺼낼 수 있는 자료구조
// FIFO (First In First Out)

// Stack operation
// 1.데이터를 넣는 것 enqueue, 큐의 뒷부분에서 일어난다
// 2.데이터를 꺼내는 것 dequeue, 큐의 앞부분에서 일어난다
// IsQueueEmpty, IsQueueFull...

// Circular Queue
// 큐를 효율적으로 구현하기 위한 방법론

#define QUEUE_SIZE 5

int queue[QUEUE_SIZE];
int front = 0;
int rear = 0;

int isQueueEmpty();
int isQueueFull();
void enqueue(int v);
int dequeue();

int main(void)
{
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5); // queue is full

	printf("dequeue is %d\n", dequeue());
	printf("dequeue is %d\n", dequeue());
	printf("dequeue is %d\n", dequeue());
	printf("dequeue is %d\n", dequeue());
	printf("dequeue is %d\n", dequeue()); // -999

	printf("queue size : %d\n", sizeof(queue) / sizeof(int));
	
	return 0;
}

// is queue empty
// return 1 if empty
//        0 if not
int isQueueEmpty()
{
	return (front == rear) ? 1 : 0;
	/*
	if (front == rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	*/
}

// is queue full
// return 1 if full
//        0 if not
int isQueueFull()
{
	return ((rear + 1) % QUEUE_SIZE == front) ? 1 : 0;
	/*
	if (front == (rear + 1) % QUEUE_SIZE)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	*/
}

// enqueue
void enqueue(int v)
{
	// check if the queue is full
	if (isQueueFull() == 1)
	{
		printf("queue is full\n");
		return;
	}
	else
	{
		rear = rear + 1;
		rear = rear % QUEUE_SIZE;

		queue[rear] = v;

		printf("enqueue is successful, %d\n", queue[rear]);
	}
}

// dequeue
int dequeue()
{
	// check if the queue is empty
	if (isQueueEmpty() == 1)
	{
		return -999;
	}
	else
	{
		front = front + 1;
		front = front % QUEUE_SIZE;

		return queue[front];
	}
}