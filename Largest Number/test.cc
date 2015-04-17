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

using namespace std;

/*
Largest Number
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

思路：这是排序问题，排序原则是：两个元素第一个字符不同时，选大的；相同时，如3和30，这时3>30，因为330>303，即分别按两种次序组合，比较组合值

*/

class Solution {
public:
    string largestNumber(vector<int> &num) {
        string res = "";
        int len = num.size();
        vector<string> snum(len);
        stringstream ss;

        for(int i=0; i<len; ++i){   //转化成字符串数组
            ss.str("");
            ss.clear();
            ss<<num[i];
            ss>>snum[i];
        }

        sort(snum.begin(), snum.end(), mycmp);
        for(int i=0; i<len; ++i)
            res.append(snum[i]);
        while(res.size()>1 && res.at(0)=='0') {     //注意 00 的情况需要去重
            res.erase(res.begin());
        }
        return res;
    }

    static bool mycmp(string a, string b){
        string c = a+b;
        string d = b+a;
        return c>d;     //分别按不同顺序拼接，比谁大
    }

};

int main(){
	Solution sol;
    vector<int> args;
    // args.push_back(3);
    // args.push_back(30);
    // args.push_back(34);
    // args.push_back(5);
    // args.push_back(9);
    args.push_back(0);
    args.push_back(0);
// sol.largestNumber(args);
// cout<<mycmp("3", "30");
    cout<<sol.largestNumber(args)<<endl;
    return 0;
}