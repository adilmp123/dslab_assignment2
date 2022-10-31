#include <stdio.h>
#define MAX 100
int stack[MAX],top1=-1,top2=(MAX/2);
void push(int stackNo, int item)
{
    if(stackNo==1)
    {
        if(top1==(MAX/2)-1)
            printf("Stack 1 Overflow");
        else
            stack[++top1]=item;
    }
    else if(stackNo==2)
    {
        if(top2==MAX)
            printf("Stack 2 Overflow");
        else
            stack[++top2]=item;
    }
}
void pop(int stackNo)
{
    if(stackNo==1)
    {
        if(top1==-1)
        {
            printf("Stack 1 is empty");
        }
        else
        {
            printf("%d ",stack[top1--]);
        }
    }
    else if(stackNo==2)
    {
        if(top2==(MAX/2))
        {
            printf("Stack 2 is empty");
        }
        else
        {
            printf("%d ",stack[top2--]);
        }
    }
}
int main()
{
    int op,element,stackNo;
    system("clear");
    printf("Enter the stack number (1 or 2 ): ");
    scanf("%d",&stackNo);
    do
    {
        printf("Choose Operation\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Change Stack Number\n");
        printf("Press any other key to exit\n");
        scanf("%d",&op);
        switch (op)
        {
            case 1: 
                printf("Enter element to push: ");
                    scanf("%d",&element);
                    push(stackNo,element);
                    printf("Pushed %d",element);
                    break;
            case 2: 
                pop(stackNo);
                break;
            case 3: 
                printf("Enter the stack number (1 or 2 ): ");
                scanf("%d",&stackNo);
                break;
        }
        printf("\n\n");
    }while(op<=3);
}