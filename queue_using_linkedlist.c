#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct Node
{
	int data;
	struct Node *next;
};
struct Queue
{
	struct Node *front;
	struct Node *rear;
};
struct Node *new_node(int n)
{
	struct Node *newnode=(struct Node *)malloc(sizeof(struct Node));
	newnode->data=n;
	
	return newnode;
}
struct Queue *createqueue()
{
	struct Queue *t=(struct Queue *)malloc(sizeof(struct Queue));
	t->front=NULL;
	t->rear=NULL;
	return t;
}
void enqueue(struct Queue *t,int data)
{
	struct Node *temp=new_node(data);
	if(t->front==NULL&&t->rear==NULL)
	{
		t->front=temp;
		t->rear=temp;
		
		return;
	
	}
	t->rear->next=temp;
	t->rear=temp;
}
int deQueue(struct Queue *t)
{
	int ele;
	struct Node *temp=t->front;
	if(t->front==NULL&&t->rear==NULL)
	{
		printf("Queue is empty\n");
		return INT_MIN;
	}
	ele=t->front->data;
	t->front=t->front->next;
	free(temp);
	return ele;
}
int printfront(struct Queue *t)
{
	if(t->front==NULL)
	{
		printf("Queue is empty\n");
		return INT_MIN;
	}
	return t->front->data;
}
int printrear(struct Queue *t)
{
	if(t->front==NULL)
	{
		printf("Queue is empty\n");
		return INT_MIN;
	}
	return t->rear->data;
}
			
int main()
{
	struct Queue *t=createqueue();
	
	
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
	printf("The dequeued element is %d\n",deQueue(t));
	
	printf("the front is %d and the rear is %d\n",printfront(t),printrear(t));
	return 0;
}
