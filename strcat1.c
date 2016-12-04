#include <stdio.h>

void strcat1(char s[], char t[]);
void getline(char line[], int lim);

int main(void)
{
	char line1[1000];
	char line2[1000];	
	
	getline(line1, 1000);
	getline(line2, 1000);
	
	strcat1(line1, line2);
	
	printf("%s", line1);
	
	return 0;
} 

void getline(char s[], int lim)
{
	int i, c;
	
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (s[i] == '\n'){
		s[i] = c;
		++i;
	}
	
	s[i] = '\0';
}

void strcat1(char s[], char t[])
{
	int i, j;
	
	for (i = j = 0; s[i] != '\0'; ++i)
		;
	while((s[i++] = t[j++]) != '\0')
		;
}