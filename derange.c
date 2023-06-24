#include<stdio.h>
int derange(int a)
{
	if(a==0)
		return 1;
	if(a==1)
		return 0;
	return((a-1)*(derange(a-1)+derange(a-2)));
}
int main()
{
	int a;
	scanf("%d",&a);
	printf("%d",derange(a));
	return 0;
}
