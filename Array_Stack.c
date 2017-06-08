// Stack using array.


#include <stdio.h>

#define SIZE 100

double buf[SIZE];  
int bufp = 0;     

void push(double a)
{
	if (bufp < SIZE)
		buf[bufp++] = a;
	else
		printf("Stack is full.\n");
}

double pop(void)
{
	if (bufp > 0)
		return buf[--bufp];
	else{
		printf("Stack is empty.\n");
		return 0.0;
	}
}

int main(void)
{
	double c;
	int a;
	
	while(1){
		scanf("%lf", &c);
			
		if (c == 0)
			break;
		push(c);
	}
	
	a = bufp;
	while (a-- > 0)
		printf("%.2lf\n", pop());
	
	return 0;
}
