#include <stdio.h>
#define MAX 100
int size1, size2,ii=0;
int stack[MAX],top1=-1,top2;
void push(int stackNo, int item)
{
    if(stackNo==1)
    {
        if(top1==size1-1)
        {
            // if(top2==(size1+size2-1) && ii==0)
            // {
            //     ii++;
            //     stack[top2]=item;
            //     top2++;
            //     printf("Pushed %d to stack 2",item);
            // }
            // else
            // {
                printf("Stack 1 Overflow");
            // }
        }
        else
        {
            stack[++top1]=item;
            printf("Pushed %d to stack 1",item);
        }
    }
    else if(stackNo==2)
    {
        if(top2==(size1-1))
            printf("Stack 2 Overflow");
        else
        {
            stack[top2--]=item;
            printf("pushed %d to stack 2",item);
        }
    }
}
int display(int stackNo)
{
    int i;
    if(stackNo==1)
    {
        if(top1==-1)
        {
            printf("Stack 1 is empty"); 
            return 0;
        }
        for(i=0;i<=top1;i++)
        {
            printf("%d ",stack[i]);
        }
    }
    else if(stackNo==2)
    {
        if(top2==(size1+size2-1))
        {
            printf("Stack 2 is empty"); 
            return 0;
        }
        for(i=(size1+size2-1);i>top2;i--)
        {
            printf("%d ",stack[i]);
        }
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
            size1--;
            size2++;
        }
    }
    else if(stackNo==2)
    {
        if(top2==(size1+size2-1))
        {
            printf("Stack 2 is empty");
        }
        else
        {
            printf("%d ",stack[++top2]);
            size1++;
            size2--;
        }
    }
}
int main()
{
    int op,element,stackNo;
    system("clear");
    printf("Enter the size of stack 1: ");
    scanf("%d",&size1);
    printf("Enter the size of stack 2: ");
    scanf("%d",&size2);
    top2=size1+size2-1;
    printf("Enter the stack number (1 or 2 ): ");
    scanf("%d",&stackNo);
    do
    {
        printf("Choose Operation\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Change Stack Number\n");
        printf("Press any other key to exit\n");
        scanf("%d",&op);
        switch (op)
        {
            case 1: 
                printf("Enter element to push: ");
                    scanf("%d",&element);
                    push(stackNo,element);
                    break;
            case 2: 
                pop(stackNo);
                break;
            case 3: 
                display(stackNo);
                break;
            case 4: 
                printf("Enter the stack number (1 or 2 ): ");
                scanf("%d",&stackNo);
                break;
            default:break;
        }
        printf("\n\n");
    }while(op<=4);
}
