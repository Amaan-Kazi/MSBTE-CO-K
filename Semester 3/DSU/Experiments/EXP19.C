#include<stdio.h>
#include<conio.h>
#include<string.h>

char *reverse (char str[100], int i, int len)
{
	if(i >= len/2)
	{
		return str;
	}
	else
	{
		char temp = str[i];
		str[i] = str[len-1-i];
		str[len-1-i] = temp;

		reverse(str, i+1, len);
	}
return str;
}

void main ()
{
	char s[100];
	clrscr();

	printf("String: ");
	fflush(stdin);
	gets(s);

	printf("Reversed string: ");
	puts(reverse(s, 0, strlen(s)));

	getch();
}