#include<stdio.h>
#include<stdlib.h>
int reverse(char *q)
{	int count;
	if(*q==' ')
		count=0;
	else if(*q==0)
		count=0;
	else
		count=reverse(q+1)+1;
	if(count)
		putchar(*q);
		


	return count;
}
	
int main()
{
	int a;
	char *p=(char *)malloc(100*sizeof(char));
	printf("Enter the string");
	scanf("%[^\n]s",p);
	while(*p)
	{
		a=reverse(p);
		p=p+a;
		if(*p==' ')
		{
			printf(" ");
			p=p+1;
		}
			
	}
}
