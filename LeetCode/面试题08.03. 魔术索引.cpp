class Solution {
public:
    int ans = -1;

    void Binary_search(int l, int r, vector <int>& nums) {
        if(l > r) return ;
        int mid = (l + r) >> 1;
        if(nums[mid] == mid) {
            ans = mid;
            Binary_search(l, mid - 1, nums);
        }
        else {
            Binary_search(l, mid - 1, nums);
            if(ans == -1) Binary_search(mid + 1, r, nums);
        }
    }

    int findMagicIndex(vector<int>& nums) {
        Binary_search(0, nums.size() - 1, nums);
        return ans;
    }
};