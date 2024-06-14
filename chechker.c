
// // // // // // // // #include<stdio.h>
// // // // // // // // #include<stdlib.h>
// // // // // // // // struct tree{
// // // // // // // //     int data;
// // // // // // // //     struct tree *left;
// // // // // // // //     struct tree *right;
// // // // // // // // }*root,*newptr,*temp;
// // // // // // // // void create(int d)
// // // // // // // // {   
// // // // // // // //     struct tree * newptr;
// // // // // // // //     newptr=(struct tree*)malloc(sizeof(struct tree));
// // // // // // // //     root=newptr;
// // // // // // // //     newptr->data=d;
// // // // // // // //     newptr->left=NULL;
// // // // // // // //     newptr->right=NULL;
    
// // // // // // // // }
// // // // // // // // void insert_right(int d)
// // // // // // // // {
// // // // // // // //     if(root==NULL)
// // // // // // // //     {
// // // // // // // //         create(d);
// // // // // // // //     }
// // // // // // // //     else
// // // // // // // //     {   
// // // // // // // //         struct tree * temp;
// // // // // // // //         temp=(struct tree*)malloc(sizeof(struct tree));
// // // // // // // //         temp=root;
// // // // // // // //         printf("Enter the Root node:\n");
// // // // // // // //         scanf("%d\n",root->data);
// // // // // // // //         while(1)
// // // // // // // //         {   int v,ch;
// // // // // // // //             int dir;
            
// // // // // // // //             printf("Enter the value");
// // // // // // // //             scanf("%d",&v);
// // // // // // // //             printf("where you hav to insert the %d ? \n1)l or 2)r",v);
// // // // // // // //             scanf("%d",&dir);
// // // // // // // //             if(dir==1)
// // // // // // // //             {   
// // // // // // // //                 create(v);
// // // // // // // //                 if(temp->left==NULL)
// // // // // // // //                 {
// // // // // // // //                     temp->left=newptr;
// // // // // // // //                     // flag=1;
// // // // // // // //                 }
// // // // // // // //                 else
// // // // // // // //                 {
// // // // // // // //                   temp=temp->left;
// // // // // // // //                 }
// // // // // // // //             }
// // // // // // // //             else if(dir==2)
// // // // // // // //             {
// // // // // // // //                 if(temp->right==NULL)
// // // // // // // //                 {
// // // // // // // //                     temp->right=newptr;
// // // // // // // //                     // flag=1;
// // // // // // // //                 }
// // // // // // // //                 else
// // // // // // // //                 {
// // // // // // // //                     temp=temp->right;
// // // // // // // //                 }
// // // // // // // //             }
// // // // // // // //         }
// // // // // // // //     }
// // // // // // // // }
// // // // // // // // void display()
// // // // // // // // {
// // // // // // // //     if(root==NULL)
// // // // // // // //     {
// // // // // // // //         printf("tree is empty");
// // // // // // // //     }
// // // // // // // //     else{
// // // // // // // //         while(temp->left!=NULL)
// // // // // // // //         printf("%d\n",temp->data);
// // // // // // // //         temp=temp->left;
// // // // // // // //     }
// // // // // // // //     printf("%d\n",temp->data);
// // // // // // // // }
// // // // // // // // int main()
// // // // // // // // {
// // // // // // // //     create(20);
// // // // // // // //     insert_right();
// // // // // // // //     display();
// // // // // // // //     return 0;
// // // // // // // // }
// // // // // // // #include<stdio.h>
// // // // // // // #include<stdlib.h>

// // // // // // // struct node {
// // // // // // //     int data;
// // // // // // //     struct node *left;
// // // // // // //     struct node *right;
// // // // // // // };

// // // // // // // struct node* createNode(int d) {
// // // // // // //     struct node* newNode = (struct node*)malloc(sizeof(struct node));
// // // // // // //     newNode->data = d;
// // // // // // //     newNode->left = NULL;
// // // // // // //     newNode->right = NULL;
// // // // // // //     return newNode;
// // // // // // // }

// // // // // // // struct node* insert(struct node* root, int d) {
// // // // // // //     if (root == NULL) {
// // // // // // //         return createNode(d);
// // // // // // //     } else {
// // // // // // //         if (d <= root->data) {
// // // // // // //             root->left = insert(root->left, d);
// // // // // // //         } else {
// // // // // // //             root->right = insert(root->right, d);
// // // // // // //         }
// // // // // // //         return root;
// // // // // // //     }
// // // // // // // }

