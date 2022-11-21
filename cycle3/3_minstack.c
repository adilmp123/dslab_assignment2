#include <stdio.h>
#define MAX 100
int stack[MAX],top=-1,temp[MAX],tempTop=-1;
void push(int item)
{
    if(top==MAX-1)
    {
        printf("Stack Overflow");
    }
    else
    {
        stack[++top]=item;
        if(tempTop==-1)
        {
            temp[++tempTop]=item;
        }
        else
        {
            if(item<=temp[tempTop])
            {
                temp[++tempTop]=item;
            }
        }
    }
}
int display()
{
    int i=0;
    if(top==-1)
    {
        printf("\nStack is Empty");
        return;
    }
    for(i=0;i<=top;i++  )
    {
        printf("%d ",stack[i]);
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
        if(temp[tempTop]==stack[top])
        {
            tempTop--;
        }
        printf("popped %d ",stack[top--]);
    }
}

int displayMin()
{
    if(top==-1)
    {
        printf("stack is empty");
        return 0;
    }
    printf("smallest element = %d",temp[tempTop]);
}
int main()
{
    int element,i,op;
    system("clear");
    do
    {
        printf("Choose Operation\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Minimum Number\n");
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
            case 4: 
                displayMin();
                break;
            default:break;
        }
        printf("\n\n");
    }while(op<=4);
}