#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cstring>
#include <climits>

using namespace std;

/*
Distinct Subsequences Total Accepted: 20410 Total Submissions: 81481 My Submissions Question Solution
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.

Solution:利用DP思想，dp[S.len][T.len]; dp[i][j]表示S中前i个字符包含T中前j个字符的个数；
dp[i][j] = dp[i-1][j] + dp[i-1][j-1]； if (S[i]==T[j]);    如果当前i，j处字符相同，那么有两种情况，即可以让S[i]与T[j]匹配，故此处加上了dp[i-1][j-1]的值，第二种情况是忽略S[i]，也即dp[i-1][j]的意义
           dp[i-1][j]；                else                如果当前i，j两个字符不同，那么当前的S[i]是暂时无意义的，因为他对结果没有贡献，所以dp[i][j]的值域dp[i-1][j]相等，即S的前i个字符中包含T的前j个
                                                           字符子串个数与S的前i-1个字符子串的值一样


感悟：这类两个字符串类型的DP问题，如何思考？首先就是把问题考虑成子问题，即本题为找T在S中出现次数，我们可以用DP思想这样考虑：T的前x个字符子串在S中前n个字符子串的出现次数是多少？
*/
class Solution {
public:
    int numDistinct(string S, string T) {
        int slen = S.size();
        int tlen = T.size();
        if(slen==0 || tlen==0)
            return 0;
        int dp[slen][tlen];
        memset(dp, 0, slen*tlen*sizeof(int));
        for(int i=0; i<slen; ++i){
            if(S[i]==T[0])
                dp[i][0] = dp[(i-1)>=0?(i-1):0][0] + 1;     //只需要对dp的第一列进行处理，第一行无需特殊计算，除dp[0][0]外第一行均以0为初始值（dp[0][0]已经在这里计算了）
            else
                dp[i][0] = dp[(i-1)>=0?(i-1):0][0];
        }
        for(int i=1; i<slen; ++i){
            for(int j=1; j<tlen; ++j){
                if(S[i]==T[j])
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[slen-1][tlen-1];
    }
};


int main(){
	Solution sol;
    string s1="abccd";
    string s2="acd";

    cout<<sol.numDistinct(s1, s2)<<endl;

    return 0;
}