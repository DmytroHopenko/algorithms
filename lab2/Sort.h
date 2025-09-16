#ifndef LAB2_SORT_H
#define LAB2_SORT_H

#include  <iostream>

using namespace std;

void QuickSort(int* arr, int low, int high);
int Partition(int* arr, int low, int high);
int RandomizedPartition(int* arr, int low, int high);
void PrintArray(int* arr, int size);

int RandomizedSelect(int* arr, int low, int high, int pivot);
int SelectOnCopy(const int* arr, int n, int ith);

#endif //LAB2_SORT_H