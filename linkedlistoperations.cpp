// linkedlistoperations.cpp: Rajat Gupta
// Description: a program that do opeartion like create,delete,search and traverse on a linked list.

#include<stdlib.h>
#include<stdio.h>


int ch;
struct node {
	int data;
	struct node* link;
};

struct node* root=NULL;

void append() {
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the value \n");
	scanf("%d",&temp->data);

	temp->link=NULL;
	if(root==NULL) {
		root=temp;
	} else {
		struct node* p;
		p=root;
		while(p->link!=NULL) {
			p=p->link;
		}
		p->link=temp;
	}

}

int length() {
	struct node* p;
	p=root;
	int count=0;
	if(p==NULL) {

		return 0;
	} else {

		while(p!=NULL) {
			p=p->link;
			count++;

		}

		return count;
	}
}
void search() {
	int ele;
	struct node* p;
	p=root;

	if(p==NULL) {
		printf("Linkedlist is empty,there is no such element \n ");
	} else {
		printf("Enter Element you want to search:");
		scanf("%d", &ele);
		int count=1;
		int exit_flag = 1;
		while(exit_flag) {
			if(p->data == ele) {
				exit_flag = 1;
				break;
			} else {
				if(p->link==NULL) exit_flag = 0;
			}
			p=p->link;
			count++;

		}
		if (exit_flag) {
			printf("the element is at the position %d  \n",count);
		} else {
			printf("Element not found \n");
		}
	}
}
void display() {
	struct node* p;
	p=root;
	if(p==NULL) {
		printf("Sorry Linkedlist is Empty, No Element to display \n");

	} else {
		while(p!=NULL) {
			printf("->%d ",p->data);
			p=p->link;
		}
	}
}

void access() {

}

void addAtBegin() {
	if(root==NULL) {
		printf("Linkedlist is Empty \n");
		append();
	} else {

		struct node* temp;
		temp=(struct node*)malloc(sizeof(struct node));
		temp->link=root;
		printf("Enter data you want to insert \n");
		scanf("%d",&temp->data);
		root=temp;
	}
}

void addAtAnyPlace() {
	int loc,i=0;
	printf("Enter the location after which you want to enter the data \n");
	scanf ("%d",&loc);
	if(loc>length()) {
		printf("Enter the location again in %d limit",length());
		exit(0);
	} else if(loc==1) {
		printf("Linkedlist is empty");
		append();
	}

	else if(loc==length()) {
		append();
	} else {
		struct node* temp;
		struct node* p;
		p=root;
		temp=(struct node*)malloc(sizeof(struct node));

		while(i<loc) {
			p=p->link;
			i++;
		}
		printf("Enter data youu want to insert");
		scanf("%d",&temp->data);
		temp=p->link;
		p=temp;
	}
}

deletefromfirst() {
	if(root==NULL) {
		printf("linkedlist is empty \n");
	}

	else {
		struct node* p;
		p=root;
		printf("Deleted Element is: %d \n",p->data);
		root=p->link;
		p->link=NULL;
		free(p);
	}
}

pop(int loc)
{
	
	if(loc>length())
	{
		printf("you enetred the wrong location \n");
	}
	
	else
	{
		struct node *p=root,*q;
		int i=1;
		while(i<loc-1)
		{
			p=p->link;
			i++;
		}
		q=p->link;
		p->link=q->link;
		q->link=NULL;
		free(q);
	}
}

void access(int r)
{
	
if(root=NULL)
    {
     printf("There is no element to access");
    }
else
    {
    	int i=1;
    	struct node* p;
    	p=root;
    	while(i<r)
    	{
    	p=p->link;
    	i++;
    	}
    	printf("Accessed data is %d ",p->data);
	}	
}
int main() {

	while(1) {
		printf("Single Linked list Operations : \n");
		printf("1.Append\n");
		printf("2.AddAtBegin\n");
		printf("3.AddAtAnyPlace\n");
		printf("4.Length\n");
		printf("5.Search\n");
		printf("6.Access\n");
		printf("7.Disply\n");
		printf("8.Delete from first Place\n");
		printf("9.Delete at any place or last \n");
		printf("10.Quit\n");
		printf("Enter your Choice : ");
		scanf("%d",&ch);

		switch(ch) {
			case 1:
				append();
				break;

			case 2:
				addAtBegin();
				break;

			case 3:
				addAtAnyPlace();
				break;

			case 4:
				int len;
				len =length();
				printf("length of the linkedlist is: %d \n",len);
				break;

			case 5:
				search();
				break;

			case 6:
				int loc;
				printf("enter the location:");
				scanf("%d",&loc);
				access(loc);
				break;

			case 7:
				display();
				break;

			case 8:
				deletefromfirst();
				break;
           
		    case 9:
		    	int place;
		    	printf("enter the place of the element you want to delete");
		    	scanf("%d",&place);
		    	pop(place);
		    	break;
	    

			case 10:
				exit(0);

			default :
				printf("You entered the wrong choice \n \n");
				break;
		}
	}

	return 0;
}



