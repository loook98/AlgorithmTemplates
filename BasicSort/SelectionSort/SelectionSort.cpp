#include <bits/stdc++.h>

using namespace std;

class SelectionSort {
public:
    template<typename T>
    void selectionSort(vector<T> &arr) {
        int n = arr.size();

        for (int i = 0; i < n; ++i) {
            int minIndex = i;
            for (int j = i + 1; j < n; ++j) {
                if (arr[j] < arr[minIndex])
                    minIndex = j;
            }
            swap(arr[i], arr[minIndex]);
        }
    }
};

//int main() {
//    vector<int> arr{4, 6, 3, 2, 99};
//    SelectionSort().selectionSort(arr);
//    for (int n : arr) {
//        cout << n;
//    }
//    return 0;
//}