// // // // // // // void inorderTraversal(struct node* root) {
// // // // // // //     if (root != NULL) {
// // // // // // //         inorderTraversal(root->left);
// // // // // // //         printf("%d ", root->data);
// // // // // // //         inorderTraversal(root->right);
// // // // // // //     }
// // // // // // // }

// // // // // // // int countLeafNodes(struct node* root) {
// // // // // // //     if (root == NULL) {
// // // // // // //         return 0;
// // // // // // //     }
// // // // // // //     if (root->left == NULL && root->right == NULL) {
// // // // // // //         return 1;
// // // // // // //     }
// // // // // // //     return countLeafNodes(root->left) + countLeafNodes(root->right);
// // // // // // // }

// // // // // // // int findHeight(struct node* root) {
// // // // // // //     if (root == NULL) {
// // // // // // //         return -1;
// // // // // // //     }
// // // // // // //     int leftHeight = findHeight(root->left);
// // // // // // //     int rightHeight = findHeight(root->right);
// // // // // // //     return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
// // // // // // // }

// // // // // // // int main() {
// // // // // // //     struct node* root = NULL;
// // // // // // //     int v, n;

// // // // // // //     printf("Enter number of nodes: ");
// // // // // // //     scanf("%d", &n);

// // // // // // //     printf("Enter values:\n");
// // // // // // //     for (int i = 0; i < n; i++) {
// // // // // // //         scanf("%d", &v);
// // // // // // //         root = insert(root, v);
// // // // // // //     }

// // // // // // //     printf("Inorder Traversal: ");
// // // // // // //     inorderTraversal(root);
// // // // // // //     printf("\n");

// // // // // // //     int leafCount = countLeafNodes(root);
// // // // // // //     printf("Number of leaf nodes: %d\n", leafCount);

// // // // // // //     int height = findHeight(root);
// // // // // // //     printf("Height of the tree: %d\n", height);

// // // // // // //     return 0;
// // // // // // // }
// // // // // // #include <stdio.h>
// // // // // // #include <stdlib.h>
// // // // // // #define bool int

// // // // // // // A binary tree tNode has data, pointer to left child
// // // // // // // and a pointer to right child
// // // // // // struct tNode {
// // // // // // 	int data;
// // // // // // 	struct tNode* left;
// // // // // // 	struct tNode* right;
// // // // // // };

// // // // // // // Structure of a stack node. Linked List implementation is
// // // // // // // used for stack. A stack node contains a pointer to tree
// // // // // // // node and a pointer to next stack node
// // // // // // struct sNode {
// // // // // // 	struct tNode* t;
// // // // // // 	struct sNode* next;
// // // // // // };

// // // // // // // Stack related functions
// // // // // // void push(struct sNode** top_ref, struct tNode* t);
// // // // // // struct tNode* pop(struct sNode** top_ref);
// // // // // // bool isEmpty(struct sNode* top);

// // // // // // // Iterative function for inorder tree traversal
// // // // // // void inOrder(struct tNode* root)
// // // // // // {
// // // // // // 	// Set current to root of binary tree
// // // // // // 	struct tNode* current = root;

// // // // // // 	// Initialize stack s
// // // // // // 	struct sNode* s = NULL;
// // // // // // 	bool done = 0;

// // // // // // 	while (!done) {
		
// // // // // // 		// Reach the left most tNode of the current tNode
// // // // // // 		if (current != NULL) {
			
// // // // // // 			// Place pointer to a tree node on the stack
// // // // // // 			// before traversing the node's left subtree
// // // // // // 			push(&s, current);
// // // // // // 			current = current->left;
// // // // // // 		}

// // // // // // 		// Backtrack from the empty subtree and visit the
// // // // // // 		// tNode at the top of the stack; however, if the
// // // // // // 		// stack is empty, you are done
// // // // // // 		else {
// // // // // // 			if (!isEmpty(s)) {
// // // // // // 				current = pop(&s);
// // // // // // 				printf("%d ", current->data);

// // // // // // 				// we have visited the node and its left
// // // // // // 				// subtree. Now, it's right subtree's turn
// // // // // // 				current = current->right;
// // // // // // 			}
// // // // // // 			else
// // // // // // 				done = 1;
// // // // // // 		}
// // // // // // 	}
// // // // // // }

