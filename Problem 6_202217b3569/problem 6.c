#include<stdio.h>
#include<stdlib.h>  // For exit() function

#define MAX_SIZE 10

void main() {
    int n, a[MAX_SIZE], b[MAX_SIZE], t[MAX_SIZE], w[MAX_SIZE], g[MAX_SIZE];
    float att=0, awt=0;
    int i;

    //clrscr();
    printf("FCFS Scheduling using Queue ADT\n");

    printf("Enter the number of processes (max 10): ");
    scanf("%d", &n);

    if (n > MAX_SIZE || n <= 0) {
        printf("Invalid number of processes. Exiting...\n");
        exit(1);
    }

    printf("Enter burst times for each process:\n");
    for(i = 0; i < n; i++) {
        printf("P%d: ", i+1);
        scanf("%d", &b[i]);
    }

    printf("Enter arrival times for each process:\n");
    for(i = 0; i < n; i++) {
        printf("P%d: ", i+1);
        scanf("%d", &a[i]);
    }

    g[0] = 0; // First process starts at time 0

    // Calculate completion time, waiting time, and turnaround time
    for(i = 0; i < n; i++) {
        g[i+1] = g[i] + b[i];
        w[i] = g[i] - a[i];
        t[i] = g[i+1] - a[i];
        awt += w[i];
        att += t[i];
    }

    awt /= n; // Average waiting time
    att /= n; // Average turnaround time

    printf("\nProcess\t  Burst Time\t  Arrival Time\t  Waiting Time\t  Turnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, b[i], a[i], w[i], t[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", awt);
    printf("Average Turnaround Time: %.2f\n", att);

    //getch();
}
