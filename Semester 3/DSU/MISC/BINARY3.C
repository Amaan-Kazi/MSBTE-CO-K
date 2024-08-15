#include <stdio.h>
#include <conio.h>
#include <string.h>

void main ()
{
	int n, i, j = 0, flag = 0;
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

	i = 0;
	start = 0;
	end = n-1;
	mid = (start+end)/2;

	while (start <= end)
	{
		if (strcmp(arr[mid], search) == 0)
		{
			printf("arr[%d] (%s) == %d\n", mid, arr[mid], search);
			j++;
			flag = 1;
			printf("%s found on index %d [%d iterations]\n", search, mid, j);
			break;
		}
		else if (strcmp(arr[mid], search) > 0)
		{
			printf("arr[%d] (%s) > %d\n", mid, arr[mid], search);
			end = mid - 1;
			mid = (start+end)/2;
		}
		else
		{
			printf("arr[%d] (%s) < %d\n", mid, arr[mid], search);
			start = mid + 1;
			mid = (start+end)/2;
		}

		j++;
	}

	if (flag == 1)
	{
		for (i = mid-1; i >= 0; i--)
		{
			if (strcmp(arr[i], search) == 0)
				printf("%s found on index %d [%d iterations]\n", search, i, j);
			else
				break;
		}
		for (i = mid+1; i <= n-1; i++)
		{
			if (strcmp(arr[i], search) == 0)
				printf("%s found on index %d [%d iterations]\n", search, i, j);
			else
				break;
		}
	}
	if (flag == 0)
		printf("Not found [%d iterations]", j);

	getch();
}