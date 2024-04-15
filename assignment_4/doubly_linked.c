#include <stdio.h>
#include <stdlib.h>
#include "DOUBLY_LINKED.h"

int init(struct node **head,struct node **tail){ *head=NULL; *tail=NULL;
return 1;
}

int insert(struct node **head, struct node **tail, int data, int
pos){ struct node *newnode=(struct node*)malloc(sizeof(struct
node)); if (!newnode || pos<1)
return 0;
newnode->data=data;
if(*head==NULL){
if (pos==1){
newnode->next=NULL; newnode->prev=NULL;

*head=newnode
*tail=newnode;
return 1;
}
else return 0;
}
if (pos==1){
(*head)->prev=newnode;
newnode->next=*head; *head=newnode;
newnode->prev=NULL;
return 1;
}
struct node *ptr=NULL;
ptr=*head;
for(int i=1;i<pos-1 &&
ptr!=NULL;i++){ ptr=ptr->next;
}
if (!ptr) return 0;
newnode->next=ptr->next;
newnode->prev=ptr;
ptr->next=newnode;
if ((newnode->next)==NULL) *tail=newnode;
else (newnode->next)->prev=newnode;
return 1;
}
int deletenode(struct node **head, struct node **tail, intpos, int *key)
{
if (*head==NULL || pos<1)
return 0;
struct node *iter=*head;
int i=1;
while (iter!=NULL &&
i<pos){ iter=iter->next;
i+=1;
}
if (!iter) return 0; *key=iter->data;
if (iter==*head){ *head=(*head)->next;
(*head)->prev=NULL;
free(iter);
return 1;
}
if (iter==*tail){ *tail=(*tail)->prev;
(*tail)->next=NULL;
free(iter);
return 1;
}
(iter->next)->prev=iter->prev;
(iter->prev)->next=iter->next;
free(iter);
return 1; }

int search(struct node **head, int key, int *pos){
if (*head==NULL) return 0;
struct node *iter=*head;
int i=1;
while (iter!=NULL && iter- >data!=key){ iter=iter->next;
i+=1;
if (iter==NULL) return 0; *pos=i;
return 1;
}
int traverseforward(struct node
**head){ if (*head==NULL){
printf("NULL \n");
return 0;
}
struct node *iter=*head;
while (iter){
printf("%d-->",(iter->data));
iter=iter->next;
}
printf("NULL \n"); return 1;
}

int traversebackward(struct node **tail){ if
(*tail==NULL){ printf("NULL \n");
return 0;
}
struct node *iter=*tail; while
(iter){ printf("%d-->",(iter->data)); iter=iter- >prev;
}
printf("NULL \n"); return 1;
}
int findsmallbig(struct node **head, int *big,
int*small){ if (*head==NULL)
return 0;
struct node *iter=*head;
int tempsmall=(*head)->data;
int tempbig=tempsmall;
while (iter!=NULL){
if (tempbig<(iter->data)) tempbig=iter->data;
if (tempsmall>(iter->data))
tempsmall=iter->data;
iter=iter->next;
}*big=tempbig;{

*small=tempsmall; return 1;
}

int main(){
struct node *head=NULL; struct node *tail=NULL; init(&head, &tail);
int length;
printf("Enter no of elements to insert in Doubly LL: ");
scanf("%d",&length);
for(int i=1;
i<=length;i++){ int elem;
printf("Enter element: ");
scanf("%d",&elem);
insert(&head,&tail,elem,i);
}

printf("The current linked list: \n"); traverseforward(&head);
int elem,pos;
printf("Enter element to insert at specific position: "); scanf("%d %d",&elem,&pos);
insert(&head,&tail,elem,pos);
printf("The current linked list: \n"); traverseforward(&head);
printf("Traversing in backward direction: \n"); traversebackward(&tail);
printf("Deleting element: \n");

printf("Enter position of element to delete: "); scanf("%d",&pos);
deletenode(&head, &tail,pos,&elem); printf("The current linked list: \n");
traverseforward(&head); printf("Deleted element: %d \n",elem);
printf("Enter element to search: ");
scanf("%d",&elem);
search(&head, elem, &pos);
printf("Position of element: %d \n", pos);

int big,small;
findsmallbig(&head,&big,&small);
printf("The larget and smallest elements are: %d %d \n", big, small);
return 0;
}