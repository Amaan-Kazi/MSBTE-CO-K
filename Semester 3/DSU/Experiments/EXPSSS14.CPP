#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node {
	int coefficient;
	int power;
	struct node*link;
};

void main()
{
       int c,p;
	clrscr();

	struct node*first =(struct node*)malloc(sizeof(struct node));
	first->coefficient=c;
	first->power=p;

	struct node*sec =(struct node*)malloc(sizeof(struct node));
	sec->coefficient=c;
	sec->power=p;
	first->link=sec;

	struct node*thir =(struct node*)malloc(sizeof(struct node));
	thir->coefficient=c;
	thir->power=p;
	sec->link=thir;

	thir->link = NULL;

	struct node *ptr = first;

	printf("enter the coefficient:");
	scanf("%d",&first->coefficient);

	printf("enter the power:");
	scanf("%d",&first->power);

	printf("enter the coefficient:");
	scanf("%d",&sec->coefficient);

	printf("enter the power:");
	scanf("%d",&sec->power);

	printf("enter the coefficient:");
	scanf("%d",&thir->coefficient);

	printf("enter the power:");
	scanf("%d",&thir->power);

	struct node*fot=(struct node*)malloc(sizeof(struct node));
	fot->coefficient=c;
	fot->power=p;

	struct node*fir =(struct node*)malloc(sizeof(struct node));
	fir->coefficient=c;
	fir->power=p;
	fot->link=fir;

	struct node*six =(struct node*)malloc(sizeof(struct node));
	six->coefficient=c;
	six->power=p;
	six->link=NULL;
	fir->link = six;

	struct node *ptr2 = fot;

	printf("enter the coefficient:");
	scanf("%d",&fot->coefficient);

	printf("enter the power:");
	scanf("%d",&fot->power);

	printf("enter the coefficient:");
	scanf("%d",&fir->coefficient);

	printf("enter the power:");
	scanf("%d",&fir->power);

	printf("enter the coefficient:");
	scanf("%d",&six->coefficient);

	printf("enter the power:");
	scanf("%d",&six->power);


	while(ptr!=NULL)
	{
		printf("%dx^%d + ", ptr->coefficient, ptr -> power);

		ptr=ptr -> link;
	}
	printf("\n");

	while (ptr2!=NULL)
	{
		printf("%dx^%d + ", ptr2->coefficient, ptr2 -> power);
		ptr2= ptr2->link;
	}

	getch();
}
