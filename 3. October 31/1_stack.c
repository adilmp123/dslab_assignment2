#include <stdio.h>
#define MAX 100
int stack[MAX],top=-1;
void push(int item)
{
    if(top==MAX-1)
    {
        printf("Stack Overflow");
    }
    else
    {
        stack[++top]=item;
    }
}
int pop()
{
    if(top==-1)
    {
        printf("Stack is Empty");
    }
    else
        return stack[top--];
}
int main()
{
    int size,i,item;
    system("clear");
    printf("Enter the size of the stack: ");
    scanf("%d",&size);
    printf("Enter elements to be pushed: ");
    for(i=0;i<size;i++)
    {
        scanf("%d",&item);
        push(item);
    }
    printf("how many elements to be popped: ");
    scanf("%d",&item);
    for(i=0;i<item;i++)
    {
        printf("%d ",pop());
    }
}