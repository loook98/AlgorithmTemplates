#include <bits/stdc++.h>

using namespace std;

//堆中节点的索引从1开始
template<typename T>
class MaxHeap {
private:
    vector<int> data; //堆中的节点在数组中的索引从1开始
    int count;

    //将k位置的节点向上交换，直到整个堆是最大堆
    //向堆中插入元素时会使用这个函数
    void shiftUp(int k) {
        while (k > 1 && data[k / 2] < data[k]) {
            swap(data[k / 2], data[k]);
            k /= 2;
        }
    }

    //将k位置的元素向下交换，直到整个堆是最大堆
    //取堆顶元素时会用到这个函数
    void shiftDown(int k) {
        while (k * 2 < count) {
            int j = 2 * k;
            if (j + 1 <= count && data[j + 1] > data[j])
                j++;

            if (data[j] <= data[k])
                break;
            swap(data[k], data[j]);
            k = j;
        }
    }

public:
    MaxHeap() {
        data = vector<int>(100);
    }

    void insert(T v) {
        data[count + 1] = v;
        count++;

        shiftUp(count);
    }

    T popMax() {
        T ret = data[1];
        data[1] = data[count];
        count--;
        shiftDown(1);

        return ret;
    }

    T getMax(){
        assert(count > 0);
        return data[1];
    }
};

//需要借助一个最大堆来完成堆排序
//实现：依次将数组中的元素插入最大堆，构造出一个最大堆。然后再一次取出最大堆中的堆顶元素放入原数组中合适的位置
template<typename T>
class HeapSort1{
public:
    void heapSort1(vector<int> &arr){
        MaxHeap<T> heap;

        for (int & i : arr) {
            heap.insert(i);
        }

        for (int i = arr.size() - 1; i >= 0; --i) {
            arr[i] = heap.popMax();
        }
    }
};

int main() {
    vector<int> arr{4, 6, 3, 2, 8, 1, 3, 6, 5, 1};
    HeapSort1<int>().heapSort1(arr);
    for (int n : arr) {
        cout << n;
    }
    return 0;
}
