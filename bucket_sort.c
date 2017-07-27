/* bucket sort for single digit number.
   i must make this code to sort two-digit number.
   but.... not easy.
*/

#include <stdio.h>
#include <conio.h>

#define DIG 10
#define NUM 10

void BucketSort(int table[]);
void MakeEmptySet(int bucket[]);
int Key(int);
void Delete1(int x, int bucket[]);
bool isEmpty1(void);

int cnt = 0;

int main(void)
{
	int table[NUM] = { 9, 1, 5, 4, 8, 6, 2, 3, 7};

	printf("Before implement bucket sort\n");

	for (int i = 0; i < NUM; i++)
		printf("%d\n", table[i]);

	BucketSort(table);

	printf("After implement bucket sort\n");

	for (int i = 0; i < NUM; i++)
		printf("%d\n", table[i]);

	getchar();

	return 0;
}

void MakeEmptySet(int bucket[])
{
	for (int i = 0; i < DIG; i++)
		bucket[i] = 0;
}

int Key(int key)
{
	return (key % 10);
}

void Delete1(int x, int bucket[])
{
	int i;
	int temp;

	for (i = 0; i < NUM; i++) {
		if (bucket[i] == x) {
			for (int j = i; j < NUM; j++) {
				bucket[j] = bucket[j + 1];
			}
		}
	}
	--cnt;
}

bool isEmpty1(void)
{
	if (cnt < 0)
		return false;
	return true;
}

void BucketSort(int table[])
{
	int i, j, x;
	int bucket[DIG];

	MakeEmptySet(bucket);

	for (j = 0; j < NUM; j++) {
		bucket[Key(table[j])] = table[j];
		++cnt;
	}

	j = 0;
	for (i = 0; i < DIG; i++) {
		while (isEmpty1()) {
			x = bucket[i];
			Delete1(x, bucket);
			table[j] = x;
			++j;
		}
	}
}
