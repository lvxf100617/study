/* This code is min heap
   i.e., minimum element in the table will be root.
   
   In heapify will be implemented as tail-recursion.
   
   Using tail-recursive, we can have no extra memory when recode.
   
   Time complexive on Heap sort's implements are O(nlogn).
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10
#define MAX_INT 32767

void HeapSort(int [], int);
void InitializeHeap(int [], int);
void Heapify(int [], int, int);

int table[MAX];

int main(void)
{
	int i;

	srand((unsigned)time(NULL));

	for (i = 0; i < MAX; i++) {
		table[i] = rand() % MAX_INT;
	}

	printf("objects in array are randomly assigned.\n");
	printf("Before heap sort.\n");

	for (i = 0; i < MAX; i++) {
		printf("%d\n", table[i]);
	}

	HeapSort(table, MAX);

	printf("Result of Heapsort\n");
	for (i = 0; i < MAX; i++) {
		printf("%d\n", table[i]);
	}

	getchar();

	return 0;
}

void HeapSort(int a[], int size)
{
	int i;
	int temp;

	InitializeHeap(a, size);
	printf("After implement Initialize Heap.\n");

	for (i = 0; i < size; i++)
		printf("%d\n", a[i]);

	for (i = 0; i < MAX - 1; i++) {
		temp = a[i];
		a[i] = a[MAX - 1];
		a[MAX - 1] = temp;
		Heapify(a, i + 1, MAX - 1);
	}


}

void InitializeHeap(int a[], int size)
{
	int i;

	for (i = 0; i < MAX; i++) {
		Heapify(a, 0, i);
	}
}

int count = 0;

void Heapify(int a[], int i, int j)
{
	int RightChild, LeftChild;
	int temp;
	int k;


	RightChild = 2 * j - MAX - 1;
	LeftChild = 2 * j - MAX;

	if (RightChild >= i && a[RightChild] <= a[LeftChild] && a[RightChild] < a[j]) {
		temp = a[j];
		a[j] = a[RightChild];
		a[RightChild] = temp;
		Heapify(a, i, RightChild);
	}else if (LeftChild >= i && a[LeftChild] < a[j]) {
		temp = a[j];
		a[j] = a[LeftChild];
		a[LeftChild] = temp;
		Heapify(a, i, LeftChild);
	}

	printf("After %d implement heapify...?\n", count+1);

	for (k = 0; k < MAX; k++) {
		printf("%d\n", a[k]);
	}
	count++;
}
