#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
    int isThreaded;
};

struct Node *root = NULL;

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->isThreaded = 0;
    return newNode;
}

struct Node *inorderSuccessor(struct Node *node) {
    if (node == NULL)
        return NULL;
    struct Node *temp = node->right;
    if (!node->isThreaded) {
        while (temp && !temp->left)
            temp = temp->left;
    }
    return temp;
}

void createThreadedBinaryTree(struct Node *node) {
    if (!node)
        return;
    struct Node *successor = inorderSuccessor(node);
    if (node->right == NULL)
        node->isThreaded = 1;
    createThreadedBinaryTree(node->left);
    if (successor)
        node->right = successor;
    createThreadedBinaryTree(successor);
}

void preorderTraversal(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        if (!node->isThreaded)
            node = node->left;
        else
            node = node->right;
    }
}

int main() {
    int choice, data;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert into Threaded Binary Tree\n");
        printf("2. Create Inorder Threaded Binary Tree\n");
        printf("3. Traverse in Preorder\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                if (root == NULL) {
                    root = createNode(data);
                } else {
                    // Add your logic here to insert nodes into the threaded binary tree
                }
                break;
            case 2:
                if (root == NULL) {
                    printf("Threaded Binary Tree is empty. Insert nodes first.\n");
                } else {
                    createThreadedBinaryTree(root);
                    printf("Inorder Threaded Binary Tree created.\n");
                }
                break;
            case 3:
                if (root == NULL) {
                    printf("Threaded Binary Tree is empty. Insert nodes first.\n");
                } else {
                    printf("Preorder Traversal of the Threaded Binary Tree:\n");
                    preorderTraversal(root);
                    printf("\n");
                }
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}
