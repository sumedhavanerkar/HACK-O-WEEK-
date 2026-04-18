#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
struct Node {
    char name[50];
    struct Node *left, *right;
};

// Create new folder
struct Node* createNode(char name[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert folder (user decides position)
struct Node* insert(struct Node* root, char name[]) {
    if (root == NULL)
        return createNode(name);

    int choice;
    printf("\nWhere to insert '%s' under '%s'?\n", name, root->name);
    printf("1. Left Subfolder\n2. Right Subfolder\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
        root->left = insert(root->left, name);
    else
        root->right = insert(root->right, name);

    return root;
}

// Preorder
void preorder(struct Node* root) {
    if (root != NULL) {
        printf(" %s  ", root->name);
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf(" %s  ", root->name);
        inorder(root->right);
    }
}

// Postorder
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf(" %s  ", root->name);
    }
}

// Main
int main() {
    struct Node* root = NULL;
    int choice;
    char name[50];

    printf("=====================================\n");
    printf("    FILE SYSTEM DIRECTORY TREE\n");
    printf("=====================================\n");

    while (1) {
        printf("\n MENU\n");
        printf("1. Create Root Folder\n");
        printf("2. Insert Subfolder\n");
        printf("3. Show Preorder\n");
        printf("4. Show Inorder\n");
        printf("5. Show Postorder\n");
        printf("6. Exit\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                if (root != NULL) {
                    printf("⚠ Root already exists!\n");
                    break;
                }
                printf("Enter root folder name: ");
                scanf("%s", name);
                root = createNode(name);
                printf("Root '%s' created.\n", name);
                break;

            case 2:
                if (root == NULL) {
                    printf("⚠ Create root first!\n");
                    break;
                }
                printf("Enter subfolder name: ");
                scanf("%s", name);
                insert(root, name);
                break;

            case 3:
                printf("\n Preorder (Root → Left → Right):\n");
                preorder(root);
                printf("\n");
                break;

            case 4:
                printf("\n Inorder (Left → Root → Right):\n");
                inorder(root);
                printf("\n");
                break;

            case 5:
                printf("\n Postorder (Left → Right → Root):\n");
                postorder(root);
                printf("\n");
                break;

            case 6:
                printf("\n Program Ended.\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}