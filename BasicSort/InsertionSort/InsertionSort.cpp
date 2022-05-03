#include <bits/stdc++.h>

using namespace std;

class InsertionSort {
public:
    template<typename T>
    void insertionSort(T arr[], int n) {
        for (int i = 1; i < n; ++i) { //第一个元素已经完成插入，故i从1开始

            //第一种写法
//            //寻找arr[i]元素合适的插入位置
//            for (int j = i; j > 0; --j) {
//                if (arr[j - 1] > arr[j])
//                    swap(arr[j - 1], arr[j]);
//                else
//                    break;
//            }

            //第二种写法,简洁一点，思路不变
            for (int j = i; j > 0 && arr[j - 1] > arr[j]; --j) {
                swap(arr[j-1], arr[j]);
            }
        }
    }
};

//int main() {
//    int arr[5]{4,3,3,2,1};
//    InsertionSort().insertionSort(arr, 5);
//    for (int n : arr) {
//        cout << n;
//    }
//    return 0;
//}