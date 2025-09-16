#include "Sort.h"
#include <algorithm>
#include <random>

int Partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);

    return i + 1;
}

int RandomizedPartition(int *arr, int low, int high) {
    static mt19937 rng(random_device{}());
    uniform_int_distribution<int> dist(low, high);

    int p = dist(rng);
    swap(arr[p], arr[high]);
    return  Partition(arr, low, high);
}


void QuickSort(int *arr, int low, int high) {
    if (low < high) {
        int q = RandomizedPartition(arr, low, high);
        QuickSort(arr, low, q - 1);
        QuickSort(arr, q + 1, high);
    }
}

void PrintArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        if (i) cout << ' ';
        cout << arr[i];
    }
    cout << endl;
}

int RandomizedSelect(int *arr, int low, int high, int pivot) {
    if (low == high) {
        if (pivot != 1) throw logic_error("pivot out of range");
        return arr[low];
    }

    int q = RandomizedPartition(arr, low, high);
    int k = q - low + 1;

    if (pivot == k) return arr[q];
    if (pivot < k) return RandomizedSelect(arr, low, q - 1, pivot);
    return RandomizedSelect(arr, q + 1, high, pivot - k);
}

int SelectOnCopy(const int* arr, int n, int ith) {
    int* tmp = new int[n];
    for (int i = 0; i < n; ++i) tmp[i] = arr[i];
    int res = RandomizedSelect(tmp, 0, n - 1, ith);
    delete[] tmp;
    return res;
}