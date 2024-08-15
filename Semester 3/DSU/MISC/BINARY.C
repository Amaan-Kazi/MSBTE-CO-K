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

	i = 0;
	start = 0;
	end = n-1;
	mid = (start+end)/2;

	while (start <= end)
	{
		if (arr[mid] == search)
		{
			printf("arr[%d] (%d) == %d\n", mid, arr[mid], search);
			i++;
			flag = 1;
			break;
		}
		else if (arr[mid] > search)
		{
			printf("arr[%d] (%d) > %d\n", mid, arr[mid], search);
			end = mid - 1;
			mid = (start+end)/2;
		}
		else
		{
			printf("arr[%d] (%d) < %d\n", mid, arr[mid], search);
			start = mid + 1;
			mid = (start+end)/2;
		}

		i++;
	}

	 if (flag == 0)
		printf("Not found [%d iterations]", i);
	else
		printf("%d found on index %d [%d iterations]", search, mid, i);

	getch();
}