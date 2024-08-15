#include <stdio.h>
#include <conio.h>
#include <string.h>

void main ()
{
	int n, i, flag = 0, pos;
	char arr[100][100], search[100];
	clrscr();

	printf("Number of elements: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("%d. ", i);
		fflush(stdin);
		gets(arr[i]);
	}

	printf("Search Element: ");
	fflush(stdin);
	gets(search);

	for (i = 0; i < n; i++)
	{
		if (strcmp(arr[i], search) == 0)
		{
			flag = 1;
			pos = i;
			break;
		}
	}

	if (flag == 1)
		printf("Search Element %s found on index %d", search, pos);
	else
		printf("Search Element %s not found", search);

	getch();
}