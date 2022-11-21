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
void deleteNode(int data)
{
    struct node * ptr = head;
    struct node * temp;
    if(ptr->data==data)
    {
        head = ptr->next;
        free(ptr);
    }
    else
    {
        while(ptr->data!=data && ptr->next!=NULL)
        {
            temp=ptr;
            ptr = ptr->next;
        }
        if(ptr->next==NULL)
        {
            printf("Element not Found");
        }
        temp->next = ptr->next;
        free(ptr);
    }
}

void deleteNodePos(int pos)
{
    int i=2;
    struct node * ptr = head;
    struct node * temp;
    if(pos==1)
    {
        head = ptr->next;
        free(ptr);
    }
    else
    {
        while(i!=pos+1 && ptr->next!=NULL)
        {
            temp=ptr;
            ptr=ptr->next;
            i++;
        }
        temp->next = ptr->next;
        free(ptr);
    }
}
void deleteSmallest()
{
    struct node * ptr = head;
    if(ptr==NULL)
    {
        printf("List is Empty !");
    }
    else
    {
        int smallest = ptr->data;   
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
            if(smallest>ptr->data)
            {
                smallest = ptr->data;
            }
        }
        deleteNode(smallest);
        printf("smallest element deleted");
    }
}
void reverse()
{
    struct node * prev;
    struct node * nextt;
    struct node * current;
    prev=NULL;
    nextt=head;
    current=head;
    while(nextt!=NULL)
    {
        nextt=nextt->next;
        current->next = prev;
        prev=current;
        current=nextt;
    }
    head=prev;
    printf("reversed successfully");
}
int search(int item)
{
    struct node * ptr = head;
    int pos=1,flag=1;
    if(ptr==NULL)
    {
        printf("List is Empty !");
        return 0;
    }
    if(ptr->data == item)
    {
        printf("Element found at pos %d",pos);
    }
    else
    {
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
            pos++;
            if(ptr->data==item)
            {
                printf("Element found at pos %d",pos);
                flag=0;
                break;
            }
        }

    }
    if(flag)
    {
        printf("element not found");
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
        printf("\n5. Delete data");
        printf("\n6. Delete position");
        printf("\n7. Delete Smallest");
        printf("\n8. reverse elements");
        printf("\n9. search element");
        printf("\n10. display elements");
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
            printf("Enter data to be deleted: ");
            scanf("%d",&element);
            deleteNode(element);
            break;

        case 6: 
            printf("Enter position of node to be deleted: ");
            scanf("%d",&element);
            deleteNodePos(element);
            break;

        case 7: 
            deleteSmallest(element);
            break;

        case 8:
            reverse();break;
        case 9:
            printf("Enter the element to be searched: ");
            scanf("%d",&element);
            search(element);
            break;
        case 10: 
            display();
            break;
        default:exit(0);break;
        }
        printf("\n\n");
    } while(op<=10);
}