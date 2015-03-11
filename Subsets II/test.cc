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
Subsets II

Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

Solution: 本题由于数据可能有重复，所以同样先排序，考虑当前元素前面与之相等的元素是否被use了，如果没有，那么当前元素直接跳过(即一定不能加入结果)，反之则考虑当前元素加入/不加入两种情况
*/

class Solution {
public:
    vector<vector<int> > res;
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<int> cres;
        bt(cres, S, S.size(), 0);
        return res;
    }
    void bt(vector<int> &cres, vector<int> &S, size_t n, size_t no){
        if(no == n){
            res.push_back(cres);
            cout<<cres.size()<<", ";
            return;
        }
        // for(size_t i=no; i<n; ++i){
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
    num.push_back(2);
    cout<<sol.subsetsWithDup(num).size()<<endl;

    return 0;
}