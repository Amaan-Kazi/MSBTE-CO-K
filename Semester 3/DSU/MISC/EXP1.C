#include <stdio.h>
#include <conio.h>

int arr[100], n;

void printArray()
{
	int i;
	printf("\nNew Array:\n");
	for(i = 0; i < n; i++)
	{
		printf("%d. %d\n", i, arr[i]);
	}
}

void addElement(pos, num)
{
	int i;
	for(i = n; i > pos; i--)
	{
		arr[i] = arr[i-1];
	}
	arr[pos] = num;
	n++;
}

void main ()
{
	int i, pos, num;

	clrscr();
	printf("Number of elements: ");
	scanf("%d", &n);

	printf("Enter elements of array\n");
	for (i = 0; i < n; i++)
	{
		printf("%d.", i);
		scanf("%d", &arr[i]);
	}

	printf("\nEnter the position (index) and value of element to add\n");
	printf("Position: ");
	scanf("%d", &pos);
	printf("Value: ");
	scanf("%d", &num);

	addElement(pos, num);

	printArray();

	printf("Position to delete value: ");
	scanf("%d", &pos);

	for (i = pos; i < n; i++)
	{
		arr[i] = arr[i+1];
	}
	arr[n] = 0;
	n--;

	printArray();

	getch();
}