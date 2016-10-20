#include <stdio.h>
#include <assert.h>

#define N 20

typedef const char cchr;

void add(int sum[], int a[], int b[]);
void wrt(cchr *s, int a[]);    /* s is a pointer to type of const char */

int main(void)
{
	int a[N] = {7, 5, 9, 8, 9, 7, 5, 0, 0, 9, 9, 0, 8, 8}; /* size is 20 not 13 */
	int b[N] = {7, 7, 5, 3, 1, 2, 8, 8, 9, 6, 7, 7};       /*    "" */ 
	int sum[N];
	int ndigits;   /* why need to declare? */
	
	add(sum, a, b);
	wrt("Integer a: ", a);
	wrt("Integer b: ", b);
	wrt("      sum: ", sum);
	return 0;
}

void add(int sum[], int a[], int b[])
{
	int carry = 0;  /* This variable represent ....?(9 + 1 = 10 -> 1)... */
	int i;
	
	for (i = 0; i < N; ++i){
		sum[i] = a[i] + b[i] + carry;   /*for instance, at here, sum[0] = a[0] + b[0] + 0 then sum[0] have value 14 */
		if (sum[i] < 10)
			carry = 0;                    /*Because sum[0] is exceed 10, dosen't execute this part */
		else{
			carry = sum[i] / 10;          /* This part will take 1, and will be added to sum[1] */
			sum[i] %= 10;                 /* This part will take 4. */
		}                               /* I think this part is algorithm for add */
	}
}

void wrt(cchr *s, int a[])
{
	int i;
	
	printf("%s", s);
	//print leading zeros as blanks;
	for (i = N-1; i > 0 && a[i] == 0; --i)  /* ex : from 14 element in a[] to 20 element in a[] consist of zero. */
		putchar(' ');                         /* So i = 19 ~ 14 print blank */ 
	//after a leading digit greater than zero is found,
	//print all the remaining digits, including zeros.
	for ( ; i >= 0; --i)                    /* from i = 13 to i = 1 */
		printf("%d", a[i]);                   /* print a[13], a[12], .... , a[0] */
	putchar ('\n');
}
