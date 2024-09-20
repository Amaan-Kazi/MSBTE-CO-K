#include <stdio.h>
#include <conio.h>

int stack[100], top = -1, max = 10;

void push(int data)
{
	if (top >= max)
	{
		printf("Stack Overflow \n");
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
	}
	else
	{
		top--;
	}
}

void display()
{
	int i;
	printf("\nStack: \n");
	for (i = top; i >= 0; i--)
	{
		printf("%d\n", stack[i]);
	}
}

void main ()
{
	int input = 0, value;
	clrscr();

	do {
		clrscr();
		printf("0.Exit\n");
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Display\n");

		printf("\nInput: ");
		scanf("%d", &input);

		switch (input)
		{
			case 0:
				break;
			case 1:
				printf("\nValue: ");
				scanf("%d", &value);

				push(value);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				getch();
				break;
			default:
				printf("Invalid\n");
				break;
		}
	} while (input != 0);

	getch();
}