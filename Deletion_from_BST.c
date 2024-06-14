//1.search key
struct node *search(struct node *tree,int key)
{
   temp=root;
   while(temp!=NULL){
    if(temp->data==key)
    {
        return temp;
    }
    else if(key>temp->data)
    {
        parent=temp;
        temp=temp->left;
    }
    else
    {
        parent=temp;
        temp=temp->right;
    }
   }
}
//leaf node deletion
if(temp->left==NULL&&temp->right==NULL)
{
    if(temp==parent->left){
        parent->left=NULL;
        free(temp);
    }
    if (temp==parent->right)
    {
        parent->right=NULL;
        free(temp);
    }
}
// node you have to delete is left child
if(temp->left!=NULL&&temp->right==NULL)
{
    if(temp==parent->left)
    {
    parent->left=temp->left;
    temp->left=NULL;
    free(temp);
    }
    else if(temp=parent->right)
    {
        parent->right=temp->left;
        temp->left=NULL;
        free(temp);
    }

}
else if(temp->left==NULL&&temp->right!=NULL)
{
    if(temp==parent->right)
    {
        parent->right=temp->left;
        temp->left=NULL;
        free(temp);
    }
    if(temp==parent->left)
    {
        parent->left=temp->right;
        temp->right=NULL;
        free(temp);
        
    }
    
}
//3rd case node with 2 childrens
if(temp=parent->right)
{
temp_succ=temp->right; 
if(temp_succ->left!=NULL)
{
   temp_succ=temp_succ->left;
}
temp_succ->data=temp->data;
temp_succ=NULL;
free(temp_succ);
}