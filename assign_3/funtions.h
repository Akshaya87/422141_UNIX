#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX_SIZE 10

struct Stack {
    int items[MAX_SIZE];
    int top;
};

void initialize(struct Stack *s);
int isFull(struct Stack *s);
int isEmpty(struct Stack *s);
void push(struct Stack *s, int value);
int pop(struct Stack *s);
void printBoard(int board[MAX_SIZE][MAX_SIZE], int n);
int isSafe(int board[MAX_SIZE][MAX_SIZE], int row, int col, int n);
void solveNQueens(int n);

#endif


