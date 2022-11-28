#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct node 
{
    int data;
    struct node * next;
};
struct node * head = NULL;
struct node * createNode(int data)
{
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void display()
{
    struct node * ptr = head;
    printf("\n");
    if(ptr==NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
    }
}
int addAtFront(int item)
{
    struct node * ptr = head;
    struct node * newNode = createNode(item);
    if(ptr==NULL)
    {
        head=newNode;
        return 0;
    }
    newNode->next=head;
    head=newNode;
}
void push(int item)
{
    addAtFront(item);
    printf("pushed %d",item);
}
void pop()
{
    struct node * ptr = head;
    if(head==NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("popped %d",ptr->data);
        ptr=ptr->next;
        head = ptr;
    }
}
int main()
{
    int i,op,element;
    system("clear");
    do
    {
        printf("Choose Operation\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("Press any other key to exit\n");
        scanf("%d",&op);
        switch (op)
        {
            case 1: 
                printf("Enter element to push: ");
                    scanf("%d",&element);
                    push(element);
                    break;
            case 2: 
                pop();
                break;
            case 3: 
                display();
                break;
            default:
                exit(0);
                break;
        }
        printf("\n\n");
    }while(op<=3);
}
