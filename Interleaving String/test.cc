#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <cstring>
#include <climits>

using namespace std;

/*
Interleaving String
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.

注意特例：s1=aa, s2=ab, s3=abaa;如果s3中的第一个a匹配了s1，那么后面就不行了

Solution:DP，我们从右向左考虑，递推公式：
  dp[i][j] = s3[i+j]==s1[i] && isMatch(s1-1, s2, s3-1)  ||
             s3[i+j]==s2[j] && isMatch(s1, s2-1, s3-1)


*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1=s1.size();
        int len2=s2.size();
        if(len2+len1 != s3.size())
            return false;
        bool dp[len1+1][len2+1];
        memset(dp, false, (len1+1)*(len2+1)*sizeof(bool));

        dp[0][0] = true;
        for(int i=1; i<=len1; ++i){     //处理第一列,表示如果s2为空，那么s1与s3进行挨个匹配
            if(s1[i-1]==s3[i-1])
                dp[i][0] = true;
            else
                break;
        }
        for(int i=1; i<=len2; ++i){     //处理第一行,表示如果s1为空，那么s2与s3进行挨个匹配
            if(s2[i-1]==s3[i-1])
                dp[0][i] = true;
            else
                break;
        }
        for(int i=1; i<=len1; ++i){
            for(int j=1; j<=len2; ++j){
                int k=i+j;
                dp[i][j] = (s3[k-1]==s1[i-1] && dp[i-1][j]) || (s3[k-1]==s2[j-1] && dp[i][j-1]);
                //cout<<dp[i][j]<<",";
            }
            //cout<<endl;
        }
        return dp[len1][len2];
    }
};


int main(){
	  Solution sol;
    string s1="ab";
    string s2="aa";
    string s3="abaa";

    cout<<sol.isInterleave(s1, s2, s3)<<endl;

    return 0;
}