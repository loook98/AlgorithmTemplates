#include <bits/stdc++.h>

using namespace std;

class ShellSort {
public:
    template<typename T>
    void shellSort(vector<T> &arr) {
        int n = arr.size();
        int h = n / 2;

        while (h >= 1) {
            //间距为h的各个分组的开始为start
            for (int start = 0; start < h; ++start) {
                //组内进行插入排序
                for (int i = start + h; i < n; i += h) {
                    T curVal = arr[i];
                    int j;
                    for (j = i; j > start && arr[j - h] > curVal; j -= h) {
                        arr[j] = arr[j - h];
                    }
                    arr[j] = curVal;
                }
            }
            h /= 2;
        }
    }
};

//int main() {
//    vector<int> arr{9, 6, 3, 2, 8, 1, 3, 6, 5};
//    ShellSort().shellSort(arr);
//    for (int n : arr) {
//        cout << n;
//    }
//    return 0;
//}
