#include<limits.h>
#include<stdio.h>
int main()
{
int n;
scanf("%d",&n);
int a[n];
int f,s,t=INT_MIN;
for(int i=0;i<n;i++)
{
scanf("%d",&a[i]);
int x=a[i];
if(x>t)
{
t=s;
s=f;
f=x;}
else if(x>s &&x!=f)
{
t=s;
s=x;
}
else
t=x;
}
printf("%d,%d,%d",f,s,t);
return 0;
}
