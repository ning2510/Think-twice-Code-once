//如果我们「贪心」地进行正向查找，每次找到可到达的最远位置，就可以在线性时间内得到最少的跳跃次数
class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0, now = 0, end = 0, n = nums.size();
        for(int i = 0; i < n - 1; i++) {
            if(now >= i) {
                now = max(now, i + nums[i]);
                if(i == end) {
                    end = now;
                    ans++;
                }
            }
        }
        return ans;
    }
};