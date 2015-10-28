#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <cstring>
#include <climits>
#include <cmath>
#include <cstring>

using namespace std;

/*

Longest Substring Without Repeating Characters
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int map[256];   //记录每个char的出现位置
        fill(map, map+256, -1);     //初始化为-1
        int res = 0, size = s.size(), start = 0;    //start记录最长子串开始位置
        for(int i=0; i<size; ++i){
            if(map[s[i]]>=start){   //如果当前start开始的子串中已经有了s[i]字符，则修改start到其下一个位置
                start = map[s[i]]+1;
            }
            map[s[i]] = i;
            res = max(i-start+1, res);  //更新长度
        }
        return res;

    }
};

int main(){

string s="aa";
string ss="xxx";
vector<string> strs;
strs.push_back(s);
strs.push_back(ss);
for(auto &t:strs){
    t="ddd";
}
// sort(str.begin(), str.end());
cout<<strs[1]<<endl;


	  Solution sol;
      cout<<sol.lengthOfLongestSubstring(s)<<endl;

    vector<int> args;
    args.push_back(2);
    args.push_back(2);
    args.push_back(2);
    args.push_back(5);
    args.push_back(5);
    args.push_back(6);
    args.push_back(6);
    args.push_back(6);

    unordered_map<int, bool> mp;
    for(auto i:args){
        mp[i] = false;
    }
    for(auto i:mp){
        // cout<<i.first<<", "<<i.second<<endl;
    }
    // args.push_back(Interval(6,9));
    // args.push_back(0);
    // args.push_back(0);

    // int res = sol.removeDuplicates(args);
    int A[] = {1};
    // int res = sol.search(A, 1, 0);
    // cout<<res<<endl;

    // args = sol.insert(args, Interval(0, 1));
    // for(auto t:args)
        // cout<<t.start<<","<<t.end<<" | ";
    // cout<<endl;
    // cout<<sol.countSort(args)<<endl;
    return 0;
}