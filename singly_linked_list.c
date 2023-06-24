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
void append(struct Node **head_ref,int new_data)
{
	struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
	new_node->data=new_data;
	struct Node *temp=*head_ref;
	if(temp==NULL)
	{
		*head_ref=new_node;
		return;
	}
	new_node->next=temp;
	*head_ref=new_node;
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
	return;
}
		
int main()
{
	struct Node *head=NULL;
	
	printf("Created list is:");
	printlist(head);
	push(&head,30);
	push(&head,40);
	push(&head,50);
	push(&head,20);
	printf("Created list is:");
	printlist(head);
	append(&head,70);
	printf("Created list is:");
	printlist(head);
	insertafter(&head,30,200);
	printf("Created list is:");
	printlist(head);
	delete(&head,30);
	printf("Created list is:");
	printlist(head);
	return 0;
}
