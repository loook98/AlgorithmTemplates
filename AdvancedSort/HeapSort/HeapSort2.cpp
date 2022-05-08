#include <bits/stdc++.h>

using namespace std;

//<原地堆排序>
//注意：现在堆中节点的索引从0开始
//对于索引i， 父节点：(i-1)/2;
//          左孩子: i * 2 + 1;
//          右孩子：i * 2 + 2;
template<typename T>
class HeapSort2 {
public:
    void heapSort2(vector<T> &arr) {
        int n = arr.size();

        //先heapify,将arr转化为一个最大堆
        //第一个非叶子节点的索引为 「n-1」的父节点，即为 (n-1-1)/2;
        for (int i = (n - 1 - 1) / 2; i >= 0; --i) {
            shiftDown(arr, n - 1, i);
        }

        //然后每次取出当前堆顶元素放到最后面，堆的右范围减1
        for (int i = n - 1; i > 0; --i) {
            swap(arr[i], arr[0]);
            shiftDown(arr, i - 1, 0);
        }
    }

    //end为当前堆的右范围(包括arr[end])
    void shiftDown(vector<T> &arr, int end, int k) {
        while (k * 2 + 1 <= end) {
            int j = k * 2 + 1;
            if (j + 1 <= end && arr[j + 1] > arr[j])
                j = j + 1;

            if (arr[j] <= arr[k])
                break;
            swap(arr[k], arr[j]);
            k = j;
        }
    }
};

int main() {
    vector<int> arr{7,4, 6, 3, 2, 8, 3, 6, 5, 1};
    HeapSort2<int>().heapSort2(arr);
    for (int n: arr) {
        cout << n;
    }
    return 0;
}
