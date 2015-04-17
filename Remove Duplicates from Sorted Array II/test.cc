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
2.1.2 Remove Duplicates from Sorted Array II
描述
Follow up for ”Remove Duplicates”: What if duplicates are allowed at most twice?
For example, Given sorted array A = [1,1,1,2,2,3],
Your function should return length = 5, and A is now [1,1,2,2,3]

分析：用一个变量count记录元素重复次数，用另一个变量记录应该覆盖的位置index，一旦count>2了就跳过，遇到新元素开始覆盖index位置。

*/



class Solution {
public:
    int removeDuplicates(vector<int> A) {
        int len = A.size();
        if(len<2)
            return len;
        int  count = 1, index = 1;
        for(int i=1; i<len; ++i) {
            if(A[i]!=A[i-1]) {
                count = 1;
                A[index++] = A[i];
            } else {
                count++;
                if(count==2)
                    A[index++] = A[i];
            }
        }
        return index;
    }
};


int main(){


	  Solution sol;

    vector<int> args;
    args.push_back(2);
    args.push_back(2);
    args.push_back(2);
    args.push_back(5);
    args.push_back(5);
    args.push_back(6);
    args.push_back(6);
    args.push_back(6);
    // args.push_back(Interval(6,9));
    // args.push_back(0);
    // args.push_back(0);

    int res = sol.removeDuplicates(args);
    cout<<res<<endl;

    // args = sol.insert(args, Interval(0, 1));
    // for(auto t:args)
        // cout<<t.start<<","<<t.end<<" | ";
    // cout<<endl;
    // cout<<sol.countSort(args)<<endl;
    return 0;
}