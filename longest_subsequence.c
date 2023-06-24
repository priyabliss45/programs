#include<stdio.h>
#include<string.h>
int longest(char *p,char *q)
{
	int n=0,i,j,m;
	
	i=0;
	while(p[i])
	{
		m=i;
		j=0;
		while(q[j])
		{
			if(p[i]==q[j])
			{
				
				
				n++;
				j++;
				i++;
			}
			else
				j++;
			
		}
		i=m;
		i++;
	}
	return n;
}	
			
int main()
{
	char a[100],b[100];
	printf("Enter  first string");
	scanf("%s",a);
	printf("%s",a);
	printf("\nEnter  second string");
	scanf("%s",b);
	printf("%s",b);
	printf("\nThe longest subsequence is of the length %d\n",longest(a,b));
	return 0;
}
