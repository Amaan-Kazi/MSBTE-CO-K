#include <stdio.h>
#include <conio.h>

void main ()
{
	int queue[100], f = 0, r = -1, val, input = -1;
	clrscr();

	while (input != 0)
	{
		printf("0. Exit \n");
		printf("1. Enqueue \n");
		printf("2. Dequeue \n");
		printf("3. Display \n");
		printf("Input: ");
		scanf("%d", &input);

		switch (input)
		{
			case 0:
				exit(1);
				break;
			case 1:
				printf("\n Value: ");
				scanf("%d", &val);
			case 2:

			case 3:

			default:
				printf("Invalid \n");
				break;

		}
	}

	getch();
}