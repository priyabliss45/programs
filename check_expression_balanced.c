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
int matchstr(char a,char b)
{
	if(a=='('&&b==')')
		return 1;
	if(a=='{'&&b=='}')
		return 1;
	if(a=='['&&b==']')
		return 1;
	return 0;
}
int bal(struct stack *s,char *str,int x)
{
	
	int i=0;
	while(str[i])
	{
		if(str[i]=='('||str[i]=='{'||str[i]=='[')
			push(s,str[i]);
		if(str[i]==')'||str[i]=='}'||str[i]==']')
		{
			if(s==NULL)
				return 0;
			if(!matchstr(pop(s),str[i]))
				return 0;
		}	
		i++;
	
	}
	if(s==NULL)
		return 1;
	else
		return 0;
	
}
	
int main()
{
	char a[100];
	int x;
	printf("Enter the string\n");
	scanf("%[^\n]s",a);
	x=strlen(a);
	struct stack *s=createstack(x);
	if(bal(s,a,x))
		printf("expression is balanced");
	else
		printf("expression is not balanced");
	
	return 0;
}
	
