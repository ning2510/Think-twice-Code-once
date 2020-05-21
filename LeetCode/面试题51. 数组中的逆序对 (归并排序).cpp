class Solution {
    int ans = 0;
    vector <int> ss;

public:
    void merge(int l, int r, vector<int>& nums) {
        if(l >= r) return ;
        int mid = (l + r) >> 1;
        merge(l, mid, nums);
        merge(mid + 1, r, nums);
        int i = l, j = mid + 1, cnt = 0;
        while(i <= mid && j <= r) {
            if(nums[i] <= nums[j]) {
                ss[cnt++] = nums[i++];
            }
            else {
                ans += mid - i + 1;
                ss[cnt++] = nums[j++];
            }
        }
        while(i <= mid) ss[cnt++] = nums[i++];
        while(j <= r) ss[cnt++] = nums[j++];
        for(int i = 0; i < cnt; i++) {
            nums[l + i] = ss[i];
        }
    }

    int reversePairs(vector<int>& nums) {
        ss.resize(nums.size(), 0);
        merge(0, nums.size() - 1, nums);
        return ans;
    }
};