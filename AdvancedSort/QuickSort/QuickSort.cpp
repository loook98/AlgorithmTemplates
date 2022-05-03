#include <bits/stdc++.h>

using namespace std;

class QuickSort{
public:
    void quickSort(vector<int>& nums, int l, int r){
        //☆错误点①：l >= r返回，而不是l==r;
        if (l >= r)
            return;

        int p = partition(nums, l, r);
        quickSort(nums, l, p - 1);
        quickSort(nums, p + 1, r);
    }

    //对nums[l...r]进行分割，找到第一个元素排序后所在的位置，并将该元素放到该位置，最后返回该位置。
    //并且此时元素左侧均为<它的元素，右侧均为>=它的元素。
    int partition(vector<int>& nums, int l, int r){
        //防止在数据几乎有序的情况下生成的递归树是不平衡的
        swap(nums[l], nums[rand()%(r-l+1) + l]);

        //☆错误点②： j初始化为l，而不是l+1;
        int j = l; // 区间(l...j]内的为< nums[l]的元素
        int i = l + 1; //用于遍历数组的索引。并且[j+1,i)之间的元素为>= nums[l]的元素

        while (i <= r){
            if (nums[i] < nums[l]){
                j++;
                swap(nums[j], nums[i]);
                i++;
            } else{
                i++;
            }
        }

        //遍历完数组之后，nums[l]正确的位置应是j.
        //故应交换l和j处元素
        swap(nums[l], nums[j]);
        return j;
    }
};

/*
int main(){
    vector<int> a{2,34,345,12,1,345,0,9};
    for (int x : a) {
        cout << x << " ";
    }
    cout <<endl;
    QuickSort().quickSort(a, 0, a.size()-1);
    for (int x : a) {
        cout << x << " ";
    }
    cout <<endl;
    return 0;
}*/
