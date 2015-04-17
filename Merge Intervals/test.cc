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
Merge Intervals
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18]

思路：现根据start排序，然后遍历并合并重叠项
*/

 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

bool cmp(Interval le, Interval re) {
    return (le.start < re.start);
}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        int len = intervals.size();
        if(len<2)
            return intervals;
        vector<Interval> res;
        sort(intervals.begin(), intervals.end(), cmp);
        Interval pre = intervals[0];
        for(int i=1; i<len; ++i) {
            Interval cur = intervals[i];
            if(cur.start<=pre.end) {
                pre.end=cur.end;
            } else {
                res.push_back(pre);
                pre = cur;
            }
        }
        res.push_back(pre);
        return res;
    }
};

int main(){
	Solution sol;
    vector<Interval> args;
    args.push_back(Interval(1,3));
    args.push_back(Interval(2,6));
    args.push_back(Interval(8,10));
    args.push_back(Interval(15,18));
    args.push_back(Interval(16,21));
    // args.push_back(0);
    // args.push_back(0);
// sol.largestNumber(args);
// cout<<mycmp("3", "30");
    cout<<sol.merge(args).size()<<endl;
    return 0;
}