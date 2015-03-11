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

DP:分解成子问题，分别解决子问题，从开头开始遍历，dp[i]表示0-第i个字符中连续括号子串的长度(s[i]=')'且被包含到这个子串中,否则dp[i]=0)，考虑第i+1个字符，若为右括号“)”，那么
    由于dp[i]已知，我们可以跳过向前跳过dp[i]个字符，比如 )( () ) ,我们可以跳过中间那对括号，直接看更前一个(设为第last个)是否为"("，若是，那么
    dp[i+1] = dp[i]+2+dp[last-1]；若不是，那么
    dp[i+1] = 0;
    由于每次i都要看一下之前的last处字符，时间复杂度应该还是O(N)，没有到O(N^2)

栈实现的方法：用一个栈遇到左括号就压栈，遇到右括号就跟栈顶元素弹栈，并把二者位置标记为true（用一个一维数组），最后遍历这个一维数组，求出最长连续为true的长度即可
              时间复杂度为O(N)

*/

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int la = strlen(s);
        int lb = strlen(p);
        if(*p != '*' && !cequal(*s, *p))
            return false;
        if(lb>1 && *(p+lb-1) != '*' && !cequal(*s, *(p+lb-1)))
            return false;
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
    string s1="aa";
    string s2="a";
    string s3="()";
    cout<<sol.isMatch(s1.c_str(), s2.c_str())<<endl;

    return 0;
}