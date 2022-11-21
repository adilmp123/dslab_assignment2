#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node * next;
};
int swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
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
int insertAfter(int item, int data)
{
    struct node * ptr = head;
    struct node * newNode = createNode(data);
    while(ptr->data!=item && ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    if(ptr->next==NULL)
    {
        printf("Element Not Found");
        return;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
}
int insertBefore(int item, int data)
{
    struct node * ptr = head;
    struct node * temp;
    struct node * newNode = createNode(data);
    while(ptr->data!=item && ptr->next!=NULL)
    {
        temp=ptr;
        ptr=ptr->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void display()
{
    struct node * ptr = head;
    printf("\n");
    if(ptr==NULL)
    {
        printf("List is Empty");
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
void sortedAdd(int element)
{
    struct node * ptr = head;
    struct node * new = createNode(element);
    if(head==NULL)
    {
        head=new;
    }
    else if(ptr->next==NULL)
    {
        ptr->next=new;
    }
    else
    {
        while(element>ptr->data && ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        insertBefore(ptr->data,element);
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
            sortedAdd(element);
            printf("%d added",element);
            break;

        case 2: 
            display();
            break;

        default:exit(0);break;
        }
        printf("\n\n");
    } while(op<=2);
}