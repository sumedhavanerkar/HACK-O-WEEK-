#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

// Check full
int isFull() {
    return (front == (rear + 1) % SIZE);
}

// Check empty
int isEmpty() {
    return (front == -1);
}

// Enqueue
void enqueue(int id) {
    if (isFull()) {
        printf("\n QUEUE FULL! Please wait...\n");
        return;
    }

    if (isEmpty())
        front = rear = 0;
    else
        rear = (rear + 1) % SIZE;

    queue[rear] = id;
    printf("\n Customer %d added successfully!\n", id);
}

// Dequeue
void dequeue() {
    if (isEmpty()) {
        printf("\n QUEUE EMPTY! No customers.\n");
        return;
    }

    printf("\n Serving Customer: %d\n", queue[front]);

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
}

// Display
void display() {
    if (isEmpty()) {
        printf("\n Queue is empty.\n");
        return;
    }

    printf("\n Current Queue Status:\n");
    printf("-------------------------------------------------\n");
    printf("| Position | Customer ID |\n");
    printf("-------------------------------------------------\n");

    int i = front, pos = 1;

    while (1) {
        printf("|   %3d    |     %3d     |\n", pos++, queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }

    printf("-------------------------------------------------\n");
}

// Main
int main() {
    int choice, id;

    printf("========================================\n");
    printf("    BANK CUSTOMER QUEUE SYSTEM\n");
    printf("   (Circular Queue Implementation)\n");
    printf("========================================\n");

    while (1) {
        printf("\n MENU:\n");
        printf("1. Add Customer\n");
        printf("2. Serve Customer\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");

        printf("\n Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Customer ID: ");
                scanf("%d", &id);
                enqueue(id);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\n Thank you! Bank closed.\n");
                return 0;

            default:
                printf("\n Invalid choice!\n");
        }
    }
}