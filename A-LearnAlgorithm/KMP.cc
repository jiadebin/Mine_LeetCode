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
参考链接：http://www.cnblogs.com/goagent/archive/2013/05/16/3068442.html
总结：求next数组的过程就是一个KMP匹配的过程，next数组的意义就是在i和j失配时，我们需要知道j应该向左跳到哪个位置。
注意：注意-1和p.size()的值去比较时会返回错误结果!!!因为size_t类型时非负的，二者不能比较.
*/

//求next数组的值,在当前位置计算下一个位置的next值,这样next值在使用时最方便
void getNext(string &p, vector<int> &next){
    int len = p.size();
    next.resize(len);
    int i = 0, j = -1;
    next[0] = -1;
    while(i<len-1){
        if(j==-1 || p[i]==p[j]){
            ++i, ++j;
            if(p[i]==p[j])      //优化之处，即如果p[i+1]==p[j]，那么设置next[i+1]=j，是没有意义的，因为匹配依然会失败,还要继续跳转到next[j]，所以可以直接在这里一步到位
                next[i] = next[j];
            else
                next[i] = j;
        }
        else{
            j = next[j];
        }
    }
}

//匹配过程
bool kmpMatch(string &s, string &p, vector<int> &next){
    int i = 0, j = 0;
    while(i<s.size()){
        if(j==-1 || s[i]==p[j]){
            ++i, ++j;
            if(j==p.size())
                return true;
        }
        else{
            j = next[j];
        }
    }
    return false;
}

int main(){

    string s = "abcabdabe";
    string p = "abdabe";
             //-1 0 0 0 1 2    next值

// cout<<(-1<p.size())<<endl;  //注意用-1 去和size_t类型去比较时会返回错误结果!!!

    vector<int> next;
    getNext(p, next);
    bool res = kmpMatch(s, p, next);
    cout<<res<<endl;
    return 0;
}

