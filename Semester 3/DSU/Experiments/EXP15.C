#include<stdio.h>
#include<conio.h>

struct node {
	int coefficient;
	int power;
	struct node *link;
};

struct node* NewNode(int coefficient, int power)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->coefficient = coefficient;
	temp->power = power;
	temp->link = NULL;
	return temp;
}

void main()
{
	struct node *head1 = NULL;
	struct node *prev1 = NULL;
	struct node *ptr1, *nptr1;

	struct node *head2 = NULL;
	struct node *prev2 = NULL;
	struct node *ptr2, *nptr2;

	int i = 0, tempCoefficient, tempPower;
	clrscr();

	printf("Polynomial 1 [Enter 0 to stop] \n\n");
	while(1)
	{
		struct node *newNode;
		scanf("%d", &tempCoefficient);

		if (tempCoefficient == 0)
		{
			printf("x^0");
			break;
		}
		else
		{
			printf("x^");
			scanf("%d", &tempPower);

			newNode = NewNode(tempCoefficient, tempPower);
		}

		if (head1 == NULL)
			head1 = newNode;
		else
			prev1->link = newNode;

		prev1 = newNode;
		printf("\n");
	}

	printf("\n\nPolynomial 2 [Enter 0 to stop] \n\n");
	while(1)
	{
		struct node *newNode;
		scanf("%d", &tempCoefficient);

		if (tempCoefficient == 0)
		{
			printf("x^0");
			break;
		}
		else
		{
			printf("x^");
			scanf("%d", &tempPower);

			newNode = NewNode(tempCoefficient, tempPower);

		}

		if (head2 == NULL)
			head2 = newNode;
		else
			prev2->link = newNode;

		prev2 = newNode;
		printf("\n");
	}

	ptr1 = head1;
	// Sort the linked list
	while (ptr1 != NULL)
	{
		nptr1 = head1;

		while (nptr1->link != NULL)
		{
			if (nptr1->power <= nptr1->link->power)
			{
				tempPower = nptr1->power;
				tempCoefficient = nptr1->coefficient;

				nptr1->power = nptr1->link->power;
				nptr1->coefficient = nptr1->link->coefficient;

				nptr1->link->power = tempPower;
				nptr1->link->coefficient = tempCoefficient;
			}
			nptr1 = nptr1->link;
		}

		ptr1 = ptr1->link;
	}

	ptr2 = head2;
	// Sort the linked list
	while (ptr2 != NULL)
	{
		nptr2 = head2;

		while (nptr2->link != NULL)
		{
			if (nptr2->power <= nptr2->link->power)
			{
				tempPower = nptr2->power;
				tempCoefficient = nptr2->coefficient;

				nptr2->power = nptr2->link->power;
				nptr2->coefficient = nptr2->link->coefficient;

				nptr2->link->power = tempPower;
				nptr2->link->coefficient = tempCoefficient;
			}
			nptr2 = nptr2->link;
		}

		ptr2 = ptr2->link;
	}

	printf("\n\nPolynomial 1: ");
	ptr1 = head1;
	while (ptr1->link != NULL)
	{
		printf("%dx^%d + ", ptr1->coefficient, ptr1->power);
		ptr1 = ptr1->link;
	}
	printf("%dx^%d\n", ptr1->coefficient, ptr1->power);

	printf("Polynomial 2: ");
	ptr2 = head2;
	while (ptr2->link != NULL)
	{
		printf("%dx^%d + ", ptr2->coefficient, ptr2->power);
		ptr2 = ptr2->link;
	}
	printf("%dx^%d\n", ptr2->coefficient, ptr2->power);

	getch();
}