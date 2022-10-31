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
    {
        int del=stack[top--];
        return del;
    }
}
void convertToBinary(int n)
{
    while(n)
    {
        push(n%2);
        n/=2;
    }
}
void Binary()
{
    printf("Binary: ");
    while(top!=-1)
    {
        printf("%d",pop());
    }
    printf("\n");
}
void convertToHex(int n)
{
    while(n)
    {
        push(n%16);
        n/=16;
    }
}
void Hex()
{
    int i;
    printf("Hexa: ");
    while(top!=-1)
    {
        int del=pop();
        switch(del)
        {
            case 10: printf("A");break;
            case 11: printf("B");break;
            case 12: printf("C");break;
            case 13: printf("D");break;
            case 14: printf("E");break;
            case 15: printf("F");break;
            default: printf("%d",del);
        }
    }
    printf("\n");
}
int main()
{
    int n;
    system("clear");
    printf("Enter the number: ");
    scanf("%d",&n);
    convertToBinary(n);
    Binary();
    convertToHex(n);
    Hex();
}