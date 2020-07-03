class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int la, now = -1, i = 0, n = nums.size();
        while(i < n) {
            while(i < n && nums[i] == 0) i++;
            if(i < n && nums[i] == 1) {
                la = now;
                now = i;
                if(la != -1 && now - la - 1 < k) return false;
            }
            i++;
        }
        return true;
    }
};