// 单调栈 （与 LeetCode 85 相似）
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 0) return 0;
        stack <int> ss;
        ss.push(-1);
        int ans = 0, height, width;
        for(int i = 0; i < heights.size(); i++) {
            while(ss.top() != -1 && heights[i] <= heights[ss.top()]) {
                height = heights[ss.top()];
                ss.pop();
                width = i - ss.top() - 1;
                ans = max(ans, height * width);
            }
            ss.push(i);
        }
        while(ss.top() != -1) {
            height = heights[ss.top()];
            ss.pop();
            width = heights.size() - ss.top() - 1;
            ans = max(ans, height * width);
        }
        return ans;
    }
};