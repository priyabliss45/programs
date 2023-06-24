#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct stack
{
	int capacity;
	int size;
	int top;
	int *arr;
};
struct stack *createstack(int n)
{
	struct stack *t=(struct stack *)malloc(sizeof(struct stack));

	t->arr=(int *)malloc(n*sizeof(int));
	t->top=-1;
	t->capacity=n;
	t->size=0;
	return t;
}
void push(struct stack *s,int ele)
{
	if(s->size==s->capacity)
	{
		printf("Stack overflow");
		return;
	}
	s->arr[++s->top]=ele;
	s->size=s->size+1;
}
int pop(struct stack *s)
{
	int ele;
	if(s->size==0)
	{
		printf("Stack empty");
		return INT_MIN;
	}
	ele=s->arr[s->top--];
	s->size=s->size-1;
	return ele;
}
int peek(struct stack *s)
{
	if(s->size==0)
	{
		printf("Stack empty");
		return INT_MIN;
	}
	return(s->arr[s->top]);
}
int main()
{
	struct stack *s=createstack(5);
	
	push(s,40);
	printf("the top of the stack is %d",peek(s));
	printf("the popped element is %d",pop(s));
	printf("the top of the stack is %d",peek(s));
	free(s);
	return 0;
}
	
