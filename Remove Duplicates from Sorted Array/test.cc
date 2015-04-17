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
2.1.1 Remove Duplicates from Sorted Array
描述
Given a sorted array, remove the duplicates in place such that each element appear only once
and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
For example, Given input array A = [1,1,2],
Your function should return length = 2, and A is now [1,2].

分析：

*/



class Solution {
public:
    int removeDuplicates(vector<int> A) {
        int len = A.size();
        if(len<2)
            return len;
        int index = 0;
        for(int i=1; i<len; ++i) {
            if(A[i]!=A[index]) {
                A[++index] = A[i];
            }
        }
        return ++index;
    }
};


int main(){


	  Solution sol;

    vector<int> args;
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