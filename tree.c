#include <stdio.h>
#include <stdlib.h>


struct Node {
    int rollNo;
    char name[50];
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int rollNo, const char* name) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->rollNo = rollNo;
    snprintf(newNode->name, sizeof(newNode->name), "%s", name);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// a. Add a new student record into the tree
struct Node* insert(struct Node* root, int rollNo, const char* name) {
    if (root == NULL) {
        return createNode(rollNo, name);
    }
    if (rollNo < root->rollNo) {
        root->left = insert(root->left, rollNo, name);
    } else if (rollNo > root->rollNo) {
        root->right = insert(root->right, rollNo, name);
    } else {
        printf("Roll Number %d already exists!\n", rollNo);
    }
    return root;
}


struct Node* findMin(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}


struct Node* deleteNode(struct Node* root, int rollNo) {
    if (root == NULL) {
        return root;
    }

    if (rollNo < root->rollNo) {
        root->left = deleteNode(root->left, rollNo);
    } else if (rollNo > root->rollNo) {
        root->right = deleteNode(root->right, rollNo);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct Node* temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->rollNo = temp->rollNo;
        snprintf(root->name, sizeof(root->name), "%s", temp->name);

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->rollNo);
    }
    return root;
}


struct Node* search(struct Node* root, int rollNo) {
    if (root == NULL || root->rollNo == rollNo) {
        return root;
    }
    if (root->rollNo < rollNo) {
        return search(root->right, rollNo);
    }
    return search(root->left, rollNo);
}


void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("Roll No: %d | Name: %s\n", root->rollNo, root->name);
        inorder(root->right);
    }
}


void preorder(struct Node* root) {
    if (root != NULL) {
        printf("Roll No: %d | Name: %s\n", root->rollNo, root->name);
        preorder(root->left);
        preorder(root->right);
    }
}


void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("Roll No: %d | Name: %s\n", root->rollNo, root->name);
    }
}

// Main function with menu-driven interface
int main() {
    struct Node* root = NULL;
    int choice, rollNo;
    char name[50];

    while (1) {
        printf("\n--- Student BST Management System ---\n");
        printf("1. Add a new student record (Insert)\n");
        printf("2. Remove a student record (Delete)\n");
        printf("3. Search for a student record\n");
        printf("4. Display records (Inorder - Sorted)\n");
        printf("5. Display records (Preorder)\n");
        printf("6. Display records (Postorder)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter Roll Number: ");
                scanf("%d", &rollNo);
                printf("Enter Student Name: ");
                scanf("%s", name);
                root = insert(root, rollNo, name);
                break;
            case 2:
                printf("Enter Roll Number to remove: ");
                scanf("%d", &rollNo);
                root = deleteNode(root, rollNo);
                printf("Record removed (if it existed).\n");
                break;
            case 3:
                printf("Enter Roll Number to search: ");
                scanf("%d", &rollNo);
                {
                    struct Node* found = search(root, rollNo);
                    if (found != NULL) {
                        printf("Student Found -> Roll No: %d | Name: %s\n", found->rollNo, found->name);
                    } else {
                        printf("Student with Roll No %d not found.\n", rollNo);
                    }
                }
                break;
            case 4:
                printf("\n--- Inorder Traversal ---\n");
                inorder(root);
                break;
            case 5:
                printf("\n--- Preorder Traversal ---\n");
                preorder(root);
                break;
            case 6:
                printf("\n--- Postorder Traversal ---\n");
                postorder(root);
                break;
            case 7:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
