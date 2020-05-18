class Solution {
public:
    struct stu {
        int x, index;
    }q[100005];

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector <int> ans;
        int l = 1, r = 0;
        for(int i = 0; i < nums.size(); i++) {
            while(l <= r && q[r].x < nums[i]) {
                r--;
            }
            q[++r].x = nums[i];
            q[r].index = i;
            while(q[r].index - q[l].index + 1 > k && l <= r) l++;
            if(i >= k - 1) {
                ans.push_back(q[l].x);
            }
        }
        return ans;
    }
};