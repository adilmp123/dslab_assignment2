#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int size;
int stack[MAX],top=-1;
void push(int item)
{
    if(top==size-1)
    {
        printf("Stack Overflow");
    }
    else
    {
        stack[++top]=item;
        printf("pushed %d",item);
    }
}
int pop()
{
    if(top==-1)
    {
        printf("Stack is Empty");
    }
    else
    printf("popped %d",stack[top--]);
}
int display()
{
    int i=0;
    if(top==-1)
    {
        printf("\nStack is Empty");
        return 0;
    }
    for(i=0;i<=top;i++  )
    {
        printf("%d ",stack[i]);
    }
}
int main()
{
    int i,op,element;
    system("clear");
    printf("Enter the size of the stack: ");
    scanf("%d",&size);
    do
    {
        printf("Choose Operation\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("Press any other key to exit\n");
        scanf("%d",&op);
        switch (op)
        {
            case 1: 
                printf("Enter element to push: ");
                    scanf("%d",&element);
                    push(element);
                    break;
            case 2: 
                pop();
                break;
            case 3: 
                display();
                break;
            default:
                exit(0);
                break;
        }
        printf("\n\n");
    }while(op<=3);
}