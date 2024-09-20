#include <stdio.h>
#include <conio.h>

char stack[100];
char revString[100];
int top = -1, max = 10, temp = 0;

void push(char data)
{
	if (top >= max)
	{
		printf("Stack Overflow \n");
		getch();
	}
	else
	{
		top++;
		stack[top] = data;
	}
}

void pop()
{
	if (top <= -1)
	{
		printf("Stack Underflow \n");
		getch();
	}
	else
	{
		revString[temp] = stack[top];
		temp++;
		top--;
	}
}

void main ()
{
	int input = 0, i, n;
	char string[100];
	clrscr();

	printf("String: ");
	fflush(stdin);
	gets(string);

	n = strlen(string);

	for (i = 0; i < n; i++)
	{
		push(string[i]);
	}
	for (i = 0; i < n; i++)
	{
		pop();
	}

	printf("Reverse String\n");
	printf("%s", revString);
	getch();
}