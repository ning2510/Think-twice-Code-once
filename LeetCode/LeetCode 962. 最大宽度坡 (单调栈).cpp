/*
根据题意需要找出最大宽度并且A[i] <= A[j]，很容易想到i需要从左往右，j从右往左遍历数组。
进一步思考，A[i]的值越小越容易得到最大宽度，同时还要考虑i尽可能的小。
到这里，可以想到利用单调递减栈:
1、正向扫描数组记录严格的单调递减A[i]的下标
2、反向扫描数组比较A[j]与栈顶元素A[ss.top()]的值，如果满足条件，则弹出栈顶元素，不断循环直到栈为空
*/
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        stack <int> ss;
        for(int i = 0; i < A.size(); i++) {
            if(ss.empty() || A[i] < A[ss.top()]) {
                ss.push(i);
            }
        }
        int ans = 0;
        for(int i = A.size() - 1; i > ans; i--) {
            while(!ss.empty() && A[i] >= A[ss.top()]) {
                ans = max(ans, i - ss.top());
                ss.pop();
            }
        }
        return ans;
    }
};