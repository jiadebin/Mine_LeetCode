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
Majority Element

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Hide Tags: Divide and Conquer, Array, Bit Manipulation

*/

class Solution {
public:
    int majorityElement(vector<int> &num) {
        int max_times = 1, res;
        int len = num.size();
        int times = len/2;
        unordered_map<int, int> mp;
        for(int i=0; i<len; ++i){
            if(mp.count(num[i])==0){
                mp.insert(pair<int, int>(num[i], 1));
            }
            else{
                mp[num[i]]++;
            }
            if(mp[num[i]>times])
                return num[i];
            if(mp[num[i]]>=max_times){
                res = num[i];
                max_times = mp[num[i]];
            }
        }
        return res;
    }
    int majorityElement_2(vector<int> &num) {
        int len = num.size();
        int times = len/2;
        unordered_map<int, int> mp;
        for(int i=0; i<len; ++i){
            if(mp.count(num[i])==0){
                mp.insert(pair<int, int>(num[i], 1));
            }
            else{
                mp[num[i]]++;
            }
            if(mp[num[i]]>times)
                return num[i];
        }
    }

    //下面是论坛里较快的方法(O(N) time, O(1) space)，用一个count对各个元素进行计数，因为count[majority] > count[others],所以即使遇到不同元素时count减一了，那么最后count也会大于0，因为majority元素的count大于n/2,
    //极端case：2 2 2 1 3，那么2的count为3，后面遇到1，3时count变为1，依然大于0，majority为2(只有count为0时，才对majority赋新值)
    int majorityElement_3(vector<int> &num) {
    int maj;
    int count = 0;
    int n = int(num.size());
    for (int i = 0; i < n; i++){
        if (count == 0){
            maj = num[i];
            count++;
        }
        else if (num[i] == maj){
            count++;
            if (count > n/2) return maj;
        }
        else count--;
    }
    return maj;
}
};


int main(){
	Solution sol;
    vector<int> args;
    args.push_back(2);
    args.push_back(2);
    args.push_back(1);
    args.push_back(4);
    args.push_back(5);
    cout<<"\nresult is :"<<sol.majorityElement(args)<<endl;

    return 0;
}