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
Insert Interval
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

思路：类似于插入排序，将新的Interval插入到列表中，由于原列表已经是有序的，所以只需分情况进行处理，
        看newInterval的区间与当前列表元素区间的关系；一共有以下几种：

      (1)[---]
                 [---]

      (2)       [---]
         [---]

      (3)[---]
           [---]

      (4)    [---]
           [---]

      (5)   [-----]
              [-]

      (6)   [----]
          [---------]

    根据上述关系将两个interval合并，注意合并之后要从列表中删除当前的，最后插入新的，注意插入位置。
*/

 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int len = intervals.size();
        if(len<1){
            intervals.push_back(newInterval);
            return intervals;
        }
        int i=len;
        for( ; i>0; --i) {
            auto cur = intervals[i-1];
            if(newInterval.start > cur.end) {
                break;
            }
            if(newInterval.end < cur.start)
                continue;
            if(newInterval.start >= cur.start) {
                if(newInterval.end >= cur.end) {
                    newInterval.start = cur.start;
                    intervals.erase(intervals.begin()+i-1);
                    i--;
                    break;
                } else {
                    newInterval.start = cur.start;
                    newInterval.end = cur.end;
                    intervals.erase(intervals.begin()+i-1);
                    i--;
                    break;
                }
            } else {
                if(newInterval.end < cur.end) {
                    newInterval.end = cur.end;
                    intervals.erase(intervals.begin()+i-1);

                } else {
                    intervals.erase(intervals.begin()+i-1);

                }
            }
        }
        intervals.insert(intervals.begin() + i, newInterval);
        return intervals;
    }
};


int main(){
	Solution sol;
    vector<Interval> args;
    args.push_back(Interval(1,3));
    // args.push_back(Interval(6,9));
    // args.push_back(0);
    // args.push_back(0);
// sol.largestNumber(args);

    args = sol.insert(args, Interval(0, 1));
    for(auto t:args)
        cout<<t.start<<","<<t.end<<" | ";
    cout<<endl;
    // cout<<sol.countSort(args)<<endl;
    return 0;
}