#include <bits/stdc++.h>

using namespace std;

class MergeSort {

public:
    template<typename T>
    void merge(vector<T> &arr, int l, int mid, int r) {
        vector<T> aux(r - l + 1);

        int index = 0, i = l, j = mid + 1;
        while (i <= mid && j <= r){
            if (arr[i] < arr[j])
                aux[index++] = arr[i++];
            else
                aux[index++] = arr[j++];
        }

        while (i <= mid)
            aux[index++] = arr[i++];
        while (j <= r)
            aux[index++] = arr[j++];

        //复制回去
        for (int k = l; k <= r; ++k) {
            arr[k] = aux[k - l];
        }
    }

    template<typename T>
    void mergeSort(vector<T> &arr, int l, int r) {
        if (l >= r)
            return;

        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        if (arr[mid] > arr[mid + 1])
            merge(arr, l, mid, r);
    }
};

int main() {
    vector<int> arr{4, 6, 3, 2, 8, 1, 3, 6, 5, 1};
    MergeSort().mergeSort(arr, 0 , arr.size() - 1);
    for (int n : arr) {
        cout << n;
    }
    return 0;
}
