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
void pop()
{
    if(top==-1)
    {
        printf("Stack is Empty");
    }
    else
        printf("%d ",stack[top--]);
}
void displayMin()
{
    printf("smallest element = %d",temp[tempTop]);
}
int main()
{
    int size,element,i;
    system("clear");
    printf("Enter the size of the stack: ");
    scanf("%d",&size);
    printf("Enter %d elements you want to push: ",size);
    for(i=0;i<size;i++)
    {
        scanf("%d",&element);
        push(element);
    }
    displayMin();
}