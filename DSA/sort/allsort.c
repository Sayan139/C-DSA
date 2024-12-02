#include <stdio.h>
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i]; 
        int j = i - 1;
        while (j >= 0 && arr[j] > key) { // Shift elements greater than key
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // Place the key in the correct position
    }
}
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) { // Find the minimum element
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp; // Swap the found minimum element
    }
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp; // Swap elements
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1; // Return the pivot index
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partition the array
        quickSort(arr, low, pi - 1); // Sort elements before partition
        quickSort(arr, pi + 1, high); // Sort elements after partition
    }
}
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i]; // Copy data to temp arrays
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) { // Merge the temp arrays back
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++]; // Copy remaining elements of L[]
    while (j < n2) arr[k++] = R[j++]; // Copy remaining elements of R[]
}
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid); // Sort the first half
        mergeSort(arr, mid + 1, right); // Sort the second half
        merge(arr, left, mid, right); // Merge the sorted halves
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}
int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    printf("Sorted array (Insertion Sort): ");
    printArray(arr, n);

    return 0;
}
