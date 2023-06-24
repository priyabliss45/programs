#include <stdio.h>
void wave(int n,int *a)
{
	int i,j,m;
	
	for(i=0;i<n;i++)
	{
		m=a[i];
		for(j=i;j<n;j++)
		{
			if(i%2==0)
			{
				if(m<a[j])
				{
					m=a[j];
					a[j]=a[i];
					a[i]=m;
				}
			}
			else
			{
				if(m>a[j])
				{
					m=a[j];
					a[j]=a[i];
					a[i]=m;
				}
			}
		}
	}		
}
	void main()
	{
	int n,i;
	printf("enter the size of an array");
	scanf("%d",&n);
	int a[n];
	printf("enter  array elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	wave(n,a);
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}	
	}
			
