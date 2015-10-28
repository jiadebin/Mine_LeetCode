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
Maximum Gap
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

思路：即给一个乱序数组，找到其中按序排列时相邻元素的最大差值，注意题中说要用线性时间/空间解决。
      因为目标是找到按序相邻的差值，所以应该先让其有序才能找到，但是排序算法中基于比较的常见算法复杂度都是O(logN)的，
      所以只能考虑O(N)的三种：计数、基数、桶排序。
      不知道数据范围，故排除计数法；
      基数法也不具备普遍适用性；
      桶排序是首选，而且桶数量的分配是：先算出这些数据的平均gap = (max-min)/(size-1)，然后 (max-min)/平均gap +1= 桶个数，
      注意算平均gap时size要减一，算桶个数时如果要把min和max也都放入桶中，那么桶个数计算要加一(否则max可能超过最后一个桶的取值范围)
      本题对于桶排序还有一个捷径：桶排序算法中各个桶内的相邻元素的gap值肯定不会超过桶的跨度，即avg_gap；所以最大跨度应该出现在桶间，
      因为桶间的gap一定不小于桶内gap（根据桶个数的计算公式可以得出）;
      所以本题使用桶排序时不需要对桶内元素进行存储和排序，只需要存储桶的最大、最小元素，然后计算桶间的gap，去最大值即为结果。
    网络参考：http://www.cnblogs.com/skysand/p/4179099.html
    // 算出相邻两个桶之间的最大差值
    // 如果是平均分布，则桶的数目和元素的数目相同时，其排序的时间复杂度是0(n)
    // 我们假设桶的个数和元素的数目相同，若是平均分布，则每个桶里有一个数，而若某个桶里有两个以上的桶时，这时必有至少一个是空桶，那么最大间隔可能就落在空桶的相邻两个桶存储的数之间，最大间隔不会落在同一个桶的数里，因此我们不需要对每个桶再排一次序，只需要记录同一个桶的最大值和最小值，算出前一个有最大值的桶和后一个有最小值的桶之差，则可能是最大间隔
    //步骤：1.算好用的桶的个数，用最大元素和最小元素算出平均间隔，记录在平均间隔上的最大值和最小值，
    // 2. 再算出前一个间隔里的最大值和后一个间隔里的最小值之差，取最大的一个，

    本题用到的algorithms：max_element、min_element返回列表里的最大/最小值的迭代器，即指针，所以取值要加*
                          make_pair(a,b) 制作一个pair，而不能直接用pair(a,b)
                          min/max
                 cmath:   ceil(double)向上取整，但是返回的是一个浮点数（小数部分为0），不是int，如5.0
*/

class Solution {
public:
    int maximumGap(vector<int> &num) {
        int len = num.size();
        if(len<2)
            return 0;
        auto min_val = *min_element(num.begin(), num.end());
        auto max_val = *max_element(num.begin(), num.end());
        if(len==2)
            return (max_val-min_val);
        int avg_gap = ceil((double)(max_val-min_val)/(len-1));
        // int bkt_count = ceil((double)(max_val-min_val)/avg_gap);     //如果不需要把最大值放入桶中，则不可以用本句
        int bkt_count = (max_val-min_val)/avg_gap+1;
        // cout<<avg_gap<<", bkt_count="<<bkt_count<<endl;

        vector<pair<int, int> > bucket(bkt_count, make_pair(INT_MAX, INT_MIN));
        for(int i=0; i<len; ++i){
            // if(num[i]==min_val || num[i]==max_val)
                // continue;
            int bkt_num = (num[i]-min_val)/avg_gap;
            bucket[bkt_num].first = min(num[i], bucket[bkt_num].first);
            bucket[bkt_num].second = max(num[i], bucket[bkt_num].second);
        }
        int max_gap(0), last_max(min_val);
        for(auto bkt:bucket){
            if(bkt.first == INT_MAX)
                continue;
            int cur_min = bkt.first, cur_max = bkt.second;
            max_gap = max(max_gap, cur_min-last_max);
            last_max = cur_max;
        }
        // max_gap = max(max_gap, max_val-last_max);
        return max_gap;
    }
};

int main(){
	Solution sol;
    vector<int> args;
    args.push_back(3);
    args.push_back(30);
    args.push_back(35);
    args.push_back(5);
    args.push_back(9);
    // args.push_back(0);
    // args.push_back(0);
// sol.largestNumber(args);
// cout<<mycmp("3", "30");
    cout<<sol.maximumGap(args)<<endl;
    return 0;
}