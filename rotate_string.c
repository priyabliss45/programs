#include<stdio.h>
#include<stdlib.h>
char *rotate(char *q,int a,int n)
{	
		
	char temp;
	static int count=0;
	
	temp=*q;
	if(*(q+1)&&a!=0)
	{
		
		*q=*(q+1);
		count++;
		
		rotate(q+1,a,n);
		
	}
	
	*(q+n-1)=temp;
	*(q+n)=0;
	
	
	
	
	
	return q;
		
}
char *ro(char *t,int a,int n)
{
	if(a==0)
		return t;
	else
	{
		t=rotate(t,a,n);
		ro(t,a-1,n);
	}
}
	
int main()
{
	int a,count=0;
	char *p=(char *)malloc(sizeof(char));
	printf("enter the string\n");
	scanf("%[^\n]s",p);
	while(*p++)
		count++;	
	p=p-count-1;
	
	printf("Enter the number of rotations required\n");
	scanf("%d",&a);
	printf("%s",ro(p,a%count,count));
	return 0;
}
	