// // // // // // // Function to push an item to sNode
// // // // // // void push(struct sNode** top_ref, struct tNode* t)
// // // // // // {
// // // // // // 	// Allocate tNode
// // // // // // 	struct sNode* new_tNode
// // // // // // 		= (struct sNode*)malloc(sizeof(struct sNode));

// // // // // // 	if (new_tNode == NULL) {
// // // // // // 		printf("Stack Overflow \n");
// // // // // // 		getchar();
// // // // // // 		exit(0);
// // // // // // 	}

// // // // // // 	// Put in the data
// // // // // // 	new_tNode->t = t;

// // // // // // 	// Link the old list of the new tNode
// // // // // // 	new_tNode->next = (*top_ref);

// // // // // // 	// Move the head to point to the new tNode
// // // // // // 	(*top_ref) = new_tNode;
// // // // // // }

// // // // // // // The function returns true if stack is empty,
// // // // // // // otherwise false
// // // // // // bool isEmpty(struct sNode* top)
// // // // // // {
// // // // // // 	return (top == NULL) ? 1 : 0;
// // // // // // }

// // // // // // // Function to pop an item from stack
// // // // // // struct tNode* pop(struct sNode** top_ref)
// // // // // // {
// // // // // // 	struct tNode* res;
// // // // // // 	struct sNode* top;

// // // // // // 	// If sNode is empty then error
// // // // // // 	if (isEmpty(*top_ref)) {
// // // // // // 		printf("Stack Underflow \n");
// // // // // // 		getchar();
// // // // // // 		exit(0);
// // // // // // 	}
// // // // // // 	else {
// // // // // // 		top = *top_ref;
// // // // // // 		res = top->t;
// // // // // // 		*top_ref = top->next;
// // // // // // 		free(top);
// // // // // // 		return res;
// // // // // // 	}
// // // // // // }

// // // // // // // Helper function that allocates a new tNode with the
// // // // // // // given data and NULL left and right pointers.
// // // // // // struct tNode* newtNode(int data)
// // // // // // {
// // // // // // 	struct tNode* tNode
// // // // // // 		= (struct tNode*)malloc(sizeof(struct tNode));
// // // // // // 	tNode->data = data;
// // // // // // 	tNode->left = NULL;
// // // // // // 	tNode->right = NULL;

// // // // // // 	return (tNode);
// // // // // // }

// // // // // // // Driver program to test above functions
// // // // // // int main()
// // // // // // {
// // // // // // 	/* Constructed binary tree is
// // // // // // 			1
// // // // // // 			/ \
// // // // // // 		2	 3
// // // // // // 		/ \
// // // // // // 	4	 5
// // // // // // 	*/
// // // // // // 	struct tNode* root = newtNode(1);
// // // // // // 	root->left = newtNode(2);
// // // // // // 	root->right = newtNode(3);
// // // // // // 	root->left->left = newtNode(4);
// // // // // // 	root->left->right = newtNode(5);

// // // // // // 	inOrder(root);

// // // // // // 	getchar();
// // // // // // 	return 0;
// // // // // // }
// // // // // #include<stdio.h>
// // // // // #include<stdlib.h>

// // // // // struct node
// // // // // {
// // // // //     int data;
// // // // //     struct node *left;
// // // // //     struct node *right;
// // // // // }*root;
// // // // // void create(int d)
// // // // // {
// // // // //     struct node *temp;
// // // // //     temp=malloc(sizeof(struct node));
// // // // //     temp=root;
// // // // //     temp->data=d;
// // // // //     temp->left=NULL;
// // // // //     temp->right=NULL;
// // // // // }
// // // // // struct snode
// // // // // {
// // // // //   int data;
// // // // //   struct node *next;
// // // // // }*new,*top;
// // // // // int push(int v)
// // // // // {
// // // // //   new=(struct snode*)malloc(sizeof(struct snode));
// // // // //   new->data=v;
// // // // //   new->next=NULL;
// // // // //   if(top==NULL)
// // // // //   {
// // // // //     new=top;
// // // // //   }
// // // // //   else
// // // // //   {
// // // // //     new=top;
// // // // //     top=new->next;
// // // // //   }
// // // // // }

