#include "Sort.h"

int main() {
 int n, start, end, choice;

 while (true) {
  cout << "Enter 1 to start, 2 to exit program\n";
  cin >> choice;

  switch (choice) {
   case 1:{
    cout << "Enter number of elements\n";
    cin >> n;
    cout << endl;

    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
     cout << "Enter element " << i << "\n";
     cin >> arr[i];
    }
    cout << endl;

    cout << "Enter the start index: ";
    cin >> start;
    cout << "Enter the end index: ";
    cin >> end;
    cout << endl;

    MergeSort(arr, start, end);
    Show(arr, start, end);
    break;
   }
   case 2: {
    return 0;
   }
  }
}
}