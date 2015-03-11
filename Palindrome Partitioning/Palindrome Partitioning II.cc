#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <cstring>
#include <climits>

using namespace std;

/*
Palindrome Partitioning II

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

DP:分解成子问题，分别解决子问题，即从开头至第i个字符处的minCut值，直到末尾.
    idp[i] = min(i, idp[j-1]+1);   //s[j...i]是回文时的情况
    本题技巧就是在判断子串是否为回文的过程中同时更新idp数组的值

收获：string的substr方法的第二个参数不是下标，是要截取的长度！
*/

class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        int idp[len+1];     //idp[i]表示从开始到第i+1个字符处的minCut值
        for(int i=0; i<len; ++i){
            idp[i] = i;
        }
        vector<vector<bool> > dp(s.size(), vector<bool>(s.size(), true));   //初始值全设为true，循环中注意要把false的重置
        for(int i=1; i<len; ++i){
            for(int j=0; j<=i; ++j){
                if(s[j]==s[i] && (i-j<2 || dp[j+1][i-1])){
                    dp[j][i] = true;
                    if(j==0)
                        idp[i] = 0;    //s[0...i]是回文，故设为0
                    else
                        idp[i] = min(idp[i], idp[j-1]+1);   //在s[j]处分割
                }
                else
                    dp[j][i] = false;   //置为false
            }
        }
        return idp[len-1];
    }
};

int main(){
	Solution sol;
    string s1="ab";
    string s2="aa";
    string s3="cabababcbc";
    cout<<endl<<sol.minCut(s3)<<endl;

    return 0;
}