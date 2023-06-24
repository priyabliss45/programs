#include<stdio.h>
#include<string.h>
int main()
{
char a[15];
int b=0;
scanf("%s",a);
for(int i=0;i<strlen(a);i++)
{

if(a[i]=='I')
{
if(a[i+1]=='I')
b+=1;
else if(a[i+1]=='X'||a[i+1]=='V')
{
b+=-1;

}
else
b+=1;
}
else if(a[i]=='V')
	b+=5;
else if(a[i]=='X')
{

if(a[i+1]=='X')
{

b+=10;
}else if (a[i+1]=='I'||a[i+1]=='V')
b+=10;
else if(a[i+1]=='L' ||a[i+1]=='C')
b-=10;
else 
b+=10;
}
else if(a[i]=='L')
	b+=50;
else if(a[i]=='C')
{
if(a[i+1]=='C')
b+=100;
else if (a[i+1]=='D'||a[i+1]=='M')
b-=100;
else if(a[i+1]!='D'||a[i+1]!='M')
b+=100;
else
b+=100;
}
else if(a[i]=='D')
	b+=500;
else
b+=1000;

}
printf("%d",b);
return 0;
}
