#include <stdio.h>

#define MAX 100
#define MAX_SCORE 100   // assuming scores are between 0–100

int scores[MAX];
int freq[MAX_SCORE + 1] = {0};
int n = 0;

// Add score
void addScore(int score) {
    if (n >= MAX) {
        printf("\n Score list is full!\n");
        return;
    }

    scores[n++] = score;
    freq[score]++;

    printf("\n Score %d added successfully.\n", score);
}

// Display scores
void display() {
    if (n == 0) {
        printf("\n No scores available.\n");
        return;
    }

    printf("\n Scores:\n");
    printf("----------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", scores[i]);
    }
    printf("\n----------------------\n");
}

// Find Min
void findMin() {
    if (n == 0) return;

    int min = scores[0];
    for (int i = 1; i < n; i++) {
        if (scores[i] < min)
            min = scores[i];
    }

    printf("\n Minimum Score: %d\n", min);
}

// Find Max
void findMax() {
    if (n == 0) return;

    int max = scores[0];
    for (int i = 1; i < n; i++) {
        if (scores[i] > max)
            max = scores[i];
    }

    printf("\n Maximum Score: %d\n", max);
}

// Find Mode
void findMode() {
    int mode = 0, maxFreq = 0;

    for (int i = 0; i <= MAX_SCORE; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            mode = i;
        }
    }

    if (maxFreq == 0) {
        printf("\n No scores to calculate mode.\n");
    } else {
        printf("\n Mode Score: %d (Frequency: %d)\n", mode, maxFreq);
    }
}

// Main
int main() {
    int choice, score;

    printf("=====================================\n");
    printf("      EXAM SCORE TRACKER\n");
    printf("=====================================\n");

    while (1) {
        printf("\n MENU:\n");
        printf("1. Add Score\n");
        printf("2. Display Scores\n");
        printf("3. Find Minimum\n");
        printf("4. Find Maximum\n");
        printf("5. Find Mode\n");
        printf("6. Exit\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter score (0-100): ");
                scanf("%d", &score);

                if (score < 0 || score > 100) {
                    printf(" Invalid score!\n");
                } else {
                    addScore(score);
                }
                break;

            case 2:
                display();
                break;

            case 3:
                findMin();
                break;

            case 4:
                findMax();
                break;

            case 5:
                findMode();
                break;

            case 6:
                printf("\n Exiting...\n");
                return 0;

            default:
                printf("\n Invalid choice!\n");
        }
    }
}