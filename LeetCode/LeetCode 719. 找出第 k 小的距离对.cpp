class Solution {
public:
    int judge(int mid, int k, vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(int i = 0; i < n - 1; i++) {
            auto it = upper_bound(nums.begin(), nums.end(), nums[i] + mid) - nums.begin();
            sum += it - 1 - i;
        }
        return sum >= k;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = -1, l = 0, r = nums[nums.size() - 1] - nums[0];
        while(l <= r) {
            int mid = ((l ^ r) >> 1) + (l & r);
            if(judge(mid, k, nums)) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};