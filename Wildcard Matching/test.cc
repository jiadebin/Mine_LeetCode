#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <cstring>
#include <climits>

using namespace std;

/*
Wildcard Matching

Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false

Solution:
    BT法，但是容易超时，最后加上了剪枝条件，即p首先跳过 * 字符，剩余非 * 字符串与s比较，见代码
    DP法，O(MN)空间复杂度超出了内存限制，故使用O(2N)的二维数组节省空间，同时要适当考虑p非常长（远比s长）的情况如何快速判断；
            其次是dp数组第一行要进行初始化
*/

class Solution {
public:
    bool isMatch(const char *s, const char *p){     //optimal  DP
        if(strcmp(s, p) == 0)
            return true;
        int ls = strlen(s);
        int lp = strlen(p);
        if(ls==0){
            int i=0;
            while(i<lp && p[i]=='*'){
                i++;
            }
            if(i==lp)
                return true;        //for s="", p="*" case
        }
        int cc = 0;
        for(int i=0; i<lp; ++i){
            if(p[i]=='*')
                continue;
            cc++;
        }
        if(cc>ls)   //比较p中去除*之后的纯字母长度与s的长度，如果仍比s的字符多，那么肯定不匹配,这样可以快速比较p非常长的case
            return false;

        vector<vector<bool> > dp(2, vector<bool>(lp+1, false));
        for(int i=1; i<=ls; ++i){
            if(i==1){
                dp[0][0] = true;    //dp[0][0] = true, 因为相当于我们在s、p开头加了一个空字符，故\0 == \0
                dp[1][0] = false;
                for(int j=1; j<=lp; ++j){
                    if(p[j-1]=='*'){
                        dp[0][j] = dp[0][j-1];  //第一行dp值初始化,在p[0] = '*'时非常重要，保证dp[0][1]=true
                    }
                }
            }
            else{
                dp[0][0] = false;   //dp[i-1][0] = false
                dp[1][0] = false;
            }
            char cs = s[i-1];
            for(int j=1; j<=lp; ++j){
                char cp = p[j-1];
                if(cp=='?' || cs==cp){
                    dp[i%2][j] = dp[(i-1)%2][j-1];
                }
                else if(cp=='*'){
                    dp[i%2][j] = dp[(i-1)%2][j-1] || dp[(i-1)%2][j] || dp[i%2][j-1];
                }
                else
                    dp[i%2][j] = false;
            }
        }
        return dp[ls%2][lp];
    }

    bool isMatch_DP_MemLimitExceed(const char *s, const char *p){   //DP,耗内存过大
        if(s == NULL || p == NULL)  return false;
        int ls = strlen(s);
        int lp = strlen(p);
        vector<vector<bool> > dp(ls+1, vector<bool>(lp+1, false));
        dp[0][0] = true;
        for(int i=1; i<=ls; ++i){
            char cs = s[i-1];
            for(int j=1; j<=lp; ++j){
                char cp = p[j-1];
                if(cp=='?' || cs==cp){
                    dp[i][j] = true;
                }
                else if(cp=='*'){
                    dp[i][j] = dp[i-1][j-1] || dp[i-1][j] || dp[i][j-1];
                }
            }
        }
        return dp[ls][lp];
    }

    bool isMatch_BT(const char *s, const char *p)
    {
        if (s == NULL || p == NULL) return false;
        if (*p == '\0') return *s == '\0';

        if (*p == '*')
        {
            while (*p == '*') ++p;      //跳过'*'
            while (*s != '\0')
            {
                if (isMatch(s, p)) return true;     //因为p跳过了*，这里先递归比较s与p非*的串,如果成功则返回true
                ++s;    //跳过'*'之后，s也可以在这里跳过任意个字符,如果上一行一直返回false,那么s就一直跳知道末尾\0为止
            }
            return isMatch(s, p);   //s会最终跳到\0
        }
        else if ((*s != '\0' && *p == '?') || *p == *s)
        {
            return isMatch(s + 1, p + 1);
        }

        return false;
    }

    bool isMatch_BT_TLE(const char *s, const char *p) {    //超时的方法,超时的原因就是没有跳过'*'！遇到‘*’应该跳到下一个
        if(*p == '\0')
            return (*s=='\0');
        if(*p == '*'){
            while(*s != '\0'){
                if(isMatch(s, (p+1)))
                    return true;
                ++s;
            }
            return isMatch(s, (p+1));
        }
        else if(cequal(*s, *p)){
            ++s;
            ++p;
            return isMatch(s, p);
        }
        return false;
    }

    bool cequal(const char a, const char b){
        if(a==b || b=='?')
            return true;
        return false;
    }
};

int main(){
	Solution sol;
    string s1="c";
    string s2="*a*";
    string s3="";
    string s4="";
    // cout<<strcmp(s3.c_str(), s4.c_str())<<endl;
    cout<<sol.isMatch(s1.c_str(), s2.c_str())<<endl;
    // bool res = sol.isMatch_2(s1.c_str(), s2.c_str());
    // cout<<res<<endl;

    return 0;
}