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
    newNode->next = head;
    return newNode;
}
void display()
{
    struct node * ptr = head;
    printf("\n");
    if(ptr==NULL)
    {
        printf("queue is empty");
    }
    else
    {
        while(ptr->next!=head)
        {
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
        printf("%d ",ptr->data);
        printf("%d ",ptr->next->data);
    }
}
void enqueue(int data)
{
    struct node * ptr = head;
    struct node * newNode = createNode(data);
    if(head==NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->data=data;
        head->next=head;
        printf("added %d at head",data);
    }
    else
    {
        while(ptr->next!=head)
        {
            ptr=ptr->next;
        }
        ptr->next=newNode;
        printf("added %d",data);
    }
}
void dequeue()
{
    struct node * ptr = head;
    struct node * p = head;
    if(ptr==NULL)
    {
        printf("queue is empty");
    }
    else if(ptr==head && ptr->next==head)
    {
        printf("dequeued %d",ptr->data);
        head=NULL;
    }
    else
    {
        printf("dequeued %d",ptr->data);
        while(ptr->next!=head)
        {
            ptr=ptr->next;
        }
        p=p->next;
        ptr->next=p;
        head=p;
    }
}
int main()
{
    int i,op,element;
    system("clear");
    do
    {
        printf("Choose Operation\n");
        printf("1. enqueue\n");
        printf("2. dequeue\n");
        printf("3. Display\n");
        printf("Press any other key to exit\n");
        scanf("%d",&op);
        switch (op)
        {
            case 1: 
                printf("Enter element to enqueue: ");
                    scanf("%d",&element);
                    enqueue(element);
                    break;
            case 2: 
                dequeue();
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
