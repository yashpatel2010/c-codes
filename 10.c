#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *new_node,*temp,*head,*tail;
int count=0;
void create_node()
{   
    head=0;
    head=tail;
    int choice;
    while(choice)
    {   
        new_node=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter data: ");
        scanf("%d",&new_node->data);

        new_node->next=0;
        new_node->prev=0;

        if(head==0)
        {
            head=tail=new_node;
        }
        else
        {
            tail->next=new_node;
            new_node->prev=tail;
            tail=new_node;    
        }
        printf("\npress '1' if you want to continue otherwise press '0': ");
        scanf("%d",&choice);
    }

}

void display()
{
    temp=head;
    if(head==0)
    {
        printf("\n!!Doubly linked list is empty!!\n");
    }
    else
    {
        printf("\n***doubly linked list is***\n");
        while(temp!=0)
        {
            printf("%d ",temp->data);
            temp=temp->next;
            count++;
        }
    }
}



void insert_at_beg()
{
    new_node=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data: ");
    scanf("%d",&new_node->data);
    head->prev=new_node;
    new_node->next=head;
    head=new_node;
}

void insert_at_end()
{
   
    if(head==0)
    {
        insert_at_beg();
    }
    else
    {
        new_node=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter the data: ");
        scanf("%d",&new_node->data);

        new_node->prev=tail;
        tail->next=new_node;
        tail=new_node;
        new_node->next=0;

    }
}

void insert_at_specified_pos()
{
    int pos,i=1;
    printf("\nEnter position: ");
    scanf("%d",&pos);

    if(pos>count)
    {
        printf("\nInvalid position\n");
    }
    else if(pos==1)
    {
        insert_at_beg();
    }
    else
    {
        new_node=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter data for new node: ");
        scanf("%d",&new_node->data);
        
        temp=head;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        new_node->prev=temp;
        new_node->next=temp->next;
        temp->next=new_node;
        new_node->next->prev=new_node;
    }
    
}

void insert_after_specified_pos()
{
    int pos,i=1;
    printf("\nEnter position: ");
    scanf("%d",&pos);

    if(pos>count)
    {
        printf("\nInvalid position\n");
    }
    else
    {
        new_node=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter data for new node: ");
        scanf("%d",&new_node->data);
        
        temp=head;
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        new_node->prev=temp;
        new_node->next=temp->next;
        temp->next=new_node;
        new_node->next->prev=new_node;
    }
    
}
void insert_before_specified_pos()
{
    int pos,i=1;
    printf("\nEnter position: ");
    scanf("%d",&pos);
    if(pos==1)
    {
        insert_at_beg();
    }
    else if(pos>count)
    {
        printf("\nInvalid position\n");
    }
    else
    {
        new_node=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter data for new node: ");
        scanf("%d",&new_node->data);
        
        temp=head;
        while(i<pos-2)
        {
            temp=temp->next;
            i++;
        }
        new_node->prev=temp;
        new_node->next=temp->next;
        temp->next=new_node;
        new_node->next->prev=new_node;
    }
    
}

void del_from_beg()
{
    if(head==0)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        temp=head;
        head=head->next;
        head->prev=0;
        free(temp);
    }
}
void del_from_end()
{
    if(head==0)
    {
        printf("\n!!List is empty!!");
    }
    else
    {
        temp=tail;
        tail=tail->prev;
        tail->next=0;
        free(temp);
    }
}
void del_at_pos()
{
    int pos,i=1;
    printf("\nEnter a pos: ");
    scanf("%d",&pos);
   

    if(head==0)
    {
        printf("\nList is empty");
    }
     

    else if(pos==1)
    {
        insert_at_beg();
    }
    else if(pos==count)
    {
        insert_at_end();
    }
    else
    {
        temp=head;
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }
    
}




void main()
{
    while(1)
    {
        int choice;
        printf("\n\n-------------------------------------------------------------------------------------------");
        printf("\n***Doubly linked list menu***\n");
        printf("------------------------------\n");
        printf("\n1.Display \n2.Create node \n3.Insert node at beginning \n4.Insert node at end");
        printf("\n5.Insert node at specified position \n6.Insert node after specified position");
        printf("\n7.Insert node before specified position"); 
        printf("\n8.Delete node from beginning");
        printf("\n9.Delete node from end");
        printf("\n10.Delete node from specified position");
        printf("\n11.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {   
            case 1:display();
            break;
            case 2:create_node();
            break;
            case 3:insert_at_beg();
            break;
            case 4:insert_at_end();
            break;
            case 5:insert_at_specified_pos();
            break;
            case 6:insert_after_specified_pos();
            break;
            case 7:insert_before_specified_pos();
            break;
            case 8:del_from_beg();
            break;
            case 9:del_from_end();
            break;
            case 10:del_at_pos();
            break;
            case 11:exit(0);

            default:printf("\n!!Invalid choice!!\n");
        }
    }
}