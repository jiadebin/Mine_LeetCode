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

using namespace std;

/*
计数排序：
1、计算取值范围，确定计数数组大小；
2、统计元素出现次数；
3、累加出现次数；
4、逆序遍历原数组，依次放置每个元素到目标数组；
*/

#define KEY_LEN 10    //unsigned int最大42亿，共十位

class Solution {
public:
    vector<int> countSort(vector<int> &num) {
        int len = num.size();
        if(len<2)
            return num;
        int min_val = *min_element(num.begin(), num.end());
        int max_val = *max_element(num.begin(), num.end());

        int arr_len = max_val - min_val +1, base = min_val;     //用最小值做base
        vector<int> bkt(arr_len, 0);
        for(int ele:num){
            bkt[ele-base]++;        //出现次数累加
        }
        for(int i=1; i<arr_len; ++i){
            bkt[i] += bkt[i-1];     //次数累计，代表当前位置元素在最终有序列表中的索引
        }
        int idx;
        int val;
        vector<int> res(len, 0);
        for(int i=len-1; i>=0; i--){    //逆序遍历是为了保持稳定性
            val = num[i];           //取得当前要放置的值
            idx = bkt[val-base]-1;  //计算其索引
            res[idx] = val;
            bkt[val-base]--;
        }
        return res;
    }
};


int main(){
	Solution sol;
    vector<int> args;
    args.push_back(5);
    args.push_back(90);
    args.push_back(13);
    args.push_back(64);
    args.push_back(5);
    args.push_back(23);
    // args.push_back(0);
    // args.push_back(0);
// sol.largestNumber(args);

    args = sol.countSort(args);
    for(auto t:args)
        cout<<t<<",";
    cout<<endl;
    // cout<<sol.countSort(args)<<endl;
    return 0;
}