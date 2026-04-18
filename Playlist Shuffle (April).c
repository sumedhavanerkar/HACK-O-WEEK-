#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
struct Node {
    char song[50];
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

// Create new song node
struct Node* createNode(char name[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->song, name);
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Add at beginning
void addFront(char name[]) {
    struct Node* newNode = createNode(name);

    if (head != NULL) {
        head->prev = newNode;
        newNode->next = head;
    }

    head = newNode;
    printf("\n '%s' added at beginning.\n", name);
}

// Add at end
void addEnd(char name[]) {
    struct Node* newNode = createNode(name);

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("\n '%s' added at end.\n", name);
}

// Delete by position
void deletePos(int pos) {
    if (head == NULL) {
        printf("\n Playlist is empty!\n");
        return;
    }

    struct Node* temp = head;

    if (pos == 1) {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
        printf("\n Song '%s' deleted.\n", temp->song);
        free(temp);
        return;
    }

    for (int i = 1; temp != NULL && i < pos; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("\n Invalid position!\n");
        return;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    printf("\n Song '%s' deleted.\n", temp->song);
    free(temp);
}

// Reverse playlist (Shuffle mode)
void reverseList() {
    struct Node *temp = NULL, *current = head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
        head = temp->prev;

    printf("\n Playlist reversed (Shuffle Mode ON)\n");
}

// Display playlist
void display() {
    if (head == NULL) {
        printf("\n Playlist is empty.\n");
        return;
    }

    struct Node* temp = head;
    int pos = 1;

    printf("\n Current Playlist:\n");
    printf("-------------------------------------\n");
    printf("| Pos | Song Name                  |\n");
    printf("-------------------------------------\n");

    while (temp != NULL) {
        printf("| %3d | %-25s |\n", pos++, temp->song);
        temp = temp->next;
    }

    printf("-------------------------------------\n");
}

// Main
int main() {
    int choice, pos;
    char name[50];

    printf("=====================================\n");
    printf("      MUSIC PLAYLIST SYSTEM\n");
    printf("=====================================\n");

    while (1) {
        printf("\n MENU:\n");
        printf("1. Add Song (Front)\n");
        printf("2. Add Song (End)\n");
        printf("3. Delete Song (Position)\n");
        printf("4. Reverse Playlist (Shuffle)\n");
        printf("5. Display Playlist\n");
        printf("6. Exit\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter song name: ");
                scanf(" %[^\n]", name);
                addFront(name);
                break;

            case 2:
                printf("Enter song name: ");
                scanf(" %[^\n]", name);
                addEnd(name);
                break;

            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deletePos(pos);
                break;

            case 4:
                reverseList();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("\n Exiting Playlist.\n");
                return 0;

            default:
                printf("\n Invalid choice!\n");
        }
    }
}