#include<stdio.h>
#include<stdlib.h>

struct node
{
	int num;
	struct node*next;
}*start;

typedef struct node NODE;
NODE*start;

void insertatbegin();
void insertatend();
void traverse();
void search();
void insertspe(int item,int loc);
void delbegin();
void delend();
void delspe();
void reverse();

void search()
{
	int item;
	printf("\nenter the item to be searched : ");
	scanf("%d",&item);
	
	NODE*p;
	p=start;
	while(p!=NULL)
	{
		if(item==p->num)
		{
			printf("|%d|",item);
		
			break;
		}
		else
		{
			printf("Not found");
		}
		
		p=p->next;
	}
}
void traverse(NODE*start)
{
	NODE*st;
	st=start;
	while(st->next!=NULL)
	{
		printf("|%d|-",st->num);
		st=st->next;
	}
}

void insertatbegin()
{
	NODE*p;
	int item;
	p=(NODE*)malloc(sizeof(NODE));
	
	printf("\nEnter item : ");
	scanf("%d",&item);
	
	p->num = item;
	if(start==NULL)
    p->next = NULL;	
    else
    p->next=start;
    start = p;
    
   
}
//Function to insert a value in end of the linked list
void insertatend(NODE*start)
{
	NODE*p,*loc;
	int item;
	p = (NODE*)malloc(sizeof(NODE));
	if(!p){printf("Meemory not allocated");}
	
	
	printf("\nEnter item : ");
	scanf("%d",&item);
	
	p->num = item;
	p->next = NULL;
	
	if(start == NULL) //checking the condition that the there is any value exist or not
	{
	start= p;
	}
	
	else
	{
	loc = start;
	while(loc->next!=NULL)
	{
		loc = loc->next;
	}
	loc->next = p;
	}
}

//Insert the value at specific place

void insertspe(int item ,int loc)
{
	NODE*p,*temp;
	int k;
	temp=start;
	
	for(k=0;k<loc-2;k++)
	{
		temp = temp->next;
		if(temp==NULL)
		{printf("Node in the list less than one");}
			
	}
	p= (NODE*)malloc(sizeof(NODE));
	p->num = item; 
	p->next=temp->next;
		temp->next=p;
	
}



void main()
{
	int item,ch,loc;
	
	//Allocate memory for header node.
	start = (struct node *)malloc(sizeof(struct node));
	
	start->next = NULL;
	while(ch!=100)
	{
	printf("\n1.Insert at begining.\n2.Insert at end.\n3.Insert at specific.\n4.Traverse the list\n5.Delete begin\n6.Delete end\n");
	printf("7.Delete specific.\n8.Search\n9.Reverse\n10.exit");
	
	printf("\nEnter the choice :");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			insertatbegin(); // call for insert at begin
			break;
			
			case 2:
			insertatend(start); // call for insert at end but some problem
			break;
			
			case 3:
			printf("Enter the item  :");
			scanf("%d",&item);
			printf("\nEnter the location : ");
			scanf("%d",&loc);
			if(loc==1)
			{
				printf("It is start  point");
				break;
			}
		
			insertspe(item,loc);	
			break;
			
			case 4:
			traverse(start);
			break;
			case 5:
				delbegin(start);
				break;
				
			case 6:
				delend(start);
				break;
			case 7:
				delspe(start);
				break;
				case 8:
					search();
					break;
				case 9:
					 reverse(&start);
					break;
				case 10:
				exit(0);
				break;
				
			
	}
	}
	
}

void delbegin(NODE*start) //Deleting the value from starting 
{
	NODE*p;
	
	if(start==NULL)
	{
		printf("\nList is empty");
	}
	
	else
	{
		p=start;
		start= start->next;
		printf("\nThe item is deleted is %d",p->num);
		free(p);
	}
}

void delend(NODE*start) //This is function deleting the value from end of the linked list
{
	NODE*p,*loc;
	
	if(start==NULL)
	{
		printf("\nList is empty");
	}
	
	else if(start->next==NULL)
	{
		p=start;
		start=NULL;
		printf("\nThe item is deleted is %d",p->num);
		free(p);
	}
	
	else
	{
		loc = p = start;
		while(p->next!=NULL)
		{
				loc = p;
				p=p->next;
		}
		loc->next = NULL;
		printf("\nThe item is deleted is %d",p->num);
		free(p);
		
	}
}

void delspe(NODE*start) //Deleting from specific point 
{
	NODE*p,*tmp;
	int k,loc;
	printf("\nEnter the location for deleting that value : ");
	scanf("%d",&loc);
	--loc;
	
		if(start==NULL)
	{
		printf("\nList is empty");
	}
	
	else
	{
		p=tmp=start;
		for(k=0;k<loc;k++)
		{
			p=tmp;
			tmp=tmp->next;
		}
		p->next = tmp->next;
		printf("\nThe item is deleted is : %d",tmp->num);
		free(tmp);
	}
}

void reverse(NODE**start)
{
	NODE*current,*next,*prev;
	current=start;
	prev=NULL;
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;	
	}
	*start=prev;
	
}


