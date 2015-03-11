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
3Sum

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
TAG: ARRAY, TWO POINTERS
解题：本题不能使用哈希，以为可能有很多重复元素，先要对数组进行排序，首先想到的方法是三重循环遍历，但是显然超时；然后考虑两重循环+二分法寻找第三个元素，依然超时；最后看到了TAG里面的Two pointers，
参考了网上的答案，two pointers的意思就是用左右两个指针同时向中间移动，寻找目标元素，本题中外层循环作为第一个变量V1，然后两个指针从余下范围同时向中间移动，寻找和为 -V1的元素组合，
但是不加其他条件的话依然是超时，最后加上了跳过重复元素的条件，AC。详见代码注释.

收获：通常O(N^3)和O(N^2)都超时的情况下，考虑对数组问题，可以考虑two pointers方法
      还学到了C++11的一个新的特性，move表达式可以对容器进行去重操作，本题可以在返回时这样调用：return move(final);这样中间过程就不用在乎有重复res加入到final中了.

*/

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > final;
        vector<int> res;
        int len = num.size();
        sort(num.begin(), num.end());
        int v1, v2, v3;
        for(int i=0; i<len; ++i){
            v1 = num[i];
            int target = -v1;
            int left = i+1;
            int right = len-1;
            if(i>0 && v1==num[i-1])     //解决超时问题必要-1, v1跳过重复元素
                continue;
            while(left<right){

                v2 = num[left];
                v3 = num[right];
                int sum = v2+v3;
                if(right<len-1 && v3==num[right+1]){    //解决超时问题必要-2，V3跳过重复元素，但是注意V2不能跳过，因为V2与V1重复没关系
                    right--;
                }
                else if(sum == target){
                    res.clear();
                    res.push_back(v1);
                    res.push_back(v2);
                    res.push_back(v3);
                    // cout<<v1<<", "<<v2<<", "<<v3<<endl;
                    if(find(final.begin(), final.end(), res)==final.end())      //去掉重复结果,这步也可以不加，因为我们在V1和V3处均跳过了重复元素，所以现在res不可能有重复
                        final.push_back(res);
                    left++;
                    right--;
                }
                else if(sum < target)
                    left++;
                else
                    right--;
            }
        }
        return final;   //或者return move(final); 这样是为了节省内存，move表示对于a=b,如果b是一个右值，那么直接让a指向b的数据，然后销毁b,函数返回值其实对于调用者来说是右值,这个返回值实参调用完就没用了
    }


};


int main(){
	Solution sol;
    vector<int> args;
    args.push_back(0);
    args.push_back(0);
    args.push_back(0);
    vector<int> na = move(args);    //没有去重效果的！
    cout<<na.size()<<endl;

    return 0;
}