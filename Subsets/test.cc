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
Subsets

Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

Solution: 求子集问题，每个递归层次只考虑当前这一个元素
*/

class Solution {
public:
    vector<vector<int> > res;
    vector<vector<int> > subsets(vector<int> &S) {
        vector<int> cres;
        sort(S.begin(), S.end());   //要sort,因为题目要求一个结果内必须有序
        bt(cres, S, S.size(), 0);
        return res;
    }
    void bt(vector<int> &cres, vector<int> &S, size_t n, size_t no){
        if(no == n){
            res.push_back(cres);
            cout<<cres.size()<<", ";
            return;
        }
        // for(size_t i=no; i<n; ++i){      //注意不需要再循环了，因为当前一个深度上只需要考虑当前这一个元素的有无，后续元素会在下一层递归中考虑
            cres.push_back(S[no]);
            bt(cres, S, n, no+1);
            cres.pop_back();
            bt(cres, S, n, no+1);
        // }
    }
};

int main(){
	Solution sol;
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    cout<<sol.subsets(num).size()<<endl;

    return 0;
}