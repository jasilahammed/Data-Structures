#include<stdio.h>

int stack[100];  // Array to hold stack elements
int choice, n, top = -1, x, i;  // Global variables for stack operations

// Function prototypes
void push(void);
void pop(void);
void display(void);

int main() {
    //clrscr();  // Uncomment if using Turbo C++

    printf("\n Enter the size of STACK [MAX = 100]:");
    scanf("%d", &n);

    printf("\n\t STACK OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1. PUSH");
    printf("\n\t 2. POP");
    printf("\n\t 3. DISPLAY");
    printf("\n\t 4. EXIT");

    do {
        printf("\n Enter your Choice:");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\n\t EXIT POINT ");
                break;

            default:
                printf("\n\t Please Enter a Valid Choice (1/2/3/4)");
                break;
        }
    } while(choice != 4);

    return 0;
}

// Function to push elements into the stack
void push() {
    if (top >= n - 1) {
        printf("\n\t STACK is over flow");
    } else {
        printf(" Enter a value to be pushed:");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}

// Function to pop elements from the stack
void pop() {
    if (top <= -1) {
        printf("\n\t Stack is under flow");
    } else {
        printf("\n\t The popped element is %d", stack[top]);
        top--;
    }
}

// Function to display elements of the stack
void display() {
    if (top >= 0) {
        printf("\n The elements in STACK are:");
        for (i = top; i >= 0; i--) {
            printf("\n%d", stack[i]);
        }
    } else {
        printf("\n The STACK is empty");
    }
}