// // // // // int display()
// // // // // {   
// // // // //  struct snode *new;
// // // // //   new=top;
// // // // //   while(top==NULL)
// // // // //   {
// // // // //     printf("%d",new->data);
// // // // //     top=new->next;
// // // // //   }
// // // // // }
// // // // //  int main()
// // // // //  {
// // // // //    int ch,i,v;
// // // // //    while(1)
// // // // //    {
// // // // //    scanf("%d",&ch);
// // // // //    switch(ch)
// // // // //    {
// // // // //      case 1:{
// // // // //        create(22);
// // // // //        push(20);
// // // // //        push(25);
// // // // //        break;
// // // // //    }
// // // // //      case 2:
// // // // //        {
// // // // //          display();
// // // // //          break;
// // // // //        }
// // // // #include <stdio.h>
// // // // #include <stdlib.h>

// // // // struct TreeNode {
// // // //     int value;
// // // //     struct TreeNode* left;
// // // //     struct TreeNode* right;
// // // // };

// // // // // Stack data structure for iterative traversal
// // // // struct StackNode {
// // // //     struct TreeNode* treeNode;
// // // //     struct StackNode* next;
// // // // };

// // // // struct Stack {
// // // //     struct StackNode* top;
// // // // };

// // // // // Function to create a new stack node
// // // // struct StackNode* createStackNode(struct TreeNode* treeNode) {
// // // //     struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
// // // //     stackNode->treeNode = treeNode;
// // // //     stackNode->next = NULL;
// // // //     return stackNode;
// // // // }

// // // // // Function to initialize the stack
// // // // struct Stack* createStack() {
// // // //     struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
// // // //     stack->top = NULL;
// // // //     return stack;
// // // // }

// // // // // Function to check if the stack is empty
// // // // int isStackEmpty(struct Stack* stack) {
// // // //     return stack->top == NULL;
// // // // }

// // // // // Function to push a node onto the stack
// // // // void push(struct Stack* stack, struct TreeNode* treeNode) {
// // // //     struct StackNode* stackNode = createStackNode(treeNode);
// // // //     stackNode->next = stack->top;
// // // //     stack->top = stackNode;
// // // // }

// // // // // Function to pop a node from the stack
// // // // struct TreeNode* pop(struct Stack* stack) {
// // // //     if (isStackEmpty(stack))
// // // //         return NULL;

// // // //     struct TreeNode* popped = stack->top->treeNode;
// // // //     struct StackNode* temp = stack->top;
// // // //     stack->top = stack->top->next;
// // // //     free(temp);
// // // //     return popped;
// // // // }

// // // // // Function to count the number of leaf nodes using iterative in-order traversal
// // // // int countLeafNodes(struct TreeNode* root) {
// // // //     if (root == NULL)
// // // //         return 0;

// // // //     int leafCount = 0;
// // // //     struct Stack* stack = createStack();
// // // //     struct TreeNode* current = root;

// // // //     while (current != NULL || !isStackEmpty(stack)) {
// // // //         while (current != NULL) {
// // // //             push(stack, current);
// // // //             current = current->left;
// // // //         }

// // // //         current = pop(stack);

// // // //         if (current->left == NULL && current->right == NULL)
// // // //             leafCount++;

// // // //         current = current->right;
// // // //     }

// // // //     return leafCount;
// // // // }

// // // // // Helper function to create a new node in the BST
// // // // struct TreeNode* createNode(int value) {
// // // //     struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
// // // //     newNode->value = value;
// // // //     newNode->left = NULL;
// // // //     newNode->right = NULL;
// // // //     return newNode;
// // // // }

// // // // // Helper function to insert a node in the BST
// // // // struct TreeNode* insert(struct TreeNode* root, int value) {
// // // //     if (root == NULL)
// // // //         return createNode(value);

// // // //     if (value < root->value)
// // // //         root->left = insert(root->left, value);
// // // //     else if (value > root->value)
// // // //         root->right = insert(root->right, value);

// // // //     return root;
// // // // }

// // // // // Example usage
// // // // int main() {
// // // //     struct TreeNode* root = NULL;
// // // //     root = insert(root, 10);
// // // //     insert(root, 5);
// // // //     insert(root, 15);
// // // //     insert(root, 3);
// // // //     insert(root, 7);
// // // //     insert(root, 12);
// // // //     insert(root, 18);

