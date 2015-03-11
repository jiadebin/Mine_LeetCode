#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <cstring>
#include <climits>
#include <cmath>

using namespace std;

/*
Two Sum

Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

TAG: Array, Hash Table

解题：用哈希表存储数组的每个元素，然后遍历数组，用和减去当前元素即为要寻找的第二个元素，直接用哈希表判断该元素是否存在，并取得它的index即可。
收获：本题标签有hash table，所以想尝试一下C++11的unordered_map，该容器时哈希表实现的，find传入的是key，find的时间是常量。


*/

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> mp;
        vector<int> res;
        int len = numbers.size();
        for(int i=0; i<len; ++i){
            mp.insert(pair<int, int>(numbers[i], i+1));
        }
        for(int i=1; i<=len; ++i){
            int v1 = numbers[i-1];
            int v2 = target - v1;
            auto it = mp.find(v2);
            if(it!=mp.end() && it->second!=i) {
                res.push_back(i<it->second?i:it->second);
                res.push_back(i<it->second?it->second:i);
                return res;
            }
        }
        return res;
    }
};

};

int main(){
	Solution sol;
    vector<int> args;
    args.push_back(2);
    args.push_back(7);
    args.push_back(11);
    args.push_back(15);

    cout<<sol.twoSum(args)<<endl;

    return 0;
}