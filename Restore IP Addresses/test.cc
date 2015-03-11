#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <cstring>
#include <climits>
#include <cmath>

using namespace std;

/*
Restore IP Addresses

Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

Solution: 本题也属于回溯问题，关键是找好递归的剪枝条件。把IP分成4段，0开头的段只能有这一个字符，且数值范围是0~255
*/

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        int n = s.size();
        string cs;
        bt(res, s, cs, n, 0, 1);
        return res;
    }
    void bt(vector<string> &res, const string &s, string &cs, int n, int x, int seg){
        if(3*(5-seg)<n-x)   //每段最多有3个字符，如果剩下的字符过多，直接返回
            return;
        if(x == n && seg==5){
            res.push_back(cs.substr(0, n+3));
            return;
        }
        string num;
        int lnum;
        if(seg==4){     //如果是最后一段，那么余下的所有字符一起考虑
            num = s.substr(x);
            lnum = num.size();
            if(lnum == 0)
                return;
            if(lnum>1 && num[0]=='0')   //0 开头时只能长度为1
                return;
            int val = atoi(num.c_str());
            if(val>=0 && val<=255) {  //数值范围1~255或0（且只能有一个0，不能是000）
                cs.append(num);
                cs.append(".");
                // cout<<"before:"<<cs<<endl;
                 bt(res, s, cs, n, n, seg+1);
                 cs.erase(cs.size()-lnum-1, lnum+1);
                 // cout<<"after:"<<cs<<endl;
            }
        }
        else{
            for(int i=x; i<x+3 && i<n; ++i){
                num.push_back(s[i]);
                lnum = num.size();
                if(lnum == 0)
                    return;
                if(num[0]=='0' && lnum>1)      //0 头只能有一个字符
                    return;
                int val = atoi(num.c_str());
                if((val>=0 && val<=255)){
                     cs.append(num);
                     cs.append(".");
                     // cout<<"before:"<<cs<<endl;
                     bt(res, s, cs, n, i+1, seg+1);
                     cs.erase(cs.size()-lnum-1, lnum+1);
                     // cout<<"after:"<<cs<<"\n";
                }
            }
        }
    }
};

int main(){
	Solution sol;
    vector<int> num;
    num.push_back(1);
    string s = "010010";
    cout<<sol.restoreIpAddresses(s).size()<<endl;

    return 0;
}