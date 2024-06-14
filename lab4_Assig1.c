// Write a menu driven program for creating BST and perform following 
// non recursive operations
// 1.Inorder traversal
// 2.Count Number of leaf nodes
// 3.Find height of the tree

 
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(struct TreeNode** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }

    struct TreeNode* current = *root;

    while (1) {
        if (data < current->data) {
            if (current->left == NULL) {
                current->left = createNode(data);
                break;
            }
            current = current->left;
        } else if (data > current->data) {
            if (current->right == NULL) {
                current->right = createNode(data);
                break;
            }
            current = current->right;
        } else {
            // Duplicate values are not allowed in BST
            printf("Duplicate value ignored\n");
            break;
        }
    }
}

void inorderTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct TreeNode* stack[100];
    int top = -1;
    struct TreeNode* current = root;

    while (1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        if (top >= 0) {
            current = stack[top--];
            printf("%d ", current->data);
            
            current = current->right;
        } else {
            break;
        }
    }
}

int countLeafNodes(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int count = 0;
    struct TreeNode* stack[100];
    int top = -1;

    stack[++top] = root;

    while (top >= 0) {
        struct TreeNode* current = stack[top--];

        if (current->left == NULL && current->right == NULL) {
            count++;
        }

        if (current->right != NULL) {
            stack[++top] = current->right;
        }
        if (current->left != NULL) {
            stack[++top] = current->left;
        }
    }

    return count;
}

int findHeight(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int height = 0;
    struct TreeNode* queue[100];
    int front = -1, rear = -1;

    queue[++rear] = root;

    while (front != rear) {
        int levelSize = rear - front;

        // Process nodes at the current level
        while (levelSize > 0) {
            struct TreeNode* current = queue[++front];

            if (current->left != NULL)
                queue[++rear] = current->left;
            if (current->right != NULL)
                queue[++rear] = current->right;

            levelSize--;
        }

        height++;
    }

    return height;
}

int main() {
    struct TreeNode* root = NULL;
    
    int choice, data;

    do {
        printf("\nMenu\n");
		printf("----\n");
		printf("1. Insert element\n");
		printf("2. Inorder traversal\n");
		printf("3. Count number of leaf nodes\n");
		printf("4. Find height of the tree\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &data);
                insert(&root, data);
                break;
            case 2:
                printf("Inorder traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Number of leaf nodes: %d\n", countLeafNodes(root));
                break;
            case 4:
                printf("Height of the tree: %d\n", findHeight(root));
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}