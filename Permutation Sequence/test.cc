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
Permutation Sequence

The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.

Solution: 数学方法是，假设我们数字数组为[1,2,3,4...]，首先分析第一位数字的可能性，那么第一位数字在数组中的索引为(k-1)/(n-1)!，根据就是余下(n-1)位组合的可能性有(n-1)!种；
          故第一位可用这个式子确定；同理，第二位也可以确定，但是总排列数pc和k都要更新
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        int pc = pnum(n);
        // cout<<pc<<endl;
        int cn = n;
        vector<int> vec;
        for(int i=1; i<=n; ++i){
            vec.push_back(i);
        }
        k--;    //注意这句很重要，因为我们数组vec的索引是从0开始的
        for(int i=0; i<n; ++i){
            pc /= cn;   //n-1个数字组合数量
            int pos = k/pc;
            res += '0'+vec[pos];
            //cout<<res<<", ";
            vec.erase(vec.begin()+pos);
            k = k - pos*pc;     //更新k的值
            cn--;
        }
        return res;
    }

    int pnum(int n){
        int res=1;
        for(int i=2; i<=n; ++i){
            res *= i;
        }
        return res;
    }
};

int main(){
	Solution sol;

    cout<<sol.getPermutation(3, 5)<<endl;

    return 0;
}