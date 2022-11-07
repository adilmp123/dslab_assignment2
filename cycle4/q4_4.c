#include <stdio.h>
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
    if(ptr->next==NULL)
    {
        printf("Element Not Found");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void insertAtPos(int pos, int data)
{
    int i=2;
    struct node * ptr = head;
    struct node * newNode = createNode(data);
    while(i<pos && ptr->next!=NULL)
    {
        ptr=ptr->next;
        i++;
    }
    if(pos==1)
    {
        newNode->next = head;
        head = newNode;
    }
    else if(ptr->next==NULL)
    {
        ptr->next = newNode;
    }
    else
    {
        newNode->next = ptr->next;
        ptr->next = newNode;
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
        printf("\n2. Insert after a element");
        printf("\n3. Insert before a element");
        printf("\n4. Insert at given position");
        printf("\n5. display elements");
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
            printf("Enter value of node after which new node to be added: ");
            scanf("%d",&item);
            printf("Enter element: ");
            scanf("%d",&element);
            insertAfter(item,element);
            printf("%d added after %d",element,item);
            break;

        case 3: 
            printf("Enter value of node before which new node to be added: ");
            scanf("%d",&item);
            printf("Enter element: ");
            scanf("%d",&element);
            insertBefore(item,element);
            printf("%d added before %d",element,item);
            break;

        case 4: 
            printf("Enter position ");
            scanf("%d",&item);
            printf("Enter element: ");
            scanf("%d",&element);
            insertAtPos(item,element);
            printf("%d added at pos %d",element,item);
            break;

        case 5: 
            display();
            break;
        }
        printf("\n\n");
    } while(op<6);
}