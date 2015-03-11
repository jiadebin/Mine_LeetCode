#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <cstring>
#include <climits>

using namespace std;

/*
Scramble String

Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

Return 3.

Solution:
参考：http://www.blogjava.net/sandy/archive/2013/05/22/399605.html

(1)递归+剪枝：把每个字符串分成两个部分，s1_p1, s1_p2 和 s2_p1, s2_p2，只要
    isScramble(s1_p1, s2_p1) && isScramble(s1_p2, s2_p2) ||
    isScramble(s1_p1, s2_p2) && isScramble(s1_p1, s2_p2)，
    那么就返回true，注意比较的部分长度要一样,遍历分割点只要发现true就返回


感悟：此问题递归思路直接想很难能想出来，但是首先找到递归法，就很容易想出DP的思路了

*/

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        if(len1==0 || len2==0 || len1!=len2)
            return false;
        if(s1==s2)
            return true;    //a, a的情况

        string str1 = s1;
        string str2 = s2;
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        if(str1!=str2)
            return false;   //剪枝法，加速递归，如果两个str字符集不同，肯定false

        for(int i=1; i<len1; ++i){
            bool res = isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i));
            res = res || (isScramble(s1.substr(0, i), s2.substr(len2-i)) && isScramble(s1.substr(i), s2.substr(0, len2-i)));
            if(res)
                return true;     //当且仅当有一个结果为true时才return,false不应返回,因为后面的循环可能有true的情况
        }
        return false;
    }

    /*
    (2)DP:利用三维数组dp[k][i][j]表示s1中以第i个字符开始的与s2中以第j个字符开始的长度为k的子串的isScramble值；
      dp[k][i][j] = (dp[loopk]][i][j] && dp[k-loopk][i+loopk][j+loopk])||
                    (dp[loopk]][i][j+k-loopk] && dp[k-loopk][i+loopk][j])
                    其中 1<=loopk<k
      k从1至len遍历，最后返回dp[len][0][0].
    */
    bool isScramble_dp(string s1, string s2) {
        int len1 = s1.size();
        if(len1==0 || s2.size()==0 || len1!=s2.size())
            return false;
        if(s1==s2)
            return true;    //a, a的情况

        vector<vector<vector<bool> > > dp(len1+1, vector<vector<bool> >(len1, vector<bool>(len1, false)));
        for(int i=0; i<len1; ++i){
            for(int j=0; j<len1; ++j){
                if(s1[i]==s2[j])
                    dp[1][i][j] = true;
            }
        }
        for(int k=2; k<=len1; ++k){
            for(int i=0; i<len1-k+1; ++i){    //注意遍历时i，j的范围，不能让i+loopk超过len, j也一样
                for(int j=0; j<len1-k+1; ++j){
                    dp[k][i][j] = false;
                    for(int loopk=1; loopk<k && dp[k][i][j]==false; ++loopk){
                        dp[k][i][j] = (dp[loopk][i][j] && dp[k-loopk][i+loopk][j+loopk]) ||
                                      (dp[loopk][i][j+k-loopk] && dp[k-loopk][i+loopk][j]);
                    }
                }
            }
        }
        return dp[len1][0][0];
    }

};


int main(){
	  Solution sol;
    string s1="abb";
    string s2="bab";

    cout<<sol.isScramble_dp(s1, s2)<<endl;

    return 0;
}