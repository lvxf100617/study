/* K&R The programming language Example */
/* atoi() that string of digits converts to numeric value.*/

#include <stdio.h>

int atoi(char s[]);

int main(void)
{
	char s[] = "157891";
	
	printf("%d", atoi(s));
	
	return 0;
}


int atoi(char s[])
{
	int i, n;
	
	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;
}
