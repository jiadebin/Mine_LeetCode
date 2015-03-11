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
Pascal's Triangle II

Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1, 1);
        if(rowIndex>1){
            vector<int> pre(2, 1);
            vector<int> cur(pre);
            for(int i=2; i<=rowIndex; ++i){
                cur.push_back(1);
                for(int j=1; j<i; ++j){
                    cur[j] = pre[j-1]+pre[j];
                }
                pre = cur;
                if(i==rowIndex)
                    res = cur;
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
    cout<<"\nresult is :"<<sol.getRow(3).size()<<endl;

    return 0;
}