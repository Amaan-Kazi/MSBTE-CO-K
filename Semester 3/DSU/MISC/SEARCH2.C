#include <stdio.h>
#include <conio.h>

void main ()
{
	int arr[100], n, search, i, flag = 0;
	clrscr();

	printf("Number of elements: ");
	scanf("%d", &n);

	printf("Enter array \n");
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
			printf("Found on index %d \n", i);
		}
	}

	if (flag == 0)
	{
		printf("Not found");
	}

	getch();
}