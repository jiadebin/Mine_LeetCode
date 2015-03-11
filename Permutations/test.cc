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
Permutations

Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

Solution: 求全排列，典型的回溯问题，剪枝条件就是已经添加的不再考虑
*/

class Solution {
public:
    vector<vector<int> > res;
    vector<vector<int> > permute(vector<int> &num) {
        if(num.size()>0){
            int n = num.size();
            vector<int> cres;
            vector<bool> use(num.size(), false);
            bt(cres, use, num, n);
        }
        return res;
    }
    void bt(vector<int> &cres, vector<bool> &use, vector<int> &num, int n){
        if(cres.size() == n)
            res.push_back(cres);
        else{
            for(int i=0; i<n; ++i){
                if(use[i] == false){
                    cres.push_back(num[i]);
                    use[i] = true;
                    bt(cres, use, num, n);
                    cres.pop_back();
                    use[i] = false;
                }
            }
        }
    }
};

int main(){
	Solution sol;
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    cout<<sol.permute(num).size()<<endl;

    return 0;
}