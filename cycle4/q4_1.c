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
void display()
{
    struct node * ptr = head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    int n,element,i;
    system("clear");
    printf("Enter the number of elements in the list: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&element);
        addElement(element);
    }
    display();
}