// // // //     int leafCount = countLeafNodes(root);
// // // //     printf("Number of leaf nodes in the BST: %d\n", leafCount);

// // // //     return 0;
// // // // }

// // // // //     }
// // // // //   }
// // // // //  }
// // // #include <stdio.h>
// // // #include <stdlib.h>

// // // // Structure for BST node
// // // struct TreeNode {
// // //     int data;
// // //     struct TreeNode* left;
// // //     struct TreeNode* right;
// // // };

// // // // Function to create a new node in the BST
// // // struct TreeNode* createNode(int value) {
// // //     struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
// // //     newNode->data = value;
// // //     newNode->left = NULL;
// // //     newNode->right = NULL;
// // //     return newNode;
// // // }

// // // // Function to insert a node in the BST
// // // struct TreeNode* insert(struct TreeNode* root, int value) {
// // //     if (root == NULL)
// // //         return createNode(value);

// // //     if (value < root->data)
// // //         root->left = insert(root->left, value);
// // //     else if (value > root->data)
// // //         root->right = insert(root->right, value);

// // //     return root;
// // // }

// // // // Function for non-recursive in-order traversal of the BST
// // // void inorderTraversal(struct TreeNode* root) {
// // //     struct TreeNode* stack[100]; // Maximum stack size, adjust as needed
// // //     int top = -1;
// // //     struct TreeNode* current = root;

// // //     while (current != NULL || top != -1) {
// // //         while (current != NULL) {
// // //             stack[++top] = current;
// // //             current = current->left;
// // //         }

// // //         current = stack[top--];
// // //         printf("%d ", current->data);
// // //         current = current->right;
// // //     }
// // // }

// // // // Function to count the number of leaf nodes in the BST
// // // int countLeafNodes(struct TreeNode* root) {
// // //     if (root == NULL)
// // //         return 0;

// // //     int leafCount = 0;
// // //     struct TreeNode* stack[100]; // Maximum stack size, adjust as needed
// // //     int top = -1;
// // //     struct TreeNode* current = root;

// // //     while (current != NULL || top != -1) {
// // //         while (current != NULL) {
// // //             stack[++top] = current;
// // //             current = current->left;
// // //         }

// // //         current = stack[top--];

// // //         if (current->left == NULL && current->right == NULL)
// // //             leafCount++;

// // //         current = current->right;
// // //     }

// // //     return leafCount;
// // // }

// // // // Function to find the height of the BST
// // // int findHeight(struct TreeNode* root) {
// // //     if (root == NULL)
// // //         return -1;

// // //     int height = 0;
// // //     struct TreeNode* stack[100]; // Maximum stack size, adjust as needed
// // //     int top = -1;
// // //     struct TreeNode* current = root;
// // //     int maxDepth = 0;

// // //     while (current != NULL || top != -1) {
// // //         while (current != NULL) {
// // //             stack[++top] = current;
// // //             current = current->left;
// // //             height++;
// // //         }

// // //         current = stack[top--];
// // //         if (height > maxDepth)
// // //             maxDepth = height;

// // //         current = current->right;
// // //         height++;
// // //     }

// // //     return maxDepth;
// // // }

// // // // Function to display the menu
// // // void displayMenu() {
// // //     printf("\nMenu:\n");
// // //     printf("1. Insert node in BST\n");
// // //     printf("2. In-order Traversal\n");
// // //     printf("3. Count number of leaf nodes\n");
// // //     printf("4. Find height of the tree\n");
// // //     printf("5. Exit\n");
// // //     printf("Enter your choice: ");
// // // }

// // // // Function to clear the input buffer
// // // void clearInputBuffer() {
// // //     while (getchar() != '\n')
// // //         continue;
// // // }

// // // int main() {
// // //     struct TreeNode* root = NULL;
// // //     int choice, value;

// // //     do {
// // //         displayMenu();
// // //         scanf("%d", &choice);
// // //         clearInputBuffer(); // Clear the input buffer to avoid any issues

