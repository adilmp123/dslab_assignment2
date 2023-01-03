#include <stdio.h>
#include <stdlib.h>
#define Table_SIZE 10
struct node
{
    int data;
    struct node * next;
};
struct node * createNode(int data)
{
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
struct node *head[Table_SIZE]={NULL};
struct node * c;

void insert(int key)
{
    int i;
    i=key%Table_SIZE;
    struct node * new = createNode(key);
    struct node * temp;
    if(head[i]==NULL)
    {
        head[i]=new;
    }
    else
    {
        while(head[i]!=NULL && i<10)
        {
            i++;
        }
        if(i>=10)
        {
            printf("FULL");
            return;
        }
        head[i]=new;
    }
    printf("%d added",key);
}

void search(int key)
{
    int index;
    index = key%Table_SIZE;
    struct node * temp;
    if(head[index]==NULL)
    {
        printf("Search element not found");
    }
    else
    {
        temp=head[index];
        while(temp!=NULL)
        {
            if(temp->data==key)
            {
                printf("Search element found at %d",index);
                break;
            }
            temp=temp->next;
        }
        if(c=NULL)
        {
            printf("Search element not found");
        }
    }
}

void display()
{
    int i;
    struct node * temp;
    for(i=0;i<Table_SIZE;i++)
    {
        printf("\nIndex - %d: ",i);
        if(head[i]==NULL)
        {
            printf("No Hash Entry");
        }
        else
        {
            printf("%d",head[i]->data);
        }
    }
}

int main()
{
    int op,key,i;
    system("clear");
    while(1)
    {
        printf("\n1. Insert");
        printf("\n2. Display");
        printf("\n3. Search");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d",&key);
                insert(key);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter the element to search: ");
                scanf("%d",&key);
                search(key);
                break;
            case 4:
                exit(0);
                break;

        }
        printf("\n\n");
    }
}
