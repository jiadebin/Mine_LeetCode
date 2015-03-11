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
Rotate Array:

Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]

Hint:
Could you do it in-place with O(1) extra space?
Related problem: Reverse Words in a String II


*/

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n=matrix.size();
        if(n<1)
            return;
        int circles=n/2;    //矩阵一共有几层环,每层自己进行rotate
        for(int i=0; i<circles; ++i){
            int max_row_col = n-1-i;
            int min_row_col = i;
            for(int j=i; j<n-1-i; ++j){     //  (i,j)         -----         (j, max)   注意这个点行号是j，不是row_col
                                                  |                             |
                int row_col = n-1-j;        //(row_col,min)   -----       (max, row_col)
                int tmp=matrix[i][j];
                matrix[i][j] = matrix[row_col][min_row_col];
                matrix[row_col][min_row_col] = matrix[max_row_col][row_col];
                matrix[max_row_col][row_col] = matrix[j][max_row_col];
                matrix[j][max_row_col] = tmp;
            }
        }
    }
    void rotate_clever_method(vector<vector<int> > &matrix) {   //先转置矩阵，然后每行元素左右两端互换位置,这是一个取巧的方法，不容易想
        int n=matrix.size();
        if(n<1)
            return;
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0; i<n; ++i){
            for(int j=0; j<n/2; ++j){
                swap(matrix[i][j], matrix[i][n-1-j]);
            }
        }
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
    int nums[5];
    for(int i=0; i<5; ++i){
        nums[i]=i+1;
    }
    // sol.rotate(nums, 5, 2);
    for(int i=0; i<5; ++i){
        cout<<nums[i]<<", ";
    }
    // cout<<"\nresult is :"<<res.size()<<endl;
    return 0;
}