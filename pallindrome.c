#include<stdio.h>
#include<stdbool.h>  
bool pallindrome(int n)
{
int a=n;
int r=0,x;
while(n>0)
{
 x=n%10;
 r=r*10+x;
n=n/10;
}
if(a==r)
return true;
else if(n<0)
return false;
else
return false;
}
int main()
{
 int n;
scanf("%d",&n);
bool x=pallindrome(n);
if(x==true)
printf("PALLINDROME");
else
printf("NOT PALLINDROME");
return 0;
}
