#include<stdio.h>
#include<string.h>
int pallind(char *p,int n)
{
		char *q;
		int i,count=0;
		q=p+n-1;
		while(i<=n/2)
		{
			if(*p==*q)
			{
				
				p=p+1;
				q=q-1;
			}
			else
			{
				count=1;
				break;
			}
			i++;
		}
		if(count==0)
			return 1;
		else
			return 0;
}
void sub(char *q,int n)
{
	int i,j,k,l;
	char a[10];
	for(i=0;i<n;i++)
	{
		for(j=n-1;j>=0;j--)
		{
			for(k=i;k<=j;k++)
			{
				a[k]=q[k];
			}
			if(pallind(&a[i],k))
			{
				printf("%s",a);
				printf("\n");
			}
			for(l=0;l<k;l++)
			{
				
				a[l]=0;
			}
			
		}
		
		
	}
}	


int main()
{
	char a[50];
	int b;
	printf("Enter the string");
	scanf("%[^\n]s",a);
	b=strlen(a);
	sub(a,b);
	return 0;
}
	