// // //         switch (choice) {
// // //             case 1:
// // //                 printf("Enter the value to insert: ");
// // //                 scanf("%d", &value);
// // //                 clearInputBuffer();
// // //                 root = insert(root, value);
// // //                 break;
// // //             case 2:
// // //                 printf("In-order Traversal: ");
// // //                 inorderTraversal(root);
// // //                 printf("\n");
// // //                 break;
// // //             case 3:
// // //                 printf("Number of leaf nodes: %d\n", countLeafNodes(root));
// // //                 break;
// // //             case 4:
// // //                 printf("Height of the tree: %d\n", findHeight(root));
// // //                 break;
// // //             case 5:
// // //                 printf("Exiting program.\n");
// // //                 break;
// // //             default:
// // //                 printf("Invalid choice. Please try again.\n");
// // //         }
// // //     } while (choice != 5);

// // //     return 0;
// // // }
// // int findHeight(struct TreeNode* root) {
// //     if (root == NULL)
// //         return -1;

// //     int height = 0;
// //     struct TreeNode* stack[100]; 
// //     int top = -1;
// //     struct TreeNode* current = root;
// //     int maxDepth = 0;

// //     while (current != NULL || top != -1) {
// //         while (current != NULL) {
// //             stack[++top] = current;
// //             current = current->left;
// //             height++;
// //         }

// //         current = stack[top--];
// //         if (height > maxDepth)
// //             maxDepth = height;

// //         current = current->right;
// //         height++;
// //     }

// //     return maxDepth;
// // }

// // int h(struct node*root)
// // {
// //     if(root==nnull)
// // {
// //     return 0;

// // }
// //    else{
// //     struct node*temp=root;
// //     int hight=0;
// //     int depth=0;
// //     int stack[100];
// //     int top=-1;
// //     while(temp!=NNULL||top!=-1)
// //     {
// //         while(temp!=NULL)
// //         {
// //             stcak[++]=temp;
// //             temp=temp->left;
// //             hiegh++;

// //         }
// //         temp=stack[top--];
// //         if(hieght>depth){
// //             hieght=depth;

// //         }
// //         temp=temp->right;
// //         hight++;
// //         return hight;
// //     }
// //    }
// // }
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct TreeNode {
//     int data;
//     struct TreeNode* left;
//     struct TreeNode* right;
// } TreeNode;

// // Function to create a new node
// TreeNode* createNode(int data) {
//     TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
//     newNode->data = data;
//     newNode->left = newNode->right = NULL;
//     return newNode;
// }

// // Function to insert a new node into the BST
// TreeNode* insert(TreeNode* root, int data) {
//     if (root == NULL) {
//         return createNode(data);
//     } else if (data <= root->data) {
//         root->left = insert(root->left, data);
//     } else {
//         root->right = insert(root->right, data);
//     }
//     return root;
// }

// // Function to find the height and count leaf nodes of a BST non-recursively using a queue
// void findHeightAndLeafCount(TreeNode* root, int* height, int* leafCount) {
//     if (root == NULL) {
//         *height = -1; // Height of an empty tree is -1
//         *leafCount = 0;
//         return;
//     }

//     *height = -1;
//     *leafCount = 0;

//     TreeNode* queue[100];  // Assuming a maximum of 100 nodes in the queue
//     int front = 0, rear = 0;

//     queue[rear++] = root;

//     while (front < rear) {
//         int levelSize = rear - front;

//         while (levelSize > 0) {
//             TreeNode* current = queue[front++];

//             if (current->left == NULL && current->right == NULL) {
//                 (*leafCount)++;
//             }

//             if (current->left != NULL) {
//                 queue[rear++] = current->left;
//             }
//             if (current->right != NULL) {
//                 queue[rear++] = current->right;
//             }

//             levelSize--;
//         }

//         (*height)++;
//     }
// }

// int main() {
//     TreeNode* root = NULL;
//     root = insert(root, 10);
//     root = insert(root, 5);
//     root = insert(root, 15);
//     root = insert(root, 3);
//     root = insert(root, 7);
//     root = insert(root, 12);
//     root = insert(root, 18);

//     int treeHeight, leafCount;
//     findHeightAndLeafCount(root, &treeHeight, &leafCount);

//     printf("Height of the Binary Search Tree: %d\n", treeHeight);
//     printf("Number of leaf nodes: %d\n", leafCount);

//     return 0;
// }
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

struct Date {
    int dd;
    int mm;
    int yy;
};

struct Date date;

struct Reminder {
    int dd;
    int mm;
    char note[60];
};

struct Reminder R;

COORD xy = {0, 0};

// Setting the cursor
void gotoxy(int x, int y)  // X and Y coordinates
{
    xy.X = x;
    xy.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),  xy);
}

