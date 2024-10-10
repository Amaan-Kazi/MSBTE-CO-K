#include <stdio.h>
#include <conio.h>

void main ()
{
	int arr[100], search, n, i, flag = 0;
	int start, mid, end;
	clrscr();

	printf("Number of elements: ");
	scanf("%d", &n);

	printf("Enter sorted array \n");
	for (i = 0; i < n; i++)
	{
		printf("%d. ", i);
		scanf("%d", &arr[i]);
	}

	printf("Search element: ");
	scanf("%d", &search);

	start = 0;
	end = n-1;
	mid = (start+end)/2;

	while (start <= end)
	{
		if (arr[mid] == search)
		{
			flag = 1;
			break;
		}
		else if (arr[mid] > search)
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
		printf("%d found on index %d", search, mid);

	getch();
}