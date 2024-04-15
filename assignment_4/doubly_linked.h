#include <stdio.h>

struct
node{ int
data;
struct node *prev;
struct node *next;
};

int init(struct node **head, struct node **tail);
int insert(struct node **head, struct node **tail, int data, int pos);
int deletenode(struct node **head, struct node **tail, int pos, int *data);
int search(struct node **head, int key, int*pos);
int traverseforward(struct node **head);
int traversebackward(struct node **tail);
int findsmallbig(struct node**