// Checking for a leap year
int LeapYear(int year)
{
    if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
        return 1;
    return 0;
}

// Increasing month number
void countMonth(int *mm, int *yy)
{
    ++*mm;
    if (*mm > 12)
    {
        ++*yy;
        *mm = *mm - 12;
    }
}

// Decreasing month number
void reduceMonth(int *mm, int *yy)
{
    --*mm;
    if (*mm < 1)
    {
        --*yy;
        *mm = *mm + 12;
    }
}

// Number of days in a month
int NumberOfDays(int month, int year)
{
    switch (month)
    {
        case 1: return(31);
        case 2: if (LeapYear(year) == 1)
            return(29);
        else
            return(28);
        case 3: return(31);
        case 4: return(30);
        case 5: return(31);
        case 6: return(30);
        case 7: return(31);
        case 8: return(31);
        case 9: return(30);
        case 10: return(31);
        case 11: return(30);
        case 12: return(31);
        default: return(-1);
    }
}

// Name of the day based on number
char *getName(int day)
{
    switch (day)
    {
        case 0: return("Sunday\t");
        case 1: return("Monday\t");
        case 2: return("Tuesday\t");
        case 3: return("Wednesday\t");
        case 4: return("Thursday\t");
        case 5: return("Friday\t");
        case 6: return("Saturday\t");
        default: return("Error in get name\t");
    }
}

// Printing name of month and year
void print_date(int mm, int yy)
{
    printf("++++++++++++++++++++++++\n");
    gotoxy(25, 6);
    switch (mm)
    {
        case 1: printf("Jan");
            break;
        case 2: printf("Feb");
            break;
        case 3: printf("Mar");
            break;
        case 4: printf("Apr");
            break;
        case 5: printf("May");
            break;
        case 6: printf("Jun");
            break;
        case 7: printf("Jul");
            break;
        case 8: printf("Aug");
            break;
        case 9: printf("Sep");
            break;
        case 10: printf("Oct");
            break;
        case 11: printf("Nov");
            break;
        case 12: printf("Dec");
            break;

        default: printf("Error getting name\t");
            break;
    }
    printf(" ,%d", yy);
    gotoxy(20, 7);
    printf("-------------------------\n");
}

// Getting day number
int getDayNumber(int day, int mon, int year)
{
    int res = 0, t1, t2, y = year;
    year = year - 1600;
    while (year >= 100)
    {
        res = res + 5;
        year = year - 100;
    }
    res = (res % 7);
    t1 = ((year - 1) / 4);
    t2 = (year - 1) - t1;
    t1 = (t1 * 2) + t2;
    t1 = t1 % 7;
    res = res + t1;
    res = res % 7;
    t2 = 0;
    for (t1 = 1; t1 < mon; t1++)
    {
        t2 += NumberOfDays(t1, y);
    }

    t2 = t2 + day;
    t2 = t2 % 7;
    res = res + t2;
    res = res % 7;

    if (y > 2000)
        res += 1;
    res = res % 7;
    return res;
}

char *getDay(int dd, int mm, int yy)
{
    int day;
    if (!(mm >= 1 && mm <= 12))
    {
        return ("Invalid month value");
    }
    if (!(dd >= 1 && dd <= NumberOfDays(mm, yy)))
    {
        return ("Invalid date");
    }
    if (yy >= 1600)
    {
        day = getDayNumber(dd, mm, yy);
        day = day % 7;
        return (getName(day));
    }
}

