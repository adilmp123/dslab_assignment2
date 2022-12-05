#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int size,front=-1,rear=-1;
int queue[MAX];
void enqueue(int item)
{
    if(front==-1)
    {
        front=rear=0;
        queue[rear]=item;
        printf("added %d",item);
    }
    else if((rear+1)%size==front)
    {   
        printf("Queue overflow");
    }
    else
    {
        rear=(rear+1)%size;
        queue[rear]=item;
        printf("added %d",item);
    }
}
void display()
{
    int i = front, j= rear;
    if( front==-1)
    {
        printf("queue is empty");
    }
    else
    {
        while (i!=j)
        {
            printf("%d ",queue[i]);
            i=(i+1)%size;
        }
        printf("%d ", queue[i]);
    }
}
void dequeue()
{
    // printf("%d\n%d",front,rear);
    if(front==-1)
    {
        printf("queue underflow");
    }
    else if(front==rear)
    {
        printf("dequeued %d",queue[front]);
        front=(front+1)%size;
        front=rear=-1;
    }
    else
    {
        printf("dequeued %d",queue[front]);
        front=(front+1)%size;
    }
    
}
int main()
{
    int op,element;
    system("clear");
    printf("Enter the size of the queue: ");
    scanf("%d",&size);
    do
    {
        printf("Choose Operation\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
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