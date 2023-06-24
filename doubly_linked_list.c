#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
};
void printlist(struct Node *n)
{
	struct Node *last=NULL;
	printf("Forward traversing");
	while(n!=NULL)
	{
		printf("%d->",n->data);
		last=n;
		n=n->next;
	}
	printf("\n");
	printf("Backward traversing");
	
	while(last!=NULL)
	{
		printf("%d->",last->data);
		last=last->prev;
	}
	printf("\n");
}
void append(struct Node **head_ref,int new_data)
{
	struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
	new_node->data=new_data;
	new_node->next=NULL;
	struct Node *temp=*head_ref;
	if(temp==NULL)
	{
		*head_ref=new_node;
		(*head_ref)->prev=NULL;
		return;
	}
			
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=new_node;
	new_node->prev=temp;
	
	return;
}
void push(struct Node **head_ref,int new_data)
{
	struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
	new_node->data=new_data;
	struct Node *temp=*head_ref;
	if(temp==NULL)
	{
		*head_ref=new_node;
		(*head_ref)->prev=NULL;
		return;
	}
	new_node->next=temp;
	(*head_ref)->prev=new_node;
	*head_ref=new_node;
	(*head_ref)->prev=NULL;
	
	return;
}
void insertafter(struct Node **head_ref,int prev_data,int new_data)
{
	struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
	new_node->data=new_data;
	struct Node *temp=*head_ref;
	if(temp==NULL)
	{
		printf("Cant be inserted");
		return;
	}
	while(temp &&temp->data!=prev_data)
		temp=temp->next;
	if(temp!=NULL)
	{
		new_node->next=temp->next;
		temp->next=new_node;
		new_node->prev=temp;
		temp=new_node->next;
		temp->prev=new_node;
	}
}
void delete(struct Node **head_ref,int dlt_data)
{
	struct Node *temp=*head_ref;
	struct Node *curr=NULL;
	if(temp==NULL)
	{
		printf("Cant be deleted");
		return;
	}
	if(temp->data==dlt_data)
	{
		temp=temp->next;
		*head_ref=temp;
		(*head_ref)->prev=NULL;
	}
	while(temp &&temp->data!=dlt_data)
	{
		curr=temp;
		temp=temp->next;
	}
	if(temp==NULL)
	{
		printf("Cant be deleted");
		return;
	}
	curr->next=temp->next;
	temp=temp->next;
	temp->prev=curr;
	return;
}
		
int main()
{
	struct Node *head=NULL;
	
	
	push(&head,30);
	push(&head,40);
	push(&head,50);
	push(&head,20);
	
	printf("Created list is:");
	printlist(head);
	append(&head,200);
	printf("Created list is:");
	printlist(head);
	insertafter(&head,40,70);
	printf("Created list is:");
	printlist(head);
	delete(&head,50);
	printf("Created list is:");
	printlist(head);
	return 0;
}
