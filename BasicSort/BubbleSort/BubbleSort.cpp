#include <bits/stdc++.h>

using namespace std;

//升序排序
//优化: 若某一层没有交换，则整个数组已经有序了
class BubbleSort {
public:
    template<typename T>
    void bubbleSort(vector<T> &arr) {
        int n = arr.size();

        //共冒泡n-1次
        for (int i = 0; i < n - 1; ++i) {
            bool isSwapped = false;
            for (int j = 0; j < (n - 1) - i; ++j) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    isSwapped = true;
                }
            }
            if (!isSwapped)
                break;
        }
    }
};

//int main() {
//    vector<int> arr{9, 6, 3, 2, 8};
//    BubbleSort().bubbleSort(arr);
//    for (int n : arr) {
//        cout << n;
//    }
//    return 0;
//}