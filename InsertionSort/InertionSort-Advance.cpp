#include <bits/stdc++.h>

using namespace std;

class InsertionSortAdvance {
public:
    template<typename T>
    void insertSort(vector<T> &arr) {
        int n = arr.size();

        for (int i = 1; i < n; ++i) {
            T curVal = arr[i]; //记录当前考虑的元素的值
            int j;
            for (j = i; j > 0 && arr[j - 1] > curVal; --j) {
                arr[j] = arr[j - 1];
            }
            arr[j] = curVal;
        }
    }
};

//int main() {
//    vector<int> arr{4, 6, 3, 2, 1};
//    InsertionSortAdvance().insertSort(arr);
//    for (int n : arr) {
//        cout << n;
//    }
//    return 0;
//}
