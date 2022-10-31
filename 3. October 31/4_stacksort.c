#include <stdio.h>
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
        printf("%d ",stack[top--]);
}
void display()
{
    int i;
    for(i=0;i<=top;i++)
    {
        printf("%d ",stack[i]);
    }
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
    display();
}