#include <bits/stdc++.h>

using namespace std;

class QuickSort3Ways{
public:
    void quickSort3Ways(vector<int>& nums, int l, int r){
        //递归终止条件
        if (l >= r)
            return;

        //partition部分
        //处理数据基本有序情况递归树只有一侧的情况
        swap(nums[l], nums[rand()%(r-l+1)+l]);

        int lt = l;     // (l...lt]为< nums[l]的区间
        int gt = r + 1; // [gt...r]为> nums[l]的区间
        int i = l + 1;  // (lt...i)为= nums[l]的区间

        while (i < gt){
            if (nums[i] < nums[l]){
                lt++;
                swap(nums[lt], nums[i]);
                i++;
            } else if (nums[i] > nums[l]){
                gt--;
                swap(nums[gt], nums[i]);
            } else{// ==
                i++;
            }
        }
        swap(nums[l], nums[lt]);
        lt--;

        //快排的递归部分
        quickSort3Ways(nums, l, lt);
        quickSort3Ways(nums, gt, r);
    }
};


/*
int main(){
    vector<int> a{2,34,345,12,1,9,345,9,0,9,9};
    for (int x : a) {
        cout << x << " ";
    }
    cout <<endl;
    QuickSort3Ways().quickSort3Ways(a, 0, a.size()-1);
    for (int x : a) {
        cout << x << " ";
    }
    cout <<endl;
    return 0;
}*/
