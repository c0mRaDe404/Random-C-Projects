#include <stdio.h>
#include <stdlib.h>

int size;
	
struct node{
       struct node *prev;
       int data;
       struct node* next;			
	};
	
	
void printList(struct node* nd)
{
struct node* head;
head = nd;	
printf("\n");
while(head -> next != NULL)
{	
	printf("--->"); 
	printf(" %d ",head ->data);
	head = head ->next;		
	}
	printf("\n");		
	}
	
	
void* createNode(struct node* nd)
{	
		printf("\nEnter the size >> ");
		scanf("%d",&size);				
    	nd = (struct node*)malloc(sizeof(nd)*size);
    	for(int i=0;i<size;i++)
    	{
    		(nd+i) -> next = (nd+i+1);
    		(nd+i+1)-> prev = (nd+i);
   		
    		}    		  				
    		printList(nd);
    	    printf("\nSuccessfully created a list:)");
	        return (void*)nd;
			
	}
	

	
	
void Insert(struct node* nd,int pos,int data)
{
	pos = pos-1;	
	(nd+pos)->data =data;	
	printList(nd);
	printf("Inserted element %d at position %d",data,pos);					
	}
	
void Delete(struct node* nd,int pos)
{
	
	pos = pos-1;	
	struct node* head = nd+pos;	
	while (head->next != NULL)
	{
		(nd+pos-1) -> data = (nd+pos+1) ->data;	
    	(nd+pos-1)->next = (nd+pos+1);
    	(nd+pos+1)->prev = (nd+pos-1);   	
    	head = head ->next;
		
		}			
	printf("\nSucessfully deleted element at position %d",pos); 	
	}
	
	
	

int main()
{	
	int choice,size,opt,pos,data;
	typedef struct node node;	
	node* nd;
	node* new_nd;
		
	do {
				
	printf("\n1.Create\n2.Insert\n3.Delete\n4.Display\n5.Exit\n\n");
	scanf("%d",&choice);
	
	switch(choice)
	{	
		case 1:		
		new_nd = (node*)createNode(nd);			
		break;
		
		case 2:
		printf("\nEnter the position >> ");
	    scanf("%d",&pos);
	    printf("\nEnter the data>> ");
	    scanf("%d",&data);				
		Insert(new_nd,pos,data);		
		break;
		
		case 3:
		printf("\nEnter the position >> ");
	    scanf("%d",&pos);	
		Delete(new_nd,pos);	
		break;
		
		case 4: 
		printList(new_nd);
		break;
		
		case 5:
	    free(new_nd);
		exit(0);
				
	};
	
	printf("\nWanna continue? \nChoose 0 or 1 >> ");
	scanf("%d",&opt);		
	}while(opt != 0);				
}
