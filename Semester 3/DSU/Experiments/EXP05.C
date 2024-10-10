#include <stdio.h>
#include <conio.h>
#include <string.h>

void main ()
{
	int n, i, flag = 0;
	int start, mid, end;
	char arr[100][100], search[100];
	clrscr();

	printf("Number of elements: ");
	scanf("%d", &n);

	printf("Enter sorted array \n");
	for (i = 0; i < n; i++)
	{
		printf("%d. ", i);
		fflush(stdin);
		gets(arr[i]);
	}

	printf("Search element: ");
	fflush(stdin);
	gets(search);

	start = 0;
	end = n-1;
	mid = (start+end)/2;

	while (start <= end)
	{
		if (strcmp(arr[mid], search) == 0)
		{
			flag = 1;
			break;
		}
		else if (strcmp(arr[mid], search) > 0)
		{
			end = mid - 1;
			mid = (start+end)/2;
		}
		else
		{
			start = mid + 1;
			mid = (start+end)/2;
		}
	}

	if (flag == 0)
		printf("Not found");
	else
		printf("%s found on index %d\n", search, mid);

	getch();
}