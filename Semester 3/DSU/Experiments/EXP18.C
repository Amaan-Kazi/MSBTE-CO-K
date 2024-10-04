#include<stdio.h>
#include<conio.h>

int multiply(int x , int y , int multi){
	if (y <= 0)
	{
		return multi;
	}
	else {
		multi = multi + x;
		return multiply (x,y-1,multi);
	}
}
void main ()
{
	int a;
	int b;
	clrscr();

	printf("A: ");
	scanf("%d",&a);

	printf("B: ");
	scanf("%d",&b);

	printf("Multiplication = %d",multiply(a,b,0));

	getch();
}