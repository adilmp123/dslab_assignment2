#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int stack[MAX],top=-1;
void push(int item)
{
    if(top==MAX-1)
    {
        printf("Stack Overflow");
    }
    else if(top==-1)
    {
        stack[++top]=item;
    }
    else

    {
        int temp[MAX],tempTop=-1;
        while(item<stack[top] && top!=-1)
        {
            int del = stack[top--];
            temp[++tempTop]= del;
        }
        stack[++top]=item;
        while(tempTop>=0)
        {
            int del=temp[tempTop--];
            stack[++top]=del;
        }
    }
}
void pop()
{
    if(top==-1)
    {
        printf("Stack is Empty");
    }
    else
    {
        printf("popped %d ",stack[top--]);
    }
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
    int element,op,i;
    system("clear");
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
                    printf("pushed %d",element);
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
    display();
}