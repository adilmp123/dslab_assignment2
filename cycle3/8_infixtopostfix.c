#include <stdio.h>
#include <ctype.h>
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
int priority(char x)
{
    if(x=='(')
        return 0;
    if(x=='+' || x=='-')
        return 1;
    if(x=='*' || x=='/')
        return 2;
    if(x=='^')
        return 3;
    return 0;
}
void toPostfix(char str[])
{
    int i=0;
    while(str[i]!='\0')
    {
        if(isalnum(str[i]))
        {
            printf("%c ",str[i]);
        }
        else if(str[i]=='(')
        {
            push(str[i]);
        }
        else if(str[i]==')')
        {
            char x=pop();
            while(x!='(')
            {
                printf("%c ",x);
                x=pop();
            }
        }
        else
        {
            while(priority(stack[top])>=priority(str[i]))
            {
                printf("%c ",pop());
            }
            push(str[i]);
        }
        i++;
    }
    while(top!=-1)
    {
        printf("%c ",pop());
    }
}
int main()
{
    char str[100];
    system("clear");
    printf("Enter the infix expression: ");
    gets(str);
    toPostfix(str);
}