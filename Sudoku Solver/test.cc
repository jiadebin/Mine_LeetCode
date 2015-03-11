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
Sudoku Solver

数独问题，9x9方格，每行每列不能有重复数字，分成9个3x3正方形，其中用1~9填充
空格子用'.'字符填充，请对board进行填充

收获：递归函数没有返回值时，会遍历所有可能的路径，非常耗时，最终导致我的程序超时，对于这类只需找到一个解（或只有唯一解）的问题，加上bool返回值很好，如果找到第一个解了，直接返回true
后面也就不用再递归了

*/

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        vector<vector<bool> > cur_sqr(9, vector<bool>(9, false));
        vector<vector<bool> > row_tbl(9, vector<bool>(9, false));
        vector<vector<bool> > col_tbl(9, vector<bool>(9, false));
        int len=9;
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                char val = board[i][j];
                if(val != '.'){
                    row_tbl[i][val-'1'] = true;
                    col_tbl[val-'1'][j] = true;
                    cur_sqr[i/3*3+j/3][val-'1'] = true;
                }
            }
        }
        bt(board, cur_sqr, row_tbl, col_tbl);
    }

    //下面版本的bt函数运行超时，因为没有返回追，递归之后并不知道是否成功找到一个解，所以及时最后找到解了，返回到第一次调用处，还是会继续递归寻找解，所以超时了。故需改进加上bool返回值
    //如果找到了解，就直接返回true，见后面的版本
    void bt_TimeLimitExceed(vector<vector<char> > &board, vector<vector<bool> > &cur_sqr, vector<vector<bool> > &row_tbl, vector<vector<bool> > &col_tbl){
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                if(board[i][j] == '.'){
                    for(int k=0; k<9; k++){
                        if(!cur_sqr[i/3*3 + j/3][k] && !row_tbl[i][k] && !col_tbl[k][j]){
                            board[i][j] = '1'+k;
                            cur_sqr[i/3*3 + j/3][k] = true;
                            row_tbl[i][k] = true;
                            col_tbl[k][j] = true;
                            bt(board, cur_sqr, row_tbl, col_tbl);
                            board[i][j] = '.';
                            cur_sqr[i/3*3 + j/3][k] = false;
                            row_tbl[i][k] = false;
                            col_tbl[k][j] = false;
                        }
                    }
                }
            }
        }
    }

    //注意下面的bt函数添加了bool返回值，这样运行就不超时了，
    bool bt_AC(vector<vector<char> > &board, vector<vector<bool> > &cur_sqr, vector<vector<bool> > &row_tbl, vector<vector<bool> > &col_tbl){
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                if(board[i][j] == '.'){
                    for(int k=0; k<9; k++){
                        if(!cur_sqr[i/3*3 + j/3][k] && !row_tbl[i][k] && !col_tbl[k][j]){
                            board[i][j] = '1'+k;
                            cur_sqr[i/3*3 + j/3][k] = true;
                            row_tbl[i][k] = true;
                            col_tbl[k][j] = true;
                            if(bt(board, cur_sqr, row_tbl, col_tbl))    //如果下层调用找到解了，那么直接返回true，不再尝试其他值
                                return true;
                            board[i][j] = '.';
                            cur_sqr[i/3*3 + j/3][k] = false;
                            row_tbl[i][k] = false;
                            col_tbl[k][j] = false;
                        }
                    }
                    return false;
                }
            }
        }
        return true;    //所有格子都没有'.'了，填充成功
    }

    //下面是另外一种代码更简洁的递归实现,这样只是实现isValid函数麻烦一点，但是bt函数就相当简洁了,值得学习!!!!!!!
    bool bt_simple(vector<vector<char> > &board){
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                if(board[i][j] == '.'){
                    for(int k=0; k<9; k++){
                        board[i][j] = '1'+k;    //先填充上k
                        if(isValid(board, i, j) && bt_simple(board)){   //isValid函数中实验检查k的值在（i,j）格子里是否可行(验证行、列、当前九宫格)
                            return true;
                        }
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;    //所有格子都没有'.'了，填充成功
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
    // cout<<sol.exist(arg, s)<<endl;

    return 0;
}