#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, tos = 0;

void push(char stack[], int item)
{
    char temp;
    temp = item;
    if (tos == n - 1)
    {
        printf("Stack Overflow");
        exit(0);
    }
    else
    {
        tos++;
        stack[tos] = temp;
    }
}

char pop(char stack[])
{
    if (tos < 0)
    {
        printf("Stack Underflow");
        exit(0);
    }
    else
    {
        return stack[tos--];
    }
}

int getPrec(char c)
{

    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '#')
    {
        return 0;
    }
    else
    {
        return 4;
    }
}

void main()
{
    char exp[100];
    char postfix[100];
    char para;
    system("clear");
    n = 100;
    postfix[0] = '#';
    printf("Enter the expression: ");
    gets(exp);
    for (int i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == ')')
        {
            while (postfix[tos] != '(')
            {
                para = pop(postfix);
                if (para != '(')
                {
                    printf("%c", para);
                }
            }
            continue;
        }
        if (getPrec(exp[i]) > getPrec(postfix[tos]) || exp[i] == '(')
        {
            push(postfix, exp[i]);
        }
        else
        {
            while (getPrec(exp[i]) <= getPrec(postfix[tos]) && postfix[tos] != '(')
            {
                printf("%c", pop(postfix));
            }
            push(postfix, exp[i]);
        }
    }
    while (postfix[tos] != '#')
    {
        para = pop(postfix);
        if (para != '(')
        {
            printf("%c", para);
        }
    }
}