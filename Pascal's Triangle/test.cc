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
Pascal's Triangle

Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        if(numRows>0){
            for(int i=1; i<=numRows; ++i){
                vector<int> vec(i, 1);
                if(i>2){
                    vector<int> pre=res[i-2];
                    for(int m=1; m<pre.size(); ++m){
                        vec[m]=pre[m-1]+pre[m];
                    }
                }
                res.push_back(vec);
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