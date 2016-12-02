/* K&R The C programming language Ex 2-4.*/
/* This program need to fix, because the result of code not beautiful */
/* But,,,,, i don't know how to fix this problem....*/
/* This problem occurs when there are consecutive blank. */

#include <stdio.h>

void getline(char s[], int lim);
void squeeze(char s[], char t[]);

main()
{
	char line[1000];
	char dd[1000];
	
	getline(line, 100);
	getline(dd, 100);
	
	squeeze(line, dd);
	
	printf("%s", line);
	
	return 0;
}

void getline(char s[], int lim)
{
	int i, c;
	
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n' ; ++i)
		s[i] = c;
	if (c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	
}


void squeeze(char s[], char t[])
{
	int i, j, temp;
	
		
	for (i = 0; i < 4; ++i){   /*need to fix the range of condition */
		for (j = 0; s[j] != '\0'; ++j){
			if (t[i] == s[j]){
				s[j++] = s[j];
				s[j] = ' ';
			}
		}
	}
	s[j] = '\0';
	for (i = 0; i <= j; ++i){
		if (s[i] == ' '){
			temp = s[i];
			s[i] = s[i+1];
			s[i+1] = temp;
		}	
	}
	
	s[i] = '\0';
}