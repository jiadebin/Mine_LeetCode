#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cstring>
#include <climits>

using namespace std;

/*
Edit Distance

Solution:利用DP思想，注意dp矩阵的长和宽都要多一个空间，用来存放空位，空位的作用是利用增添字符求得的编辑距离；
dp[i][j] = dp[i-1][j]+1；     由左侧同行上一列而来，表示增加/删除一个字符的转换
           dp[i][j-1]+1；     由上方上一行同列而来；表示删除/增加一个字符的转换
           dp[i-1][j-1]+cost; 由左上角而来，表示修改当前字符的转换
    0   a
0   0   1
a   1   0
b   2   1
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1=word1.size(), len2=word2.size();
        if(len1==0 || len2==0)
            return max(len1, len2);
        int dp[len1+1][len2+1];
        memset(dp, 0, len1*len2*sizeof(int));

        for(int i=0; i<=len1; ++i){
            dp[i][0] = i;   //第一列的处理就是直接递增
        }
        for(int i=0; i<=len2; ++i){
            dp[0][i] = i;   //第一行的处理也是直接递增
        }
        int cost = 0;
        for(int i=1; i<=len1; ++i){
            for(int j=1; j<=len2; ++j){
                if(word1[i-1]==word2[j-1])
                    cost = 0;
                else
                    cost = 1;
                dp[i][j] = min(min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i-1][j-1]+cost);     //在增加字符、删除字符、修改字符中选择代价最小的操作
            }
        }
        return dp[len1][len2];
    }
};


int main(){
	Solution sol;
    string s1="ab";
    string s2="a";

    cout<<sol.minDistance(s1, s2)<<endl;

    return 0;
}