int checkEvent(int dd, int mm)
{
    FILE *fp;
    fp = fopen("event.dat", "rb");
    if (fp == NULL)
    {
        printf("Error in Opening the file");
    }
    while (fread(&R, sizeof(R), 1, fp) == 1)
    {
        if (R.dd == dd && R.mm == mm)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

void printMonth(int mon, int year, int x, int y)
{
    system("color 9f");
    int nod, day, cnt, d = 1, x1 = x, y1 = y, isEvent = 0;
    if (!(mon >= 1 && mon <= 12))
    {
        printf("INVALID MONTH");
        getchar();
        return;
    }
    if (!(year >= 1600))
    {
        printf("INVALID YEAR");
        getchar();
        return;
    }
    gotoxy(20, y);
    print_date(mon, year);
    y += 3;
    gotoxy(x, y);
    printf("S   M   T   W   T   F   S   ");
    y++;
    nod = NumberOfDays(mon, year);
    day = getDayNumber(d, mon, year);
    switch (day)
    {
    case 0:
        x = x;
        cnt = 1;
        break;
    case 1:
        x = x + 4;
        cnt = 2;
        break;
    case 2:
        x = x + 8;
        cnt = 3;
        break;
    case 3:
        x = x + 12;
        cnt = 4;
        break;
    case 4:
        x = x + 16;
        cnt = 5;
        break;
    case 5:
        x = x + 20;
        cnt = 6;
        break;
    case 6:
        x = x + 24;
        cnt = 7;
        break;
    default:
        printf("INVALID DATA FROM THE getOddNumber() MODULE");
        return;
    }
    gotoxy(x, y);

    printf("%02d", d);
    for (d = 2; d <= nod; d++)
    {
        if (cnt % 7 == 0)
        {
            y++;
            cnt = 0;
            x = x1 - 4;
        }
        x = x + 4;
        cnt++;
        gotoxy(x, y);
        printf("%02d", d);
    }
    gotoxy(8, y + 2);
    printf("Press 'n'  to Next, Press 'p' to Previous and 'q' to Quit");
    gotoxy(8, y + 3);
    printf("Press 's' to see events: ");
}

void AddEvent()
{
    system("color 02");
    FILE *fp;
    fp = fopen("event.dat", "ab+");
    system("cls");
    gotoxy(5, 7);
    printf("Enter the date (DD MM): ");
    scanf("%d %d", &R.dd, &R.mm);
    gotoxy(5, 8);
    printf("Enter the Event (50 character max): ");
    fflush(stdin);
    scanf("%[^\n]", R.note);
    if (fwrite(&R, sizeof(R), 1, fp))
    {
        gotoxy(5, 12);
        puts("Event is saved successfully");
        fclose(fp);
    }
    else
    {
        gotoxy(5, 12);
        puts("\aFail to save!!\a");
    }
    gotoxy(5, 15);
    printf("Press any key............");
    getch();
    fclose(fp);
}

void showEvent(int mm)
{
    system("color 02");
    FILE *fp;
    int i = 0, isFound = 0;
    system("cls");
    fp = fopen("event.dat", "rb");
    if (fp == NULL)
    {
        printf("Error in opening the file");
    }
    while (fread(&R, sizeof(R), 1, fp) == 1)
    {
        if (R.mm == mm)
        {
            gotoxy(10, 5 + i);
            printf("Event %d Day = %d: %s", i + 1, R.dd, R.note);
            isFound = 1;
            i++;
        }
    }
    if (isFound == 0)
    {
        gotoxy(10, 5);
        printf("This Month contains no events");
    }
    gotoxy(10, 7 + i);
    printf("Press any key to back.......");
    getch();
}

int main()
{
    system("title Calendar Wiz");
    system("color bc");
    int choice;
    char ch;
    while (1)
    {
        system("color bc");
        ch = 'a';
        system("cls");
        printf("1. Find Out the Day\n");
        printf("2. Print all the day of month\n");
        printf("3. Add Event\n");
        printf("4. EXIT\n");
        printf("ENTER YOUR CHOICE : ");
        scanf("%d", &choice);
        system("cls");
        switch (choice)
        {
        case 1:
            system("color 5f");
            printf("Enter date (DD MM YYYY) : ");
            scanf("%d %d %d", &date.dd, &date.mm, &date.yy);
            printf("Day is : %s", getDay(date.dd, date.mm, date.yy));
            printf("\nPress any key to continue......");
            getch();
            break;
        case 2:
            system("color 9f");
            printf("Enter month and year (MM YYYY) : ");
            scanf("%d %d", &date.mm, &date.yy);
            system("cls");
            while (ch != 'q')
            {
                printMonth(date.mm, date.yy, 20, 5);
                ch = getch();
                if (ch == 'n')
                {
                    countMonth(&date.mm, &date.yy);
                    system("cls");
                    printMonth(date.mm, date.yy, 20, 5);
                }
                else if (ch == 'p')
                {
                    reduceMonth(&date.mm, &date.yy);
                    system("cls");
                    printMonth(date.mm, date.yy, 20, 5);
                }
                else if (ch == 's')
                {
                    showEvent(date.mm);
                    system("cls");
                }
            }
            break;
        case 3:
            AddEvent();
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}