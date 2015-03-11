#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <cstring>
#include <climits>

using namespace std;

/*
Palindrome Partitioning

Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]

回溯法：利用递归的思想处理问题，如果满足条件就一直递归到末尾，然后加入结果集，否则返回，进入下一个循环.
        本题就是分割点的循环，即考虑每一个位置为分割点，判断左侧子串是否回文，若是，对右侧子串进行递归，否则放弃当前位置进入下一次循环。
DP：    不同循环之间会有重复分割、判断动作，因为产生的右侧子串可能重复。
        优化方法就是用空间换时间，也即动态规划，用二维数组保存中间结果，dp[i][j]的值表示s[i...j]是否回文，这样可以加快判断，但是依然还是用递归方法生成结果。

收获：string的substr方法的第二个参数不是下标，是要截取的长度！
*/

class Solution {
    vector<vector<string> > res;
public:
    vector<vector<string> > partition_backtracking(string s) {
        vector<string> list;
        generateList(list, s);
        return res;
    }
    void generateList(vector<string> & list, string s){
        int len=s.size();
        if(len==0){
            res.push_back(list);    //到了末尾说明分割的子串都是回文，就把list加入res
            return;
        }

        for(int i=1; i<=len; ++i){      //注意i的最大值为len,因为如果整个string也是回文的话，需要将其加入结果集
            string str=s.substr(0, i);
            if(isPalind(str)){
                list.push_back(str);
                generateList(list, s.substr(i));
                list.pop_back();    //一直重复使用一个list,所以push完要pop
            }
            else
                continue;
        }
    }
    bool isPalind(string s){
        int len = s.size();
        int i=0, j=len-1;
        while(i<j){
            if(s[i]==s[j]){
                ++i;
                --j;
            }
            else
                return false;
        }
        return true;
    }

    vector<vector<string> > partition(string s) {   //DP
        vector<string> list;
        vector<vector<bool> > dp(s.size(), vector<bool>(s.size(), true));
        initDPTab(dp, s);
        genListDP(list, s, s.size(), 0, dp);
        return res;
    }

    void genListDP(vector<string> & list, string & s, int len, int start, vector<vector<bool> > & dp){
        if(start==len){
            res.push_back(list);
            return;
        }
        for(int i=1; i<=len-start; ++i){
            if(dp[start][start+i-1]){
                list.push_back(s.substr(start, i));         //注意string的substr方法的第二个参数不是下标，是要截取的长度！
                genListDP(list, s, len, start+i, dp);
                list.pop_back();
            }
            else
                continue;
        }
    }

    void initDPTab(vector<vector<bool> > & dp, string & s){
        int len = s.size();
        for(int dist=1; dist<len; ++dist){
            for(int i=0; i<len-dist; ++i){
                int j=i+dist;
                dp[i][j] = dp[i+1][j-1]&&(s[i]==s[j]);
            }
        }
    }
};

void printRes(vector<vector<string> > res){
    int r = res.size();
    for(int i=0; i<r; ++i){
        int c = res[i].size();
        for(int j=0; j<c; ++j){
            cout<<res[i][j]<<", ";
        }
        cout<<endl;
    }
}
int main(){
	Solution sol;
    string s1="ab";
    string s2="aa";
    string s3="abaf";
    // printRes(sol.partition_backtracking(s3));
    printRes(sol.partition(s3));
    // cout<<sol.partition(s3)<<endl;

    return 0;
}