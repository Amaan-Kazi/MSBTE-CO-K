#include <stdio.h>
#include <conio.h>

void main ()
{
	int arr[100], n, i, search, flag = 0, pos;
	clrscr();

	printf("Number of elements: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("%d. ", i);
		scanf("%d", &arr[i]);
	}

	printf("Search Element: ");
	scanf("%d", &search);

	for (i = 0; i < n; i++)
	{
		if (arr[i] == search)
		{
			flag = 1;
			pos = i;
			break;
		}
	}

	if (flag == 1)
		printf("Search Element %d found on index %d", search, pos);
	else
		printf("Search Element %d not found", search);

	getch();
}