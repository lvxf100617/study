/* This is K&R exercise ..*/
/* This fucnction is uppercase letter to lower case letter*/
/* Important thing is all of C character corresponding to ASCII code. that is */
/* That are have a decimal number ..*/
/* So the return function, finally, return int number */


#include <stdio.h>

int lower(int c);

int main(void)
{
	int c;
	
  while ((c = getchar()) != EOF)
	  printf("%c", lower('C'));
	
	return 0;
}


int lower(int c)
{
	
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}
