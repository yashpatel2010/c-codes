//Circular Queue

#include<stdio.h>
#include<conio.h>
# include<stdlib.h>
#define max 5
int front=-1,rear=-1;
int queue[max];

void insert()
{int value;
    if(front==-1 && rear ==-1)
    {
        front=rear=0;
        printf("Enter an element: ");
        scanf("%d",&value);
        queue[rear]=value;
    }
    else if(((rear+1)%max)==front)
    {
        printf("\n Queue is full!!!\n");
    }
    else
    {
        printf("\nEnter an element: ");
        scanf("%d",&value);
        rear=(rear+1)%max;
        queue[rear]=value;

    }
}
void delete()
{
    if (front==-1 && rear==-1)
    {
        printf("\nQueue is underflow");
    }
    else if(front == rear)
    {
        printf("\nDeleted element is %d:",queue[front]);
        front=rear=-1;
    }
    else
    {
        printf("deleted element is:%d",queue[front]);
        front=(front+1)%max;
    }
}
void display()
{int i=front;
    if(front==-1 && rear ==-1)
    {
        printf("\n Queue is underflow");
    }
    else 
    {
        printf("\nQueue is..\n");
        while(i!=rear)
        {
            printf("%d ",queue[i]);
            i=(i+1)%max;
        }
        printf("%d",queue[rear]);
    }
}

void main()
{int choice;
    while(1)
   {
        printf("\n*****Queue menu****\n");
        printf("\n1.insert \n2.delete \n3.display \n4.exit");
        printf("\nenter any choice: ");
        scanf("%d",&choice);
    
    
    
        switch (choice)
        {
            case 1:insert();
            break;
            case 2:delete();
            break;
            case 3: display();
            break;
            case 4:exit(0);

            default: printf("\nInvalild choice\n");
        }
    }
}