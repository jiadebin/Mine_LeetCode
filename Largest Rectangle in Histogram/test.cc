#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cstring>
#include <climits>

using namespace std;

/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.

Solution:利用一个stack，把具有递增趋势的元素压栈，一旦遇到比栈顶元素小的新元素，就弹栈直到栈顶元素小于它，
        弹栈时顺便计算以当前元素作为最小高度的面积值,计算时以栈中下面元素作为左边界，以当前遍历处为右边界；
        最后遍历完，如果栈里还有元素，就依次弹栈并计算
时间复杂度：由于每个元素只进栈、出栈一次，故为 O(logN)
参考：http://www.geeksforgeeks.org/largest-rectangle-under-histogram/
*/
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int maxArea=0;
        int curArea;
        stack<int> s;
        int len = height.size();
        for(int i=0; i<len; ++i){
            if(s.empty() || height[i]>=height[s.top()])
                s.push(i);
            else{
                while(!s.empty() && height[s.top()] > height[i]){
                    int c = s.top();
                    s.pop();
                    curArea = height[c]*(s.empty()?i:(i-s.top()-1));
                    if(maxArea<curArea)
                        maxArea = curArea;
                }
                s.push(i);
            }
        }

        while(!s.empty()){
            int c = s.top();
            s.pop();
            curArea = height[c]*(s.empty()?len:(len-s.top()-1));    //注意此时右边界为总长度，因为当前元素是栈顶，表示右侧没有元素比它小了，否则它就不会是栈顶
            if(maxArea<curArea)
                maxArea = curArea;
        }
        return maxArea;
    }
};


int main(){
	Solution sol;
    vector<int> height;
    height.push_back(2);
    height.push_back(2);

    cout<<sol.largestRectangleArea(height)<<endl;

    return 0;
}