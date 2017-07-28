#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define DIGIT 10
#define N 9

int count;

void MakeEmptyQueue(int bucket[DIGIT][N])
{
	for (int i = 0; i < DIGIT; i++) {
		for (int j = 0; j < N; j++) {
			bucket[i][j] = 0;
		}
	}
	count = 0;
}

bool IsEmptyQueue(void)
{
	return ((count > 0) ? true : false);
}

int Dequeue(int bucket[DIGIT][N], int row, int col)
{
	int x;
	
	if (!IsEmptyQueue()) {
		printf("Queue is empty\n");
		exit(-1);
	}
	else {
		x = bucket[row][col];
		--count;
		return x;
	}
}

void Enqueue(int info, int bucket[DIGIT][N], int row, int col)
{
	if (count == N)
		printf("Queue is full\n");
	else {
		bucket[row][col] = info;
		++count;
	}
}

void RadixSort(int table[N])
{
	int bucket[DIGIT][N];
	int i, j, k, p, q, l;
	int significant = 1;
	int max = 150;

	while ((max / significant) > 0){
		
		for (i = 0; i < DIGIT; i++) {
			for (j = 0; j < N; j++) {
				MakeEmptyQueue(bucket);
			}
		}
		
		for (k = 0; k < DIGIT; k++) {
			for (j = 0, i = 0; j < N; j++) {
				if (k == (table[j] / significant % 10)) {
					Enqueue(table[j], bucket, (table[j] / significant % 10), i);
					i++;
				}
			}
		}

		//printf("After enqueue count : %d\n", count);

		
		for (p = 0, l = 0; p < DIGIT; p++) {
			for (q = 0; (bucket[p][q] != 0) && (q < N); q++) {
				table[l] = Dequeue(bucket, p, q);
				++l;
			}
		}

		//printf("After dequeue count : %d\n", count);

		significant *= 10;
	}
	
}

int main(void)
{
	int table[N] = {99, 1, 10, 15, 8, 150, 1, 9, 66};

	RadixSort(table);

	for (int i = 0; i < N; i++)
		printf("%d\n", table[i]);

	getchar();

	return 0;
}
