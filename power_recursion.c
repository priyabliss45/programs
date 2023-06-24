#include<stdio.h>
int power(int n,int x)
{
if(x==0)
return 1;
else if(x==1)
return n;
else
return(n*power(n,x-1));
}
int main()
{
int n,x;
scanf("%d%d",&n,&x);
printf("%d",power(n,x));
return 0;
}
