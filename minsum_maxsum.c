#include <stdio.h>
void minmaxsum(int n,int *a)
{
	int i,j,max,min,s=0,s1=0;
	max=a[0];
	min=a[0];
	
	for(i=1;i<n;i++)
	{
	if(max>s && s<a[i])
		s=a[i];
	if(max<a[i]){
		s=max;
		max=a[i];
		}
	if(min<s1 && s1>a[i])
		s1=a[i];
	
	if(min>a[i]){
		s1=min;
		min=a[i];
	
		
	}
	
	
		}
	a[0]=min+s1;					a[n-1]=max+s;			
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
	minmaxsum(n,a);
	printf("The minimum sum is \n%d",a[0]);
	printf("The maximum sum is \n%d",a[n-1]);	
}
			
