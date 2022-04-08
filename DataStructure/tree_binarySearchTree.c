#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 주소록 */

struct node {
	struct node* left;
	struct node* right;
	char* name;
	char* phone_number;
};

struct node* root = 0;

struct node* createNewNode(char* name, char* phoneNumber)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->left = 0;
	newNode->right = 0;

	// name과 phone_number의 메모리 공간을 직접 할당하여 관리
	//newNode->name = name;
	//newNode->phone_number = phoneNumber;
	char* _name = (char*)malloc(strlen(name) + 1);
	strcpy(_name, name);

	char* _phoneNumber = (char*)malloc(strlen(phoneNumber) + 1);
	strcpy(_phoneNumber, phoneNumber);

	newNode->name = _name;
	newNode->phone_number = _phoneNumber;

	return newNode;
}

void addToBST(char* name, char* phoneNumber)
{
	struct node* newNode = createNewNode(name, phoneNumber);

	if (root == 0)
	{
		root = newNode;
		return;
	}
	else
	{
		struct node* cur = root;

		while (1)
		{
			// strcmp(str1, str2) : string compare
			// return 0, str1 == str2
			// return -1, strcmp(str1, str2) < 0 ===> str1 < str2, str1이 먼저 나오는 경우
			// return 1, strcmp(str1, str2) > 0 ===> str1 > str2, str2가 먼저 나오는 경우

			if (strcmp(cur->name, newNode->name) < 0) // right
			{
				if (cur->right == 0)
				{
					cur->right = newNode;
					return;
				}
				else
				{
					cur = cur->right;
				}
			}
			else if (strcmp(cur->name, newNode->name) > 0) // left
			{
				if (cur->left == 0)
				{
					cur->left = newNode;
					return;
				}
				else
				{
					cur = cur->left;
				}
			}
			else // strcmp(cur->name, newNode->name) == 0, 동일 이름
			{
				printf("same name\n");
				return;
			}
		}
	}
}

void displayNodeInfo(struct node* node)
{
	if (node == 0)
	{
		printf("node is null\n");
	}
	printf("name : %s, phone : %s\n", node->name, node->phone_number);
}

void inorder(struct node* node)
{
	if (node == 0)
	{
		return;
	}

	inorder(node->left);
	displayNodeInfo(node);
	inorder(node->right);
}

void searchBST(char* name)
{
	struct node* cur = root;

	while (1)
	{
		if (cur == 0)
		{
			printf("%s is not an exist person.\n", name);
			return;
		}

		if (strcmp(cur->name, name) < 0) // right
		{
			cur = cur->right;
		}
		else if (strcmp(cur->name, name) > 0) // left
		{
			cur = cur->left;
		}
		else // strcmp(cur->name, name) == 0, 동일 이름
		{
			printf("%s's phone number is %s.\n", name, cur->phone_number);
			return;
		}
	}
}

int main(void)
{
	addToBST("park", "010-1111-1234"); // root
	addToBST("kim", "010-2222-1234"); // root->left
	addToBST("lee", "010-3333-1234"); // root->left->right

	//displayNodeInfo(root);
	//displayNodeInfo(root->left);
	//displayNodeInfo(root->right);

	//inorder(root);

	char buf[30];

	printf("Insert a name to search : ");
	gets(buf);

	searchBST(buf);

	return 0;
}