#include <stdio.h>

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) { // Loop through the array n-1 times
        for (int j = 0; j < n - i - 1; j++) { // Compare adjacent elements
            if (arr[j] > arr[j + 1]) { // Swap if out of order
                int temp = arr[j]; 
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    bubbleSort(arr, n); // Sort the array
    printf("Sorted array: \n");
    printArray(arr, n); // Print the sorted array

    return 0;
}
