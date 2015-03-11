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
Spiral Matrix

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

思路：首先考虑特殊情况，即m/n为0，为1这两种情况；接下来考虑n==2，即只有两列的(不必单独处理，只需在循环终止条件里加上判断);
      对于多行多列的情况，遍历的规律是，先走一行，然后走右侧的列，然后逆向走下面的行，然后走左侧的列，这样就走了一圈，即考虑一圈的四条边，并且要注意每条边要走的元素个数;
      其实遍历这四条边时就用四个for循环每次add一个元素到result里即可；
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        std::vector<int> v;
        int m = matrix.size();
        if(m==0)
            return res;
        int n = matrix[0].size();
        if(m==0)
            return res;
        if(m==1){
            v = matrix[0];
            res.insert(res.end(), v.begin(), v.end());
            return res;
        }
        if(n==1){
            for(int i=0; i<m; ++i){
                res.push_back(matrix[i][0]);
            }
            return res;
        }
        for(int ri=0; ri<(m+1)/2 && (n-2*ri)>0; ++ri){  //注意(n-2*ri)>0 这个条件是针对有多行但只有两列的情况的，因为每次走一圈时行中元素要减少2个
            v = matrix[ri];
            for(int i=0; i<ri; ++i){
                v.erase(v.begin());
                v.erase(v.end()-1);
            }
            res.insert(res.end(), v.begin(), v.end());
            for(int ci=ri+1; ci<m-1-ri; ++ci){
                res.push_back(matrix[ci][n-1-ri]);
            }
            if(m-1-ri==ri)
                continue;
            v = matrix[m-1-ri];
            for(int i=0; i<ri; ++i){
                v.erase(v.begin());
                v.erase(v.end()-1);
            }
            res.insert(res.end(), v.rbegin(), v.rend());
            for(int ci=m-2-ri; ci>ri; --ci){
                res.push_back(matrix[ci][ri]);
            }

        }
        return res;
    }
};

void print(std::vector<int> v){
    for(int i=0; i<v.size(); ++i){
        cout<<v[i]<<", ";
    }
    cout<<endl;
}

int main(){
	Solution sol;
    vector<vector<int> > arg;
    vector<int> args;
    args.push_back(1);
    args.push_back(11);
    arg.push_back(args);
    args.clear();
    args.push_back(2);
    args.push_back(12);
    arg.push_back(args);
    args.clear();
    args.push_back(3);
    args.push_back(13);
    arg.push_back(args);
    args.clear();
    args.push_back(4);
    args.push_back(14);
    arg.push_back(args);
    args.clear();
    args.push_back(5);
    args.push_back(15);
    arg.push_back(args);

    // cout<<arg[2][2]<<endl;
    vector<int> res = sol.spiralOrder(arg);
    cout<<"\nresult is :"<<res.size()<<endl;
        print(res);
    return 0;
}