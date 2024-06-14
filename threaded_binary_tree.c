#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int leftThread;
    int rightThread;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->leftThread = 0;
    newNode->rightThread = 0;
    return newNode;
}

void insert(struct Node** root, int data) {
    struct Node* newNode = createNode(data);

    if (*root == NULL) {
        *root = newNode;
        return;
    }

    struct Node* current = *root;
    while (1) {
        if (data < current->data) {
            if (current->leftThread == 0) {
                newNode->left = current->left;
                newNode->right = current;
                current->left = newNode;
                current->leftThread = 1;
                break;
            } else {
                current = current->left;
            }
        } else {
            if (current->rightThread == 0) {
                newNode->right = current->right;
                newNode->left = current;
                current->right = newNode;
                current->rightThread = 1;
                break;
            } else {
                current = current->right;
            }
        }
    }
}

void inorderTraversal(struct Node* root) {
    struct Node* current = root;
    while (current->leftThread == 1) {
        current = current->left;
    }
    while (current != NULL) {
        printf("%d ", current->data);
        if (current->rightThread == 1) {
            current = current->right;
            while (current->leftThread == 1) {
                current = current->left;
            }
        } else {
            current = current->right;
        }
    }
}


void postorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct Node* current = root;
    struct Node* prev = NULL;

    while (current != NULL) {
        if (current->leftThread == 1) {
            current = current->left;
        } else if (current->rightThread == 1) {
            current = current->right;
        } else {
            printf("%d ", current->data);
            prev = current;
            current = current->right;

            while (current != NULL && current->right != prev) {
                printf("%d ", current->data);
                prev = current;
                current = current->right;
            }
        }
    }
}

int main() {
    struct Node* root = NULL;
    int choice, data;

    do {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(&root, data);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
