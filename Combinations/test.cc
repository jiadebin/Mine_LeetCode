#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <cstring>
#include <climits>

using namespace std;

/*
Combinations
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

Solution: 这是backtracking类型的题，故用递归解决，首先就是考虑一个循环，每个解中是否包含当前元素：是或否，只有这两种。
          再用一个start值作为开始的边界，进行递归，每找到一个解，就加入结果集。
*/

class Solution {
public:
    vector<vector<int> > res;
    vector<vector<int> > combine(int n, int k) {
        vector<int> v;
        construct(n, k, 0, v);
        return res;
    }
    void construct(int n, int k, int start, vector<int> &v){
        if(v.size()==k){
            res.push_back(v);
            return;
        }
        for(int i=start+1; i<=n; ++i){
            v.push_back(i);     //包含i
            construct(n, k, i, v);
            v.pop_back();       //不包含i
        }
    }
};

int main(){
	Solution sol;
    string s1="c";
    string s2="*a*";
    string s3="";
    string s4="";
    // cout<<strcmp(s3.c_str(), s4.c_str())<<endl;
    cout<<sol.combine(1, 1).size()<<endl;
    // bool res = sol.isMatch_2(s1.c_str(), s2.c_str());
    // cout<<res<<endl;

    return 0;
}