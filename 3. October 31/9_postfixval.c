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
void postfix(char str[])
{
    int i=0,n1,n2,n3,num;
    while(str[i]!='\0')
    {
        if(isdigit(str[i]))
        {
            num=str[i]-48;
            push(num);
        }
        else
        {
            n1=pop();
            n2=pop();
            switch(str[i])
            {
                case '+': n3=n1+n2;break;
                case '-': n3=n2-n1;break;
                case '*': n3=n1*n2;break;
                case '/': n3=n2/n1;break;
            }
            push(n3);
        }
        i++;
    }
    printf("%d",pop());
}
int main()
{
    char str[100];
    system("clear");
    printf("Enter the infix expression: ");
    gets(str);
    postfix(str);
}