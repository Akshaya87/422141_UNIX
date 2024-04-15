provided data already exists within the linked list. struct node *ptrToKey=NULL;
int pos=0;
if (!search(head, data,&ptrToKey, &pos))
{
struct node *ptr=*head;
for (int i=1; i<position-1 && ptr!=NULL;i++) ptr=ptr->next;
if (ptr==NULL)
return 0;
else{
newnode->next=ptr->next;
ptr->next=newnode;
return 1;
}
}
else{
printf("Element already present in address: %p
\n",ptrToKey);
return 0;
}

}
int traverse(struct node *head){ if
(!head){ printf("NULL \n"); return 1;
}
for (struct node *ptr=head;ptr!=NULL;ptr=ptr->next) printf("%d -->",ptr->data);
printf("NULL \n"); return 1;
}
int kFromLast(struct node *head, int k ,int *data)
{
if(!head)
return 0;
struct node *fast=head; struct node *slow=NULL;
int i=1;
while(fast!=NULL &&
i<=k){ fast=fast->next;
i++;
}
if(fast==NULL && i<k)
return 0;
slow=head;
while(slow!=NULL){
slow=slow->next;
fast=fast->next;
}*data=slow->data;
return 1;
}
int main(){
struct node *head; initList(&head);
int n;
printf("Enter no of nodes you want to enter data: ");
scanf("%d",&n);
int pos=1; while (n--
){ int data;
printf("\nEnter data: ");
scanf("%d",&data);
if (!insert(&head,pos++,data))
return 0;
}
printf("\nThe current linked list is:\n"); traverse(head);
int k, data;
printf("Enter kth position from last to find node data: "); scanf("%d", &k);
kFromLast(head, k, &data); printf("Data: %d\n",data); return 0;
}