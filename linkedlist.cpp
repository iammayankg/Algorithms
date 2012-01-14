/*Reverse a linked list in O(n) */

#include <stdio.h>
#include <stdlib.h>
struct list
{
	int data;
	struct list *next;
};
typedef struct list LIST;
LIST * create_node(int num)
{
	LIST * node=(LIST *)malloc(sizeof(LIST));
	node->data=num;
	node->next=NULL;
}
void add(LIST *l,int num)
{
	LIST *root=l;
	while(l->next!=NULL)
	l=l->next;
	l->next=create_node(num);
	root->data++;
}
void display(LIST *root)
{
	while(root!=NULL){
	printf("%d->",root->data);
	root=root->next;
	}
}
void reverse(LIST *root)
{
	LIST *a,*b,*c,*head;
	a=head=root->next;
	b=c=a->next;
	while(b!=NULL)
	{
		c=c->next;
		b->next=head;
		head=b;
		a->next=c;
		b=c;
	}
	root->next=head;
}
int main()
{
	LIST *root=create_node(0);
	add(root,1);
	add(root,2);
	add(root,3);
	add(root,4);
	add(root,5);
	display(root);
	reverse(root);
	printf("\n");
	
	display(root);
	return 1;
}
