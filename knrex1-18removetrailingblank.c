#include <stdio.h>

#define MAXLINE 1000


int getline(char s[], int max);
void copy(char from[]);

main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];
	
	max = 0;
	while((len = getline(line, MAXLINE)) > 0){
		//if (len > max){
		//	max = len;
		copy(line);
		printf("%s", line);	
	}
	//if (max > 0)
		
	return 0;
}

int getline(char s[], int lim)
{
	int c, i;
	
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n'){
		s[i] = c;
		++i;
	}
	
	s[i] = '\0';
	return i;
}

void copy(char from[])
{
	int i;
	
	i = 0;
	while (from[i] != '\0'){
		if (from[i] == ' ' || from[i] == '\t')
			if (from[++i] == ' ' || from[i] == '\t')
				from[i] = '\b';
		++i;
	}
	
	//i = 0;
	/*while ((to[i] = from[i]) != '\0')
		++i;*/
}