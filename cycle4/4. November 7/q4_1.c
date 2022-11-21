#include <stdio.h>
#include <stdlib.h>
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
void addElement(int data)
{
    struct node * ptr = head;
    struct node * newNode = createNode(data);
    if(head==NULL)
    {
        head = newNode;
    }
    else
    {
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=newNode;
    }
}
void display()
{
    struct node * ptr = head;
    printf("\n");
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    int op,element,item;
    system("clear");
    do
    {
        printf("1. Add Element");
        printf("\n2. display elements");
        printf("\nExit - Any other key");
        printf("\nEnter the operation: ");
        scanf("%d",&op);
        switch (op)
        {
        case 1: 
            printf("Enter element: ");
            scanf("%d",&element);
            addElement(element);
            printf("%d added",element);
            break;
        case 2: 
            display();
            break;
        default:exit(0);break;
        }
        printf("\n\n");
    } while(op<4);
}