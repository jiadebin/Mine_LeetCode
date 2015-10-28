class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        vector<bool> used(9, false);
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){     //处理行
                if(!check(board[i][j], used))
                    return false;
            }
            fill(used.begin(), used.end(), false);  //fill algorithm to reset used array to false
            for(int j=0; j<9; ++j){     //处理列
                if(!check(board[j][i], used))
                    return false;
            }
            fill(used.begin(), used.end(), false);
        }
        for(int k=0; k<9; ++k){     //处理9个正方形
            fill(used.begin(), used.end(), false);
            int row = k/3*3, col = k%3*3;       //每个3x3正方形行列的起始位置
            for(int i=row; i<row+3; ++i){
                for(int j=col; j<col+3; ++j){
                    if(!check(board[i][j], used))
                        return false;
                }
            }
        }
        return true;
    }

    bool check(char ch, vector<bool> &used){
        if(ch=='.')
            return true;
        if(used[ch-'1'])
            return false;
        used[ch-'1'] = true;
        return true;
    }
};