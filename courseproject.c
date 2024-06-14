#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// AVL Tree Node

// AVL Tree Node
struct AVLNode {
    int dd;
    int mm;
    char events[100];
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
};

typedef struct AVLNode AVLNode;

// Function to get the height of a node
int height(AVLNode *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to create a new AVL node
AVLNode *newNode(int dd, int mm, const char *events) {
    AVLNode *node = (AVLNode *)malloc(sizeof(AVLNode));
    node->dd = dd;
    node->mm = mm;
    strcpy(node->events, events);
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // New node is initially at height 1
    return node;
}

// Function to perform a right rotation
AVLNode *rightRotate(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Function to perform a left rotation
AVLNode *leftRotate(AVLNode *x) {
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Function to get the balance factor of a node
int getBalance(AVLNode *node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Function to insert a node into the AVL tree
AVLNode *insert(AVLNode *node, int dd, int mm, const char *events) {
    // Perform standard BST insertion
    if (node == NULL)
        return newNode(dd, mm, events);

    if (dd < node->dd || (dd == node->dd && mm < node->mm))
        node->left = insert(node->left, dd, mm, events);
    else if (dd > node->dd || (dd == node->dd && mm > node->mm))
        node->right = insert(node->right, dd, mm, events);
    else // Duplicate dates are not allowed
        return node;

    // Update height of current node
    node->height = 1 + max(height(node->left), height(node->right));

    // Get the balance factor
    int balance = getBalance(node);

    // Left Heavy
    if (balance > 1) {
        if (dd < node->left->dd || (dd == node->left->dd && mm < node->left->mm))
            return rightRotate(node);
        if (dd > node->left->dd || (dd == node->left->dd && mm > node->left->mm)) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }

    // Right Heavy
    if (balance < -1) {
        if (dd > node->right->dd || (dd == node->right->dd && mm > node->right->mm))
            return leftRotate(node);
        if (dd < node->right->dd || (dd == node->right->dd && mm < node->right->mm)) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }

    return node;
}

// Function to find the node with the minimum value in a subtree
AVLNode *minValueNode(AVLNode *node) {
    AVLNode *current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// Function to delete a node from the AVL tree
AVLNode *deleteNode(AVLNode *root, int dd, int mm) {
    if (root == NULL)
        return root;

    if (dd < root->dd || (dd == root->dd && mm < root->mm))
        root->left = deleteNode(root->left, dd, mm);
    else if (dd > root->dd || (dd == root->dd && mm > root->mm))
        root->right = deleteNode(root->right, dd, mm);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            AVLNode *temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;

            free(temp);
        } else {
            AVLNode *temp = minValueNode(root->right);
            root->dd = temp->dd;
            root->mm = temp->mm;
            strcpy(root->events, temp->events);
            root->right = deleteNode(root->right, temp->dd, temp->mm);
        }
    }

    if (root == NULL)
        return root;

    // Update height of current node
    root->height = 1 + max(height(root->left), height(root->right));

    // Get the balance factor
    int balance = getBalance(root);

    // Left Heavy
    if (balance > 1) {
        if (getBalance(root->left) >= 0)
            return rightRotate(root);
        if (getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }

    // Right Heavy
    if (balance < -1) {
        if (getBalance(root->right) <= 0)
            return leftRotate(root);
        if (getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    return root;
}

// Function to search for events in the AVL tree
int searchEvent(AVLNode *root, int dd, int mm) {
    if (root == NULL) {
        // Return 0 if the tree is empty
        return 0;
    }

    if (dd < root->dd || (dd == root->dd && mm < root->mm)) {
        // Search in the left subtree
        return searchEvent(root->left, dd, mm);
    } else if (dd > root->dd || (dd == root->dd && mm > root->mm)) {
        // Search in the right subtree
        return searchEvent(root->right, dd, mm);
    } else {
        // Events found for the selected day
        printf("Events: %s\n", root->events);
        return 1; // Return 1 to indicate events are found
    }
}

// Function to print all events in the AVL tree
void printAllEvents(AVLNode *root) {
    if (root != NULL) {
        printAllEvents(root->left);
        printf("Date: %02d/%02d, Events: %s\n", root->dd, root->mm, root->events);
        printAllEvents(root->right);
    }
}

// Function to delete events on a specific date
AVLNode *deleteEventsOnDate(AVLNode *root, int dd, int mm) {
    root = deleteNode(root, dd, mm);
    return root;
}

// Function to read events from a CSV file
AVLNode *readEventsFromFile(AVLNode *root, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return root;
    }

    int dd, mm;
    char events[100];
    while (fscanf(file, "%d,%d,%99[^\n]", &dd, &mm, events) == 3) {
        root = insert(root, dd, mm, events);
    }

    fclose(file);
    return root;
}

// Function to write events to a CSV file
void writeEventsToFileHelper(AVLNode *root, FILE *file) {
    if (root != NULL) {
        writeEventsToFileHelper(root->left, file);
        fprintf(file, "%d,%d,%s\n", root->dd, root->mm, root->events);
        writeEventsToFileHelper(root->right, file);
    }
}

// Function to write events to a CSV file
void writeEventsToFile(AVLNode *root, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing: %s\n", filename);
        return;
    }

    writeEventsToFileHelper(root, file);

    fclose(file);
}

int main() {
    AVLNode *root = NULL;

    // Read events from the file on startup
    root = readEventsFromFile(root, "events.csv");

    char ch;
    int dd, mm;
    char buffer[100]; // Buffer to store the event name

    while (1) {
        printf("\n1. Add Event\n");
        printf("2. Print All Events\n");
        printf("3. Search Events\n");
        printf("4. Delete Events\n");
        printf("5. Save Events to File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &ch);

        switch (ch) {
            case '1':
                printf("Enter date (DD MM): ");
                scanf("%d %d", &dd, &mm);
                printf("Enter event name: ");
                getchar(); // Consume the newline character left in the buffer
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strlen(buffer) - 1] = '\0'; // Remove the newline character
                root = insert(root, dd, mm, buffer);
                break;
            case '2':
                printAllEvents(root);
                break;
            case '3':
                printf("Enter date (DD MM): ");
                scanf("%d %d", &dd, &mm);
                int eventsFound = searchEvent(root, dd, mm);
                if (eventsFound == 0) {
                    printf("No events found for the selected day.\n");
                }
                break;
            case '4':
                printf("Enter date (DD MM) to delete events: ");
                scanf("%d %d", &dd, &mm);
                root = deleteEventsOnDate(root, dd, mm);
                printf("Events on %02d/%02d deleted.\n", dd, mm);
                break;
            case '5':
                // Save events to the file
                writeEventsToFile(root, "events.csv");
                printf("Events saved to file.\n");
                break;
            case '6':
                // Save events to the file before exiting
                writeEventsToFile(root, "events.csv");
                exit(0);
        }
    }

    return 0;
}