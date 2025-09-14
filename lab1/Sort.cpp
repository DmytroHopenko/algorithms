#include "Sort.h"
#include <climits>


void Merge(int* arr, int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int* left = new int[n1 + 1];
    int* right = new int[n2 + 1];

    for (int i = 0; i < n1; i++) {
        left[i] = arr[start + i];
    }

    for (int j = 0; j < n2; j++) {
        right[j] = arr[mid + j + 1];
    }

    left[n1] = INT_MAX;
    right[n2] = INT_MAX;

    int i = 0, j = 0;

    for (int k = start; k <= end; k++) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i = i + 1;
        } else {
            arr[k] = right[j];
            j = j + 1;
        }
    }
}

void MergeSort(int* arr, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        MergeSort(arr, start, mid);
        MergeSort(arr, mid + 1, end);
        Merge(arr, start, mid, end);
    }
}

void Show(int* arr, int start, int end) {
    cout << "Sorted array: ";
    for (int i = start; i < end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}