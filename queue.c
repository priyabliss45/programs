#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct Queue
{
	int capacity;
	int size;
	int front;
	int rear;
	int *arr;
};
struct Queue *createQueue(int a)
{
	struct Queue *t=(struct Queue *)malloc(sizeof(struct Queue));
	t->arr=(int *)malloc(a*sizeof(int));
	t->capacity=a;
	t->size=0;
	t->front=-1;
	t->rear=-1;
	return t;
}
void enqueue(struct Queue *t,int new_data)
{
	if(t->size==t->capacity)
	{
		printf("Queue overflow\n");
		return;
	}
	if(t->front==-1&&t->rear==-1)
	{
		t->front++;
		t->rear++;
		t->arr[t->rear]=new_data;
		t->size++;
		return;
	}
	t->rear=(t->rear+1)%t->capacity;
	t->arr[t->rear]=new_data;
	t->size++;
}
int deQueue(struct Queue *t)
{
	int ele;
	
	if(t->size==0)
	{
		printf("Queue is empty\n");
		return INT_MIN;
	}
	ele=t->arr[t->front];
	t->front=(t->front+1)%t->capacity;
	t->size=t->size-1;
	
	return ele;
}
	
int printfront(struct Queue *t)
{
	if(t->size==0)
	{
		printf("Queue is empty\n");
		return INT_MIN;
	}
	return t->arr[t->front];
}
int printrear(struct Queue *t)
{
	if(t->size==0)
	{
		printf("Queue is empty\n");
		return INT_MIN;
	}
	return t->arr[t->rear];
}
int main()
{
	int a;
	printf("Enter the size \n");
	scanf("%d",&a);
	struct Queue *t=createQueue(a);
	enqueue(t,10);
	enqueue(t,20);
	enqueue(t,30);
	enqueue(t,40);
	enqueue(t,50);
	printf("the front is %d and the rear is %d\n",printfront(t),printrear(t));
	printf("The dequeued element is %d\n",deQueue(t));
	printf("The dequeued element is %d\n",deQueue(t));
	printf("The dequeued element is %d\n",deQueue(t));
	printf("The dequeued element is %d\n",deQueue(t));
	
	printf("the front is %d and the rear is %d\n",printfront(t),printrear(t));
	return 0;
}
