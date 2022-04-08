/* Sort 정렬 */

// 1. Bubble Sort
// 0번부터 (배열의 크기 - 1)번 인덱스까지, 한 인덱스의 값을 다음 인덱스의 값과 비교하여 더 큰 값을 뒤의 인덱스에 저장

// 2. Selection Sort
// 정렬되지 않은 배열 중 가장 작은 값을 정렬된 배열의 마지막에 저장

// 3. Insertion Sort
// 1번부터 (배열의 크기)번 인덱스까지, 한 인덱스의 값을 이전 인덱스의 값과 비교하여 더 작은 값을 앞의 인덱스에 저장

// 4. Quick Sort
// 피봇의 위치를 찾은 다음 나머지 값에 대해서도 피봇의 위치를 찾는 과정을 반복


/* speed */

// Quick Sort : O(n * logn)
// Bubble, Selection, Insertion Sort : O(n^2)

#include <stdio.h>

void printAll(int* toBeDisplayed, int size);
void swap(int* arr, int index1, int index2);
void performBubbleSort(int* toBeSorted, int size);
int findSmallest(int* arr, int startIndex, int size);
void performSelectionSort(int* toBeSorted, int size);
void performInsertionSort(int* toBeSorted, int size);
void performQuickSort(int* toBeSorted, int pivotIndex, int leftIndex, int rightIndex);

int main(void)
{
	int data[10] = { 31, 24, 56, 1, 4, 10, 6, 76, 87, 30 };

	printf("Before being sorted\n");
	printAll(data, 10);
	printf("---------------------------------\n");

	//performBubbleSort(data, 10);
	//performSelectionSort(data, 10);
	//performInsertionSort(data, 10);
	performQuickSort(data, 0, 1, 9);

	return 0;
}

// Bubble Sort
void printAll(int* toBeDisplayed, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", toBeDisplayed[i]);
	}
	printf("\n");
}

void swap(int* arr, int index1, int index2)
{
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}

void performBubbleSort(int* toBeSorted, int size)
{
	int i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (toBeSorted[j] > toBeSorted[j + 1])
			{
				// j <--> j + 1
				swap(toBeSorted, j, j + 1);
			}
		}

		printAll(toBeSorted, 10);
	}
}

// Selection Sort
int findSmallest(int* arr, int startIndex, int size)
{
	int smallestIndex = startIndex;
	int smallest = arr[startIndex];

	int i;
	for (i = startIndex; i < size; i++)
	{
		if (arr[i] < smallest)
		{
			smallest = arr[i];
			smallestIndex = i;
		}
	}

	return smallestIndex;
}

void performSelectionSort(int* toBeSorted, int size)
{
	int i, j;

	// 가장 작은것을 찾고 맨 앞으로 이동
	for (i = 0; i < size; i++)
	{
		j = findSmallest(toBeSorted, i, size);
		swap(toBeSorted, i, j);
		printAll(toBeSorted, size);
	}
}

// Insertion Sort
void performInsertionSort(int* toBeSorted, int size)
{
	int i;

	for (i = 1; i < size; i++)
	{
		int j = i;
		while ((j - 1) >= 0 && toBeSorted[j - 1] > toBeSorted[j])
		{
			swap(toBeSorted, j - 1, j);
			j--;
		}

		printAll(toBeSorted, 10);
	}
}

// Quick Sort
void performQuickSort(int* toBeSorted, int pivotIndex, int leftIndex, int rightIndex)
{
	int left = leftIndex;
	int right = rightIndex;

	printf("pivot : %d, left : %d, right : %d \n", pivotIndex, leftIndex, rightIndex);
	printAll(toBeSorted, 10);

	while (left < right)
	{
		while (toBeSorted[pivotIndex] > toBeSorted[left] && left <= rightIndex)
		{
			left++;
		}

		while (toBeSorted[pivotIndex] < toBeSorted[right] && right >= leftIndex)
		{
			right--;
		}

		if (right < left)
		{
			swap(toBeSorted, pivotIndex, right);
			performQuickSort(toBeSorted, pivotIndex, pivotIndex + 1, right - 1);
			performQuickSort(toBeSorted, right + 1, right + 2, rightIndex);
		}
		else
		{
			swap(toBeSorted, left, right);
			printf("-->");
			printAll(toBeSorted, 10);
		}
	}
}