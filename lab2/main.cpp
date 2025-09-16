#include  "Sort.h"

int main() {
    int n, start, end, choice;

    while (true) {
        cout << "Enter 1 to start, 2 to get Ordinal statistics, 3 to exit program\n";
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

                if (start < 0) start = 0;
                if (end   < 0) end   = 0;
                if (start >= n) start = n - 1;
                if (end   >= n) end   = n - 1;
                if (start > end) swap(start, end);

                QuickSort(arr, start, end);
                PrintArray(arr, n);
                break;
            }
            case 2: {
                cout << "Enter number of elements\n";
                cin >> n;
                cout << endl;

                int *arr = new int[n];

                for (int i = 0; i < n; i++) {
                    cout << "Enter element " << i << "\n";
                    cin >> arr[i];
                }
                cout << endl;

                int ith;
                cout << "Enter i (1.." << n << ") for i-th order statistic: ";
                if (!(cin >> ith) || ith < 1 || ith > n) {
                    cerr << "i must be in [1," << n << "]\n\n";
                    delete[] arr;
                    break;
                }

                int ithVal = SelectOnCopy(arr, n, ith);
                int mn     = SelectOnCopy(arr, n, 1);
                int mx     = SelectOnCopy(arr, n, n);

                int k = (n + 1) / 2;
                int medLow  = SelectOnCopy(arr, n, k);
                int medHigh = (n % 2 == 1) ? medLow : SelectOnCopy(arr, n, k + 1);

                cout << "\nResults:\n";
                cout << "i-th order statistic (i=" << ith << "): " << ithVal << "\n";
                cout << "min: " << mn << "\n";
                cout << "max: " << mx << "\n";

                if (n % 2 == 1) {
                    cout << "median: " << medLow << " (index " << k << ")\n\n";
                } else {
                    cout << "median (lower, upper): " << medLow << ", " << medHigh
                         << " | average = " << ((medLow + medHigh) / 2.0) << "\n\n";
                }

                delete[] arr;
                break;
            }
            case 3: {
                return 0;
            }
        }
    }
}