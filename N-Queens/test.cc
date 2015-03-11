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
N-Queens
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

Solution: 注意条件是不能有两个同行、同列、同斜线！同斜线的判断可以利用二者的行差与列差绝对值是否相等来判断。

注意：Output Limit Exceeded 并不是超时，而是说程序给出的结果过多（包括了所有正确的结果），这时要查看程序的逻辑错误。比如本题我遇到了这个错误，原因是没有去除同斜线的情况。

*/

class Solution {
public:
    vector<vector<string> > res;
    vector<int> tag;
    vector<vector<string> > solveNQueens(int n) {
        bt(n, 0);
        return res;
    }
    void bt(int n, int row){
        if(row==n){
            gather(n);
            return;
        }
        for(int i=0; i<n; ++i){
            if(isValid(row, i)){
                tag.push_back(i);
                bt(n, row+1);
                tag.pop_back();
            }
            else
                continue;
        }
        return;
    }
    void gather(int n){
        vector<string> ans(n, string(n, '.'));  //注意得加string关键字
        for(int i=0; i<n; ++i){
            ans[i][tag[i]]='Q';
        }
        res.push_back(ans);
    }
    bool isValid(int row, int col){
        if(!tag.empty() && find(tag.begin(), tag.end(), col)!=tag.end())
            return false;
        for(int i=0; i<row; ++i){
            if(abs(tag[i]-col) == (row-i))  //判断是否在同一斜线上
                return false;
        }
        return true;
    }
};

int main(){
	Solution sol;

    // cout<<strcmp(s3.c_str(), s4.c_str())<<endl;
    cout<<sol.solveNQueens(4).size()<<endl;
    // bool res = sol.isMatch_2(s1.c_str(), s2.c_str());
    // cout<<res<<endl;

    return 0;
}