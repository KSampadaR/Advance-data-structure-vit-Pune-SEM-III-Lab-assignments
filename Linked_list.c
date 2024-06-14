#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head;

void create(int d)
{   
    struct node *q,*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=d;
    temp->next=NULL;
    head=temp;
   
}
void insert_begin(int d)
{   if(head==NULL)
{
     create(d);
}
    else
    {

    struct node *q,*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=d;
    temp->next=head;
    head=temp;
    }
}
void insert_end(int d)
{   if(head==NULL)
{
    create(d);
}   
    else{
    struct node *q,*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=d;
    temp->next=NULL;
    q=head;
    while(q->next!=NULL)
    {
       q=q->next;
    }
    q->next=temp;
    }
}

void insert_middle(int d, int v)
{
  if(head==NULL)
  {
    create(d);
  }
  else
  {
    struct node *q,*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=d;
    q=head;
    while(q->data!=v)
    {
        q=q->next;
    }
     temp->next=q->next;
     q->next=temp;
  }
}

void display()
{
    struct node *q,*temp;
    if(head==NULL)
    {
        printf("Empty");
    }
    else
    { temp=head;
      while(temp->next!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
      }
        printf("%d \n",temp->data);
    }
}

void delete_begin()
    {
        if(head==NULL)
        {
           printf("empty");
        }
        else
        {
            struct node *q,*temp;
           temp=head;
           head=temp->next;
           free(temp);
        }
    }

void delete_end()
{
    if(head==NULL)
    {
        printf("Empty");
    }
    else{
        struct node *q,*temp;
        temp=head;
        q=head;
        while(temp->next!=NULL)
        {   
            q=temp;
            temp=temp->next;
        }
        q->next=NULL;
        free(temp);
    }
}

void delete_middle(int v)
{  
    if(head==NULL)
    {
        printf("empty");
    }
    else{
        struct node *q,*temp;
        temp=head;
        q=head;
        while(temp->data!=v)
        {    
            q=temp;
            temp=temp->next;
        }
        q->next=temp->next;
        free(temp);
    }
}
void main(){
    head=NULL;
    while (1)
    {
        
        int ch,v,i,n,a[20],pos,d;
        printf("0)Exit\n1)create\n2)display\n3)add at begin\n4)\n5\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        fflush(stdin);
        switch (ch)
        {
        case 0:
            exit(0);
            break;
        case 1:
            printf("Enter the size of No's:\n");
            scanf("%d",&v);
            for(i=0;i<v;i++){
            printf("Enter the value");
            scanf("%d",&n);
            create(n);
             break;
        case 2:
            display();
            break;
        case 3:
            printf("enter the element\n");
            scanf("%d",&v);
            insert_begin(v);
            break;
        case 4:
            printf("enter the position\n");
            scanf("%d",&pos);
            printf("Enter the element\n");
            scanf("%d",&v);
            insert_middle(v,pos);
            break;
       
        }
    }
    } 
}