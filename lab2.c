#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head;
void create(int d)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    head=temp;
    temp->data=d;
    temp->next=NULL;    
}
void insert_begin(int d)
{
    if(head==NULL)
      create(d);
    else
    {
        struct node *temp;
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=d;
        temp->next=head;
        temp=head;
    }
}
void insert_mid(int d)
{
    if(head==NULL)
    {
        create(d);
    }
    else
    {
        int d;
        struct node *temp,*q;
        temp=(struct node*)malloc(sizeof(struct node));
        temp=head;
        while(q->data!=d)
        {
           q->next=q;
        }
        temp->next=q->next;
        q->next=temp;
        temp->data=d;
    }

}
void insert_end(int d)
{
    struct node *temp,*q;
    temp=(struct node*)malloc(sizeof(struct node));
    temp=head;
    temp->data=d;
    while(q->next!=NULL)
    {
        q=q->next;
    }
    q->next=temp;
    temp->next=NULL;

}
void delete_start(int d)
{
    if(head==NULL)
    {
        create(d);
    }
    else
    {
       struct node *temp;
       temp=head;
       head=temp->next;
       temp->next=NULL;
       free(temp);
    }
}
void delete_end(int d)
{
    if(head==NULL)
    {
        create(d);
    }
    else{
        struct node *temp,*q;
        temp=head;
        q=head;
        while(q->next!=NULL)
        {
            q=q->next;
        }
        q->next=temp;
        temp->next=NULL;
        q->next=NULL;
        free(temp);
    }
}
void delete_mid(int v)
{   int d;
    if(head==NULL)
    {
        create(v);
    }
    else
    {
        struct node *temp,*q;
        temp=head;
        q=head;
        while(q!=NULL)
    }
}
void display()
{
    if(head==NULL)
    {
        printf("The list is empty\n");
    }
    else
    { struct node *temp;
      temp=head;
      printf("The list is:\n");

      while(temp!=NULL)
      {
      printf("%d\n",temp->data);
           temp=temp->next;
      }
     // printf("%d\n",temp->data);
    }
}
int main()
{
    int ch,v,i,d,n;
    head=NULL;
    while(1)
    {
        printf("Enter your choice\n1.create\n2.display\n3.insert at start\n4.Insert at middle\n5.Insert at end\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the size of node");
                scanf("%d",&n);
                for(i=0;i<n;i++){
                printf("Enter the value");
                scanf("%d",&v);
                }
                create(v);
                break;
            
            case 2:
                display(v);
                break;

            case 3:
                 printf("Enter the value");
                 scanf("%d",&v);
                 insert_begin(v);
                 break;
            case 4:
                printf("Enter the value after which you want to insert the value\n");
                scanf("%d\n",&d);
                printf("enter the value\n");
                scanf("%d\n",&v);
                insert_mid(v);
                break;

            case 5:
                printf("Enter the Value");
                scanf("%d",&v);
                insert_end(v);
                break;
            case 6:
                exit(0);
                break;
        
        }
    }
}
