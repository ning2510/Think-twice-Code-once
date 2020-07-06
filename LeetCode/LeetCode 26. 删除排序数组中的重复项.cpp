class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        int x = nums[0], len = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] == x) continue;
            len++;
            x = nums[i];
        }
        if(len == n) return n;
        int l = 1, r = 1;
        while(l < len) {
            while(r < n && nums[r] == nums[r - 1]) r++;
            while(r < n - 1 && nums[r] == nums[r + 1]) r++;
            swap(nums[l], nums[r]);
            l++;
            r++;
        }
        return len;
    }
};