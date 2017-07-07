#include <stdio.h>

#define MAX 10

void qsort(int table[], int left, int right);

int main(void)
{
	int a[MAX] = {15, 3, 9, 5, 11, 20, 77, 1, 9, 17};
	int i;

	qsort(a, 0, MAX);

	for (i = 0; i < MAX; i++)
		printf("%d\n", a[i]);

	
	return 0;
}

void qsort(int table[], int left, int right)
{
	int i, j;
	int v;
	int temp;

	if (left < right) {
		i = left;
		j = right;
		v = table[left];

		while (i < j) {
			i = i + 1;
			while (i < right && table[i] < v)
				i = i + 1;
			j = j - 1;
			while (j >= left && table[j] > v)
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

		qsort(table, left, j);
		qsort(table, j + 1, right);
	}
}

