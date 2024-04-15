#include <stdio.h>
#include <stdlib.h>
struct
node{ int
data;
struct node *next;
};

struct node *head;

int initList(struct node **head){ *head=NULL;
return 1;
}
int search(struct node **head, int data, struct node
**ptrToKey, int *pos){
if (*head==NULL) return 0; *pos=1;
struct node *ptr=*head;
for (;ptr!=NULL && ptr->data!=data;ptr=ptr->next){ *pos=(*pos)+1;
}*ptrToKey=ptr;
if (!ptr) return 0;
return 1;
}
int insert(struct node **head, int position, int data){
struct node *newnode=(struct node*)malloc(sizeof(struct node));
if (newnode==NULL)
return 0;
newnode->data=data; if
(position==1){ newnode->next=*head; *head = newnode;
return 1;
}