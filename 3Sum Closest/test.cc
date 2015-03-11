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
3Sum Closest

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

解题：方法继承自3Sum，依然是tow pointers

收获：通常O(N^3)和O(N^2)都超时的情况下，考虑对数组问题，可以考虑two pointers方法
      还学到了C++11的一个新的特性，move表达式可以对容器进行去重操作，本题可以在返回时这样调用：return move(final);这样中间过程就不用在乎有重复res加入到final中了.
      注意move的效果：
      vector<int> a;
      ...push 几个元素到a中...
      vecotr<int> b=move(a);    //这时a已经为空了，全部转移给了b
*/

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int len = num.size();
        sort(num.begin(), num.end());
        int min_sub, res;
        for(int i=0; i<len-2; ++i){
            int a = num[i];
            int left = i+1;
            int right = len-1;
            while(left<right){
                // cout<<left<<"--"<<right<<endl;
                if(right<len-1 && num[right]==num[right+1]){
                    right--;
                    continue;
                }
                int b = num[left];
                int c = num[right];
                int cur_sub = a+b+c-target;
                //cout<<cur_sub<<",";
                if(i==0 && left==1 && right==len-1){
                    min_sub = cur_sub;
                    res = a+b+c;
                }
                else if(abs(min_sub) > abs(cur_sub)){
                    min_sub = cur_sub;
                    res = a+b+c;
                }
                if(cur_sub>0)
                    right--;
                else
                    left++;
            }
        }
        return res;
    }
};


int main(){
	Solution sol;
    vector<int> args;
    args.push_back(-1);
    args.push_back(2);
    args.push_back(1);
    args.push_back(-4);
    cout<<"\nresult is :"<<sol.threeSumClosest(args, 1)<<endl;

    return 0;
}