#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <cstring>
#include <climits>
#include <cmath>
#include <cctype>

using namespace std;

/*
Valid Palindrome
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.

注意：tolower是cctype里面的function，http://www.cplusplus.com/reference/cctype/；且它的命名空间不是std,是全局的(所有的C语言库都是
       全局命名空间，而不是std，所以如果声明了using namespace std,那么调用C库函数时就应该使用::func这种方式)，所以注意调用方式；
      cctype 里面包含各种对字符进行类型判断以及大小写转换函数；
      tolower/toupper 也是cctype里的函数；

      transform(begin, end, begin2, out_begin, op) 是STL的算法，它的作用是将op操作应用到begin-end序列上，并输出到out_begin开始的序列里；
            op可以是一元操作(无begin2参数)，也可以是二元操作（有begin2参数，表示op的第二个参数序列起点）；
            http://www.cplusplus.com/reference/algorithm/transform/?kw=transform
*/


class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.size();
        if(len==0)
            return true;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int i = 0, j = len-1;
        while(i<j){
            if(!isalnum(s[i]))  i++;
            else if(!isalnum(s[j]))  j--;
            else if(s[i]!=s[j])  return false;
            else
                i++, j--;
        }
        return true;
    }
};

int main(){

string a="11";
string b="1";

	  Solution sol;
      cout<<sol.isPalindrome("A man, a plan, a canal: Panama")<<endl;

    vector<int> args;
    args.push_back(2);


    return 0;
}