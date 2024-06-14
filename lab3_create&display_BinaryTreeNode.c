
#include<stdio.h>
#include<stdlib.h>
struct tree{
    int data;
    struct tree *left;
    struct tree *right;
}*root,*newptr,*temp;
void create(int d)
{   
    struct tree * newptr;
    newptr=(struct tree*)malloc(sizeof(struct tree));
    root=newptr;
    newptr->data=d;
    newptr->left=NULL;
    newptr->right=NULL;
    
}
void insert(int d)
{
    if(root==NULL)
    {
        create(d);
    }
    else
    {   
        struct tree * temp;
        temp=(struct tree*)malloc(sizeof(struct tree));
        temp=root;
        while(1)
        {   int v,ch;
            int dir;
            printf("Enter the value");
            scanf("%d",&v);
            printf("where you hav to insert the %d ? \n1)l or 2)r",v);
            scanf("%d",&dir);
            if(dir==1)
            {   
                create(v);
                if(temp->left==NULL)
                {
                    temp->left=newptr;
                    // flag=1;
                }
                else
                {
                  temp=temp->left;
                }
            }
            else if(dir==2)
            {
                if(temp->right==NULL)
                {
                    temp->right=newptr;
                    // flag=1;
                }
                else
                {
                    temp=temp->right;
                }
            }
        }
    }
}
void display()
{
    if(root==NULL)
    {
        printf("tree is empty");
    }
    else{
        while(temp->next!=NULL)
        printf("%d\n",temp->data);
        temp=temp->data;
    }
    printf("%d\n",temp->data);
}
int main()
{
    create(10);
    insert(20);
    display();
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to display the binary tree (inorder traversal)
void displayTree(struct Node* root) {
    if (root == NULL)
        return;

    displayTree(root->left);
    printf("%d ", root->data);
    displayTree(root->right);
}

int main() {
    // Create the binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Display the binary tree
    printf("Binary Tree: ");
    displayTree(root);

    return 0;
}
