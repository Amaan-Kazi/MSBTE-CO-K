#include <stdio.h>
#include <conio.h>

struct node {
	int data;
	struct node *link;
};

void main ()
{
	struct node *first = malloc(sizeof(struct node));
	struct node *second = malloc(sizeof(struct node));
	struct node *third = malloc(sizeof(struct node));
	struct node *head = first;
	struct node *ptr;
	struct node *temp;
	int search, flag = 0;

	clrscr();

	first->data = 20;
	first->link = NULL;
	head->link = first;

	second->data = 30;
	second->link = NULL;
	first->link = second;

	third->data = 40;
	third->link = NULL;
	second->link = third;

	temp->data = 10;
	temp->link = head;
	head = temp;
	ptr = head;

	printf("Search Element: ");
	scanf("%d", &search);

	while(ptr != NULL)
	{
		if (ptr->data == search)
		{
			flag = 1;
			printf("Found \n");
			break;
		}

		ptr = ptr->link;
	}

	if (flag == 0)
		printf("Not Found\n");

	printf("Linked List: \n");

	ptr = head;
	while(ptr != NULL)
	{
		printf("%d \n", ptr->data);
		ptr = ptr->link;
	}

	getch();
}