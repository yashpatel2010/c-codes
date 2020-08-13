// Singly Linked list

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct node
    {
        int data;
        struct node *next;
    };
    struct node *head,*temp,*new_node;
    int count=0;


void create_node()

{
    
    int choice;
    head=0;

    while(choice)
    {
        new_node=(struct node *)malloc(sizeof(struct node));

        printf("\nEnter element: ");
        scanf("%d",&new_node->data);
        new_node->next=0;
        
        if(head==0)
        {
            head=temp=new_node;
        }
        else
        {
            
            temp->next=new_node;
            temp=new_node;
        }
        printf("\nDo you want to continue(for continue enter 1 or exit enter 0): ");
        scanf("%d",&choice);
    }
}

void display()
{
    temp=head;
    while(temp!=0)
    {
        printf("\n***Linked list is***\n");
        printf("%d ",temp->data);
        temp=temp->next;
        count++;
    }
    printf("\nYou have %d nodes\n",count);
    printf("\n---------------------");
}

void insert_at_beg()
{
    new_node=(struct node *)malloc(sizeof(struct node));\
    printf("\nEnter an element for new node: ");
    scanf("%d",&new_node->data);
    new_node->next=head;
    head=new_node;
}

void insert_at_end()
{
    new_node=(struct node *)malloc(sizeof(struct node));
    printf("enter element for new node: ");
    scanf("%d",&new_node->data);
    new_node->next=0;

    temp=head;
    while(temp->next!=0)
    {
        temp=temp->next;
    }
    temp->next=new_node;
}

void insert_after_specified_loc()
{
    int pos,i=1;
    new_node=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter an element for new node: ");
    scanf("%d",&new_node->data);

    printf("\nEnter the position after you want to insert a node: ");
    scanf("%d",&pos);

    if(pos>count)
    {
        printf("\nInvalid Position!!");
    }
    else
    {
        temp=head;
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        new_node->next=temp->next;
        temp->next=new_node;
    }
}

void insert_before_specified_loc()
{
    int pos,i=1;
    new_node=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter an element for new node: ");
    scanf("%d",&new_node->data);

    printf("\nEnter the position before you want to insert a node: ");
    scanf("%d",&pos);

    if(pos>count)
    {
        printf("\nInvalid Position!!");
    }
    else
    {
        temp=head;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        new_node->next=temp->next;
        temp->next=new_node;
    }
}

void delete_first_node()
{   if(head==0)
    {
        printf("\nLinked list is empty");
    }
    else
    {
      temp=head;
      head=head->next;
      free(temp);  
    }
}

void delete_last_node()
{
    struct node *previous;
    temp=head;
    while(temp->next!=0)
    {
        previous=temp;
        temp=temp->next;
    }
    
    if(temp==head)
    {
        head=0;
        free(temp);
    }
    else
    {
        previous->next=0;
        free(temp);
    }   
}

void delete_from_given_pos()
{
    struct node *next_node;
    int pos,i=1;
    temp=head;
    printf("\nEnter position: ");
    scanf("%d",&pos);

    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    next_node=temp->next;
    temp->next=next_node->next;
    free(next_node);
}

void delete_before_given_pos()
{
    struct node *next_node;
    int pos,i=1;
    temp=head;
    printf("\nEnter position: ");
    scanf("%d",&pos);

    while(i<pos-2)
    {
        temp=temp->next;
        i++;
    }
    next_node=temp->next;
    temp->next=next_node->next;
    free(next_node);
}

void delete_after_given_pos()
{
    struct node *next_node;
    int pos,i=1;
    temp=head;
    printf("\nEnter position: ");
    scanf("%d",&pos);

    while(i<pos)
    {
        temp=temp->next;
        i++;
    }
    next_node=temp->next;
    temp->next=next_node->next;
    free(next_node);
}




void main()
{   while(1)
    {
        int choice;
        printf("\n****Singly linked list menu****\n");
        printf("\n1.Create linked list ");
        printf("\n2.Insert element at 1st position");
        printf ("\n3.Insert an element at Last position"); 
        printf ("\n4.Insert an element after specified location");
        printf ("\n5.Insert element before specified location"); 
        printf ("\n6.Delete first element");
        printf ("\n7.Delete last element"); 
        printf ("\n8.Delete element after specified location");
        printf ("\n9.Delete element before specified location");
        printf ("\n10.Display Linked list");
        printf ("\n11.Exit");
        printf("\n\nselect operation: ");
        scanf("%d",&choice);

    
        switch(choice)
        {
            case 1:create_node();
            break;
            case 2:insert_at_beg();
            break;
            case 3:insert_at_end();
            break;
            case 4:insert_after_specified_loc();
            break;
            case 5:insert_before_specified_loc();
            break;

            case 6:delete_first_node();
            break;
            case 7:delete_last_node();
            break;
            case 8:delete_after_given_pos();
            break;
            case 9:delete_before_given_pos();
            break;
            case 10:display();
            break;

            case 11:exit(0);
        
            default:printf("\n Invalid choice!!");
        }
    }
}