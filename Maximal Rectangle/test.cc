#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cstring>
#include <climits>

using namespace std;

/*
Maximal Rectangle Total Accepted: 15144 Total Submissions: 70838 My Submissions Question Solution
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
Tags： Array Hash Table Stack Dynamic Programming

Solution:利用Largest Rectangle in Histogram那道题的直方法，计算矩形每一行上的每一列的高度，然后计算这些列产生的最大面积，依次计算第1、2、3.。。行，每一行最大值与当前最大值比较
时间复杂度：O(M*N)

如果是找全部由1组成的子正方形，那么可以使用DP，参考：http://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/
而本题是矩形，其实不好使用DP，可以参考：http://www.cnblogs.com/remlostime/archive/2012/11/12/2766566.html 使用DP求出每行中以当前元素1结尾的连续1的最大长度，遍历完之后，利用此信息在列上
找最大矩阵，即找以(i, j)为右下角的矩形最大的1的面积，但是需要三重循环了。例如：
0110
1110
0110
对应的DP信息矩阵为:
0120
1230
0120
接着求以(3,3)元素为右下角的最大矩阵，可以追溯至(1,3)这三行中第三列最小为2，故最大子矩阵面积为3*2=6；这就是本题利用DP的解法，即只能由DP得到行上面的最长边信息，求最大面积还得对这个信息进行组合，
且需要三重循环遍历，故时间复杂度为O(M*M*N)。不如使用第一种方法。

*/
class Solution {
public:
    int maximalRectagle(vector<vector<char> > &matrix) {
        if(matrix.size()==0)
            return 0;
        if(matrix[0].size()==0)
            return 0;
        int res = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> hvec(cols, 0);
        for(int i=0; i<rows; ++i){
            for(int j=0; j<cols; ++j){
                if(matrix[i][j]=='1')
                    hvec[j] += 1;
                else
                    hvec[j] = 0;
            }
            res = max(res, largestRectangleArea(hvec));
        }
        return res;
    }

    int largestRectangleArea(vector<int> &height) {
        int maxArea=0;
        int curArea;
        stack<int> s;
        int len = height.size();
        for(int i=0; i<len; ++i){
            if(s.empty() || height[i]>=height[s.top()])
                s.push(i);
            else{
                while(!s.empty() && height[s.top()] > height[i]){
                    int c = s.top();
                    s.pop();
                    curArea = height[c]*(s.empty()?i:(i-s.top()-1));
                    if(maxArea<curArea)
                        maxArea = curArea;
                }
                s.push(i);
            }
        }

        while(!s.empty()){
            int c = s.top();
            s.pop();
            curArea = height[c]*(s.empty()?len:(len-s.top()-1));    //注意此时右边界为总长度，因为当前元素是栈顶，表示右侧没有元素比它小了，否则它就不会是栈顶
            if(maxArea<curArea)
                maxArea = curArea;
        }
        return maxArea;
    }
};


int main(){
	Solution sol;
    vector<char> vv(4, '1');
    // cout<<vv.size()<<endl;
    vector<vector<char> >  v;
    v.push_back(vv);
    v.push_back(vv);
    v.push_back(vv);

    cout<<sol.maximalRectagle(v)<<endl;

    return 0;
}