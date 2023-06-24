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

void swap(struct Node** head_ref,int x, int y)
{
  
    	if (x == y)
        		return;
 
    	struct Node *prevX = NULL, *currX = *head_ref;
    	while (currX && currX->data != x)
    	{
    		    prevX = currX;
    		    currX = currX->next;
    	}
 
   
    	struct Node *prevY = NULL, *currY = *head_ref;
    	while (currY && currY->data != y)
    	{
      		  prevY = currY;
     		  currY = currY->next;
    	}
 
 
    	if (currX == NULL || currY == NULL)
     		   return;
 
    
    	if (prevX != NULL)
    		    prevX->next = currY;
   	else
 		    *head_ref = currY;
 
    	if (prevY != NULL)
     		    prevY->next = currX;
    	else
     		*head_ref = currX;
 
    	struct Node* temp = currY->next;
    	currY->next = currX->next;
    	currX->next = temp;
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
	swap(&head,30,50);
	printf("Created list is:");
	printlist(head);
	return 0;
}
