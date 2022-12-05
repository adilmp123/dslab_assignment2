#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node * next;
    struct node * prev;
};
struct node * createNode(int data)
{
    struct node * new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next=NULL;
    new->prev=NULL;
    return new;
}
struct node * head=NULL;
void addAtEnd(int data)
{
    struct node * new = createNode(data);
    if(head==NULL)
    {
        head=new;
        printf("added %d at head",data);
        return;
    }
    else
    {
        struct node * ptr = head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        new->prev=ptr;
        ptr->next=new;
        printf("added %d at End",data);
    }
}
void addAtFront(int data)
{
    struct node * new = createNode(data);
    if(head==NULL)
    {
        head=new;
        printf("added %d at head",data);
    }
    else
    {
        new->next=head;
        head->prev=new;
        head=new;
        printf("added %d at front",data);
    }
}
void delFront()
{
    if(head==NULL)
    {
        printf("List is empty");
        return;
    }
    struct node * ptr = head;
    head=head->next;
    head->prev=NULL;
    printf("%d deleted",ptr->data);
    free(ptr);
}
void delEnd()
{
    if(head==NULL)
    {
        printf("List is empty");
        return;
    }
    struct node * ptr = head;
    struct node * temp;
    while(ptr->next!=NULL)
    {
        temp=ptr;
        ptr=ptr->next;
    }
    temp->next=NULL;
    printf("%d deleted",ptr->data);
    free(ptr);
}
void display()
{
    struct node * ptr = head;
    if(head==NULL)
    {
        printf("queue is empty");
        return;
    }
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
int main()
{
    int i,op,element;
    system("clear");
    // addAtEnd(2);
    // addAtEnd(3);
    // addAtFront(1);
    // delFront();
    // delEnd();
    // display();
    do
    {
        printf("Choose Operation\n");
        printf("1. Enqueue at rear\n");
        printf("2. Enqueue at front\n");
        printf("3. dequeue from rear\n");
        printf("4. dequeue from front\n");
        printf("5. Display\n");
        printf("Press any other key to exit\n");
        scanf("%d",&op);
        switch (op)
        {
            case 1: 
                printf("Enter element to enqueue at end: ");
                scanf("%d",&element);
                addAtEnd(element);
                break;
            case 2: 
                printf("Enter element to enqueue at front: ");
                scanf("%d",&element);
                addAtFront(element);
                break;
            case 3: 
                delEnd();
                break;
            case 4: 
                delFront();
                break;
            case 5: 
                display();
                break;
            default:
                exit(0);
                break;
        }
        printf("\n\n");
    }while(op<=5);
}
