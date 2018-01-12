#include <stdio.h>
#include <stdlib.h>

struct node
{
   int data;
   struct node *prev;
   struct node *next;
};
typedef struct node Node;

Node *get_new_node()
{
    Node *p;
    p = (Node *)malloc(sizeof(Node));
    return p;
}

void insert(Node **llist, int x)
{
   Node *p = get_new_node();
   p->data = x;
   if((*llist) == NULL)
   {
       p->next = NULL;
       p->prev = NULL;
       (*llist) = p;
   }
   else if((*llist)->data >x)
	{
	   p->next = (*llist);
       p->prev = NULL;
       (*llist)->prev = p;
       (*llist) = p;
	}
   else
   {
      Node *q = *llist;
      while(q->next != NULL && q->next->data < x)
      {
		  q = q->next;
      }
      p->next = q->next;
	  p->prev = q;
	  if(q->next != NULL)
	      q->next->prev = p;	
	  q->next = p;	
   }
}

void display(Node *llist)
{
   Node *p = llist;
   printf("----------------------------\n");
   while(p != NULL)
   {
       printf("%6d", p->data);
       p = p->next;
   }
   printf("\n");
   printf("----------------------------\n");
}

void reverse(Node **llist)
{
	Node *p = *llist, *temp;
	while(p!= NULL)
	{
//		printf("%d %d %d\n", p->data, p->prev, p->next);
		temp = p->prev;
		p->prev = p->next;
		p->next = temp;
		p = p->prev;	
	}
	*llist = temp->prev;
}

int main()
{
    Node *start;
    start = NULL;
    insert(&start, 1);
    insert(&start, 2);
    insert(&start, 3);
    insert(&start, 4);
    display(start);
	reverse(&start);
	display(start);
}
