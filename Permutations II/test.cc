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
Permutations II

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].

Solution: 本题由于数据可能有重复，所以需要更好的剪枝方法。可以对num进行排序，这样相等的值肯定相邻，我们可以判断，对于num[i]，如果在其之前有与它相等且未被use的值，那么我们也不use它，直接跳到i+1,
          即只有前面与其相等的值都被use了，我们才考虑它，这样就避免重复的结果了
*/

class Solution {
public:
    vector<vector<int> > res;
    vector<vector<int> > permuteUnique(vector<int> &num) {
        if(num.size()>0){
            sort(num.begin(), num.end());
            int n = num.size();
            vector<int> cres;
            vector<bool> use(num.size(), false);
            bt(cres, use, num, n);
        }
        return res;
    }
    void bt(vector<int> &cres, vector<bool> &use, vector<int> &num, int n){
        if(cres.size() == n){
            if(find(res.begin(), res.end(), cres) == res.end())
                res.push_back(cres);
            return;
        }
        for(int i=0; i<n; ++i){
            if(i>0 && num[i-1]==num[i] && use[i-1]==false){
                continue;
            }
            if(use[i] == false){
                cres.push_back(num[i]);
                use[i] = true;
                bt(cres, use, num, n);
                cres.pop_back();
                use[i] = false;
            }
        }
    }
};

int main(){
	Solution sol;
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(1);
    cout<<sol.permuteUnique(num).size()<<endl;

    return 0;
}