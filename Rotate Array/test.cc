#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <cstring>
#include <climits>
#include <cmath>

using namespace std;

/*
Rotate Array:

Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]

Hint:
Could you do it in-place with O(1) extra space?
Related problem: Reverse Words in a String II

*/

class Solution {
public:
    void rotate_onn(int nums[], int n, int k) {     //方法1，O(n) space
        if(n<=1 || k<1)
            return;
        k%=n;   //in case of k>n, we should first reduce it by mod
        int nums_cp[n];
        memcpy(nums_cp, nums, n*sizeof(int));
        for(int i=n-1; i>=0; --i){
            int j=i-k;
            if(j<0)
                j+=n;
            nums[i]=nums_cp[j];
        }
    }

    void rotate(int nums[], int n, int k) {     //O(1) space, 使用reverse string的方法，三次reverse即可,先reverse整体，然后分别reverse两个段
        if(n<=1 || k<1)
            return;
        k%=n;   //in case of k>n, we should first reduce it by mod
        reverse_array(nums, 0, n-1);
        reverse_array(nums, 0, k-1);
        reverse_array(nums, k, n-1);

    }
    void reverse_array(int arr[], int left, int right){
        while(left<right){
            swap(arr[left++], arr[right--]);
        }
    }
};

void print(std::vector<int> v){
    for(int i=0; i<v.size(); ++i){
        cout<<v[i]<<", ";
    }
    cout<<endl;
}

int main(){
	Solution sol;
    vector<vector<int> > arg;
    vector<int> args;
    args.push_back(1);
    args.push_back(11);
    int nums[5];
    for(int i=0; i<5; ++i){
        nums[i]=i+1;
    }
    sol.rotate(nums, 5, 2);
    for(int i=0; i<5; ++i){
        cout<<nums[i]<<", ";
    }
    // cout<<"\nresult is :"<<res.size()<<endl;
    return 0;
}