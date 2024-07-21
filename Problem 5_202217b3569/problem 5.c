#include<stdio.h>
#include<stdlib.h>  // For exit() function

#define MAX_SIZE 5

void insert(int queue[], int *rear, int *item);
void delete(int queue[], int *front, int *rear);
void display(int queue[], int front, int rear);

int main() {
    int queue[MAX_SIZE];
    int front = 0, rear = 0;
    int choice, item;

    printf("Queue using Array\n");
    printf("1. Insertion\n");
    printf("2. Deletion\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    do {
        printf("\nEnter your Choice:");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if (rear == MAX_SIZE)
                    printf("Queue is Full\n");
                else {
                    printf("Enter element to insert:");
                    scanf("%d", &item);
                    insert(queue, &rear, &item);
                }
                break;

            case 2:
                if (front == rear)
                    printf("Queue is Empty\n");
                else
                    delete(queue, &front, &rear);
                break;

            case 3:
                display(queue, front, rear);
                break;

            case 4:
                printf("Exiting from program\n");
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    } while(choice != 4);

    return 0;
}

// Function to insert element into the queue
void insert(int queue[], int *rear, int *item) {
    queue[*rear] = *item;
    (*rear)++;
}

// Function to delete element from the queue
void delete(int queue[], int *front, int *rear) {
    printf("Deleted Element is %d\n", queue[*front]);
    (*front)++;
}

// Function to display elements of the queue
void display(int queue[], int front, int rear) {
    int i;
    if (front == rear)
        printf("Queue is Empty\n");
    else {
        printf("Queue Elements are:\n");
        for (i = front; i < rear; i++) {
            printf("%d\n", queue[i]);
        }
    }
}
