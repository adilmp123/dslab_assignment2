#include <stdio.h>
#define MAX 100
char stack[MAX];
int top=-1;
void push(char item)
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
char pop()
{
    if(top==-1)
    {
        return -1;
    }
    else
    {
        char del = stack[top--];
        return del;
    }
}
int isBalanced(char str[])
{
    int i=0;
    while(str[i]!='\0')
    {
        if(str[i]=='(')
        {
            push(str[i]);
        }
        else if(str[i]==')')
        {
            pop();
        }
        i++;
    }
    if(top==-1)
    {
        return 1;
    }
    return 0;
}
int main()
{
    char str[100];
    system("clear");
    printf("Enter the expression: ");
    gets(str);
    if(isBalanced(str))
    {
        printf("Balanced");
    }
    else
    {
        printf("Not Balanced");
    }
}