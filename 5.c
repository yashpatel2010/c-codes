#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 5
void insert();
void delete();
void display();

int queue[max];
int front=-1,rear=-1;

void main()
{
    int choice;
    while(1)
    {
        printf("\n*****Queue menu*****\n");
        printf("\n1.Insert \n2.Delete \n3.Display \n4.exit\n");
        printf("\nselect any number: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:insert();
            break;
            case 2:delete();
            break;
            case 3:display();
            break;
            case 4:exit(0);
            

            default:printf("\nInvalid choice!!!\n");
        }
    }

}

void insert()
{
    int element;
    if(rear>=max-1)
    {
        printf("Queue is overflow..");
    }
    else 
    {
        if(front==-1)   //front pointer ne 0th position pr sift kride
        front=0;
        printf("Insert an element in the queue: ");
        scanf("%d",&element);
        rear=rear+1;
        queue[rear]=element;

    }
}

void delete()
{
    if(front==-1 || front>rear)
    printf("\nQueue underflow\n");
    else
    {
        printf("the deleted element from the queue is: %d",queue[front]);
        front=front+1;
    }
}

void display()
{
    if(front==-1 || rear==-1)
    {
        printf("\nthe queue is empty\n");
    }
    else
    {int i;
        printf("\nQueue is.....\n");
        for ( i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
        
    }
}