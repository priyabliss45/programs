#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
void printlist(struct Node *n)
{
	if(n==NULL)
	{
		printf("list is empty\n");
		return;
	}
	while(n!=NULL)
	{
		printf("%d->",n->data);
		n=n->next;
	}
	printf("\n");
}
void push(struct Node **head_ref,int new_data)
{
	struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
	new_node->data=new_data;
	new_node->next=NULL;
	struct Node *temp=*head_ref;
	if(temp==NULL)
	{
		*head_ref=new_node;
		return;
	}
			
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=new_node;
	
	return;
}
void sort(struct Node **head_ref)
{
	int temp;
	struct Node *cur=(*head_ref);
	struct Node *next=NULL;
	
	while(cur!=NULL)
	{
		next=cur->next;
		while(next!=NULL)
		{
			
			if(cur->data>next->data)
			{
				temp=cur->data;
				cur->data=next->data;
				next->data=temp;
			}
			next=next->next;
		}
		cur=cur->next;
	}
	
	
	
}
		
int main()
{
	struct Node *head=NULL;
	struct Node *first=head;
	struct Node *last=head;
	printf("Created list is:");
	printlist(head);
	push(&head,30);
	push(&head,40);
	push(&head,50);
	push(&head,20);
	printf("Created list is:");
	printlist(head);
	sort(&head);
	printf("Created list is:");
	printlist(head);
	return 0;
}
