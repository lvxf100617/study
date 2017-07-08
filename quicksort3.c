// reference to data structures and their algorithms book.



#include <stdio.h>

#define MAX 10

void qsort3(int table[], int left, int right);

int main(void)
{
	int a[MAX] = { 9, 99, 30, 31, 22, 28, 1 ,5, 10, 4 };

	qsort3(a, 0, MAX);

	for (int i = 0; i < MAX; i++)
		printf("%d\n", a[i]);
	
	return 0;
}

void qsort3(int table[], int left, int right)
{
	int i, j;
	int v;
	int mid;
	int temp;

	if (right - left > 2) {
		mid = (left+right) / 2;
		
		temp = table[left+1];
		table[left+1] = table[mid];
		table[mid] = temp;	

		i = left;
		j = right;
		v = table[left];

		while (i < j) {
			i = i + 1;
			while (table[i] < v)
				i = i + 1;
			j = j - 1;
			while (table[j] > v)
				j = j - 1;
			
			temp = table[i];
			table[i] = table[j];
			table[j] = temp;
		}

		temp = table[i];
		table[i] = table[j];
		table[j] = temp;

		temp = table[j];
		table[j] = table[left];
		table[left] = temp;

		qsort3(table, left, j);
		qsort3(table, j + 1, right);
	}
}
