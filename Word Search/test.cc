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
Word Search

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

Solution:注意得是找到连续的序列与word相同，而且不能重复使用同一个字符，所以要用一个二维数组记录走过的路径。本地测试程序卡死，线上AC了。
*/

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        bool res = false;
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool> > flag(rows, vector<bool>(cols, false));
        int cur = 0;
        for(int i=0; i<rows; ++i){
            for(int j=0; j<cols; ++j){
                if(board[i][j] == word[0]){
                    flag[i][j] = true;
                    // cout<<i<<"+"<<j<<endl;
                    bt(board, word, flag, res, i, j, 1);
                    if(res)  return true;
                    flag[i][j] = false;
                }
            }
        }
        return res;
    }
    void bt(const vector<vector<char> > &board, const string &word, vector<vector<bool> > &flag, bool &res, int r, int c,  int cur){
        if(cur == word.size()){
            res = true;
            return;
        }
        char ch = word[cur];
        if(r-1>=0 && board[r-1][c] == ch && flag[r-1][c]==false){
            flag[r-1][c] = true;
            bt(board, word, flag, res, r-1, c, cur+1);
            flag[r-1][c] = false;
            if(res)  return;
        }
        if(c-1>=0 && board[r][c-1] == ch && flag[r][c-1]==false){
            flag[r][c-1] = true;
            bt(board, word, flag, res, r, c-1, cur+1);
            flag[r][c-1] = false;
            if(res)  return;
        }
        if(c+1<board[0].size() && board[r][c+1] == ch && flag[r][c+1]==false){
            flag[r][c+1] = true;
            bt(board, word, flag, res, r, c+1, cur+1);
            flag[r][c+1] = false;
            if(res)  return;
        }
        if(r+1<board.size() && board[r+1][c] == ch && flag[r+1][c]==false){
            flag[r+1][c] = true;
            bt(board, word, flag, res, r+1, c, cur+1);
            flag[r+1][c] = false;
            if(res)  return;
        }
        return;
    }
};

int main(){
	Solution sol;
    vector<vector<char> > arg;
    arg.push_back(vector<char>());
    arg.push_back(vector<char>());
    arg.push_back(vector<char>());
    arg.push_back(vector<char>());
    arg[0].push_back('A');
    arg[0].push_back('B');
    arg[0].push_back('C');
    arg[0].push_back('E');
    arg[1].push_back('S');
    arg[1].push_back('F');
    arg[1].push_back('C');
    arg[1].push_back('S');
    arg[2].push_back('A');
    arg[2].push_back('D');
    arg[2].push_back('E');
    arg[2].push_back('E');

    string s = "EEE";
    cout<<sol.exist(arg, s)<<endl;

    return 0;
}