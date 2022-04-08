/* Hashing */

// 자료구조가 정렬되어 있다 하더라도 데이터를 찾기 쉽지 않기 때문에,
// 순차적으로 접근할 필요 없이 한 번에 찾을 수 있도록 하는 것.


/* Hashing function */

// 자료 저장 시 index를 계산하여 그 위치에 저장

// 배열에 데이터를 저장하는 경우
// 데이터 a, ab, abc, abcd

// 데이터의 글자 수를 index로 지정하는 경우
// h(a) => 1, h(ab) => 2, h(abc) => 3, h(abcd) => 4

// 다른 해시함수의 경우
// a = 1, b = 2, c = 3, d = 4로 두고 데이터의 문자의 총합 % 3 을 index로 지정
// h(a) => 1 % 3 = 1, h(ab) => (1 + 2) % 3 = 0, h(abc) => (1 + 2 + 3) % 3 = 0, h(abcd) => (1 + 2 + 3 + 4) % 3 = 1
// 다른 데이터에 동일한 index값이 지정되어 성능이 좋지 않은 해시함수이다


/* Collision */

// 버킷 : 데이터를 저장할 수 있는 공간
// 하나의 버킷 안에 두 개 이상의 데이터가 들어가는 경우 Collision 충돌 발생

// 충돌 해결 방법
// 1. Chaining
// 버킷에 이미 데이터가 있는 경우 링크로 연결
// Singly Linked List

// 2. linear probing
// 버킷에 이미 데이터가 있는 경우 다음 버킷으로 넘어가서 저장한다 

// Loading density = 데이터 개수 / 전체 버킷
// 높으면 Collision 확률 증가, 공간 효율적
// 낮으면 Collision 확률 감소, 공간 낭비


/* 구현 */

// 학생데이터 : 이름, 학번, 나이
// 이름으로 hashing하여 저장
// 이름으로 검색
// chaining 방식으로 저장
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
	char name[20];
	int stno;
	unsigned short age;
	struct student* next;
};

typedef struct student STUDENT;

#define HASHTABLE_SIZE 30
STUDENT* hashTable[HASHTABLE_SIZE]; // init with NULL

int hashFunction(char* str);
void addToHashTable(char* name, int stno, unsigned short age);
void searchInTheHash(char* name);

int main(void)
{
	addToHashTable("박철수", 200, 19);
	addToHashTable("김철수", 201, 20);
	addToHashTable("이철수", 202, 19);
	addToHashTable("오철수", 203, 18);
	addToHashTable("송철수", 204, 19);

	searchInTheHash("이철수");
	searchInTheHash("송철수");

	return 0;
}

int hashFunction(char* str)
{
	// 1. 문자값을 모두 더한다
	int sum = 0;
	int len = strlen(str);
	int i;
	for (i = 0; i < len; i++)
	{
		sum += str[i];
	}
	
	// 2. % HASHTABLE_SIZE
	return (sum % HASHTABLE_SIZE);
}

void addToHashTable(char* name, int stno, unsigned short age)
{
	STUDENT* cur = (STUDENT*)malloc(sizeof(STUDENT));
	strcpy(cur->name, name);
	cur->stno = stno;
	cur->age = age;
	cur->next = 0;
	
	int index = hashFunction(name);
	
	if (hashTable[index] == 0) // empty
	{
		hashTable[index] = cur;
		return;
	}
	else // Collision
	{
		STUDENT* temp = hashTable[index];
		while (temp->next != 0)
		{
			temp = temp->next;
		}

		temp->next = cur;
		return;
	}
}

void searchInTheHash(char* name)
{
	// 1. 찾는 과정
	int index = hashFunction(name);
	STUDENT* cur = hashTable[index];

	if (cur == 0) // empty
	{
		return;
	}

	while (strcmp(cur->name, name) != 0)
	{
		cur = cur->next;
		if (cur == 0)
		{
			return;
		}
	}

	// 2. 데이터 출력
	printf("%s %d %d \n", cur->name, cur->stno, cur->age);
}