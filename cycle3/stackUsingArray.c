#include <stdio.h>
#define MAX_SIZE 101
int stack[MAX_SIZE];
int top=-1;
void stackFull()
{
    printf("Stack Overflow cannot push !");
}
void stackEmpty()
{
    printf("Stack Underflow cannot pop !");
}
void push(int item)
{
    if(top!=(MAX_SIZE-1))
    {
        top++;
        stack[top]=item;
    }
    else
    {
        stackFull();
    }
}
void pop()
{
    if(top!=-1)
    {
        printf("%d\n",stack[top]);
        top--;
    }
    else
    {
        stackEmpty();
    }
}

void peak()
{
    if(top!=-1)
    {
        printf("%d\n",stack[top]);
    }
    else
    {
        stackEmpty();
    }
}
void printStack()
{
    int i;
    for(i=0;i<=top;i++)
    {
        printf("%d\n",stack[i]);
    }
}
int main()
{
    int n;
    push(3);
    push(4);
    push(5);
    push(6);
    push(7);
    push(8);
    push(9);
    push(10);
    printStack();
}