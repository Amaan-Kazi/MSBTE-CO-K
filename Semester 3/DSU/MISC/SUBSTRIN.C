#include <stdio.h>
#include <conio.h>
#include <string.h>

void main ()
{
	int i, n, flag = 0;
	char strings[100][100], substring[100];
	clrscr();

	printf("Number of elements: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("%d. ", i);
		fflush(stdin);
		gets(strings[i]);
	}

	printf("Search Substring: ");
	fflush(stdin);
	gets(substring);

	for (i = 0; i < n; i++)
	{
		if (strstr(strings[i], substring) != NULL)
		{
			flag = 1;
			printf("%s found in %s \n", substring, strings[i]);
		}
	}

	if (flag == 0)
	{
		printf("Not found");
	}

	getch();
}