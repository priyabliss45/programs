#include<stdio.h>
int prime(int a)
{
	int i=5;
	if(a==0||a==1)
		return 0;
	
	if(a==2||a==3)
		return 1;
	if(a%2==0||a%3==0)
		return 0;
	for(;i*i<=a;i+=6)
	{
		if(a%i==0||a%(i+2)==0)
			return 0;
	}
	return 1;
	}
	
int main()
{
	int a;
	scanf("%d",&a);
	if(prime(a)) printf("Prime");
	else printf("Not Prime");
	return 0;
}

