#include<stdio.h>
#include<stdlib.h>
int  freq(char *q,char b)
{
	int c;
	
	if(*p==0)
		return 0;
	
	if(*p==b)
		c=freq(p+1)+1;
	else
		c=freq(p+1);
	return c;
}
int main()
{
	int a;
	char *p=(char *)malloc(100*sizeof(char));
	printf("Enter the string");
	scanf("%[^\n]s",p);
	while(*p)
	{
		if(*p==' ')
			p=p+1;
		a=freq(p,*p);
		printf("the frequency of %c is %d",*p,a);
		p++;
	}
	return  0;
}
	
