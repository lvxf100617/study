/* K & R The C programming language Ex 3-2 */
/* Write a function escape(s,t) that converts characters like newline and tab into visible */
/* escape sequences like \n and \t as it copies the string t to s */

/* If this exercise require to apper the character \n or \t then.... i was failed */
/* if i type '\\t' or '\\n' at line 50, then the compiler cause warning */



#include <stdio.h>

void getline(char line[], int maxline);
void escape(char s[], char t[]);

main()
{
	char b_fix[1000];
	char a_fix[1000];
	
	getline(b_fix, 1000);
	escape(a_fix, b_fix);
	
	printf("%s", a_fix);
	
	return 0;
}

void getline(char s[], int lim)
{
	int i, c;
	
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF; ++i)
		s[i] = c;
	/*if (s[i] == '\n'){
		s[i] = c;
		++i;
	}*/
	
	s[i] = '\0';
	
}

void escape(char s[], char t[])
{
	int i;
	
	for (i = 0; t[i] != '\0'; ++i){
		switch(t[i]){
			case '\t':
				s[i] = 't';
				break;
			case '\n':
				s[i] = 'n';
				break;
			default :
				s[i] = t[i];
				break;
		}
	}
}
