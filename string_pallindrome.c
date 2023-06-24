#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
struct stack
{
	int capacity;
	int size;
	int top;
	char *arr;
};
struct stack *createstack(int n)
{
	struct stack *t=(struct stack *)malloc(sizeof(struct stack));

	t->arr=(char *)malloc(n*sizeof(char));
	t->top=-1;
	t->capacity=n;
	t->size=0;
	return t;
}
void push(struct stack *s,char ele)
{
	if(s->size==s->capacity)
	{
		printf("Stack overflow");
		return;
	}
	s->arr[++s->top]=ele;
	s->size=s->size+1;
}
char pop(struct stack *s)
{
	char ele;
	if(s->size==0)
	{
		printf("Stack empty\n");
		return CHAR_MIN;
	}
	ele=s->arr[s->top--];
	s->size=s->size-1;
	return ele;
}
char peek(struct stack *s)
{
	if(s->size==0)
	{
		printf("Stack empty\n");
		return CHAR_MIN;
	}
	return(s->arr[s->top]);
}
int palli(struct stack *s,char *str,int x)
{
	
	int i=0;
	while(i<x)
	{
		
		push(s,str[i]);
		i++;
	
	}
	i=0;
	while(i<x/2)
	{
		if(str[i]!=pop(s))
			return 0;
		else 
			i++;
	}
	return 1;
}
	
int main()
{
	char a[100];
	int x;
	printf("Enter the string\n");
	scanf("%[^\n]s",a);
	x=strlen(a);
	struct stack *s=createstack(x);
	if(palli(s,a,x))
		printf("String is pallindrome");
	else
		printf("Not pallindrome");
	
	return 0;
}
	
