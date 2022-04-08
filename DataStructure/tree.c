/* Trees: terminology */

// root node
// 맨 위의 노드, 항상 뿌리 노드를 가리키는 포인터가 있어야 한다

// 상대적인 관계
// parent node, child nodes

// leaf nodes (= terminal nodes)
// 자식 노드가 없는 노드들
// 하나의 자식 노드라도 가지고 있는 노드들은 non-leaf nodes (= non-terminal nodes)

// sub-tree
// 트리의 일부분, 단 하나의 노드만으로 이루어진 서브 트리도 있다
// tree는 전체를 가리킨다

// siblings
// 같은 부모 노드를 가지는 노드들

// degree
// degree of a node : # of sub-tree of the node
// 어떤 노드가 가지는 서브 트리의 개수
// degree of a tree : maximum # of the degrees
// 트리 안에 담겨 있는 노드들이 가진 degree 중 가장 큰 값

// level
// Height or Depth of a tree
// 트리의 높이, 루트 노드만 있는 경우 level 1


/* Binary Tree */
// a tree in which every node has at most two child nodes
// 최대 두 개의 자식 노드를 가지는 트리

// maximum # of nodes on level 1 of binary tree = 1
//                    on level 2 of binary tree = 2
//                    on level 3 of binary tree = 4
//                       ...
//                    on level i of binary tree = 2^(i - 1)

// maximum # of nodes of a depth 1 binary tree = # of nodes at level 1
// maximum # of nodes of a depth 2 binary tree = # of nodes at level 1 + 2
// maximum # of nodes of a depth 3 binary tree = # of nodes at level 1 + 2 + 3
//                       ...
// maximum # of nodes of a depth k binary tree = # of nodes at level 1 + 2 + 3 + ... + k = 2^0 + 2^1 + 2^2 + ... + 2^(k - 1) = 2^k - 1


/* Binary Tree Traversal */
// 모든 노드를 중복 없이 한 번 씩 방문하여 모든 데이터를 추출하는 방법
// methods: preorder Traversal, inorder Traversal, postorder Traversal // 부모 노드를 언제 방문하는지 

// preorder Traversal
// visit parent node
// traverse its left subtree
// traverse its right subtree

// inorder Traversal
// traverse its left subtree
// visit parent node
// traverse its right subtree

// postorder Traversal
// traverse its left subtree
// traverse its right subtree
// visit parent node


/* Binary Search Tree */
// Definition of Binary Search Tree 조건
// 1. Every node entry has a unique key. // 중복 X
// 2. All the keys in the left subtree of a node are less than the key of the node. // 왼쪽 서브 트리의 모든 값은 노드의 값보다 작다
// 3. All the keys in the right subtree of a node are greater than the key of the node. // 오른쪽 서브 트리의 모든 값은 노드의 값보다 크다

// Advantages of BST 장점
// 1. Easy to search an item in the BST
// 2. Easy to find maximum or minimum item in the BST
// 3. Easy to sort the items in the BST
// 4. Easy to find successor of an item in the BST 바로 다음 값

#include <stdio.h>
#include <stdlib.h>

// BST Implementation
struct node
{
	int key;

	struct node* left;
	struct node* right;
};

struct node* root = 0;

void addToBST(int n);
struct node* findLeast(struct node* node);
struct node* removeNode(struct node* node, int key);
void inorderTraversal(struct node* node);

int main(void)
{
	addToBST(10);
	addToBST(5);
	addToBST(20);
	addToBST(7);
	addToBST(30);

	printf("root %d\n", root->key);
	printf("root left %d\n", root->left->key);
	printf("root right %d\n", root->right->key);

	removeNode(root, 5);

	printf("root %d\n", root->key);
	printf("root left %d\n", root->left->key);
	printf("root right %d\n", root->right->key);

	inorderTraversal(root);

	return 0;
}

void addToBST(int n)
{
	struct node* cur = (struct node*)malloc(sizeof(struct node));
	cur->left = cur->right = 0;
	cur->key = n;

	// 노드 추가 과정
	if (root == 0) // 트리가 비어있는 경우
	{
		root = cur;
	}
	else
	{
		struct node* temp = root;

		while (1)
		{
			// 값 비교
			if (temp->key > cur->key) // left
			{
				// 자식 노드 확인
				if (temp->left == 0)
				{
					temp->left = cur;
					return;
				}
				else
				{
					temp = temp->left;
				}
			}
			else // right
			{
				// 자식 노드 확인
				if (temp->right == 0)
				{
					temp->right = cur;
					return;
				}
				else
				{
					temp = temp->right;
				}
			}
		}
	}
}

struct node* findLeast(struct node* node)
{
	struct node* cur = node;
	while (cur->left != 0)
	{
		cur = cur->left;
	}

	return cur;
}

struct node* removeNode(struct node* node, int key) // 재귀 함수
{
	// 탈출 조건
	if (node == 0) // 트리에 찾는 데이터가 없는 경우
	{
		return 0;
	}

	// 재귀호출
	if (key == node->key) // found match
	{
		if (node->left == 0 && node->right == 0) // 자식 노드가 없는 경우
		{
			free(node);
			return 0;
		}
		else if (node->left == 0) // 오른쪽 자식 노드만 있는 경우
		{
			struct node* ret = node->right;
			free(node);
			return ret;
		}
		else if (node->right == 0) // 왼쪽 자식 노드만 있는 경우
		{
			struct node* ret = node->left;
			free(node);
			return ret;
		}
		else // 양쪽에 자식 노드가 있는 경우
		{
			struct node* toReplace = findLeast(node->right);
			node->key = toReplace->key;
			node->right = removeNode(node->right, toReplace->key);
			return node;
		}
	}
	else if (key < node->key)
	{
		node->left = removeNode(node->left, key);
		return node;
	}
	else // key > node->key
	{
		node->right = removeNode(node->right, key);
		return node;
	}
}

void inorderTraversal(struct node* node)
{
	if (node == 0)
	{
		return;
	}

	inorderTraversal(node->left);
	printf("%d \n", node->key);
	inorderTraversal(node->right);
}