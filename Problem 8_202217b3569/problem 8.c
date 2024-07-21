#include <stdio.h>

// Function to find the position of the smallest element in the array from index i to n
int smallest(int arr[], int i, int n) {
    int small = arr[i];
    int pos = i;
    for (int j = i + 1; j < n; j++) {
        if (small > arr[j]) {
            small = arr[j];
            pos = j;
        }
    }
    return pos;
}

// Function to implement selection sort
void selection_sort(int arr[], int n) {
    int i, pos;
    for (i = 0; i < n - 1; i++) {
        pos = smallest(arr, i, n);
        if (pos != i) {
            int temp = arr[i];
            arr[i] = arr[pos];
            arr[pos] = temp;
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    selection_sort(arr, n);
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
