class Solution {
    int ans = 0;
    int ss[50005], pp[50005];

    void meger(int l, int r) {
        if(l == r) return ;
        int mid = (l + r) >> 1;
        meger(l, mid);
        meger(mid + 1, r);
        int i = l, j = mid + 1, cnt = 0;
        while(i <= mid && j <= r) {
            if(ss[i] <= ss[j]) pp[cnt++] = ss[i++];
            else {
                pp[cnt++] = ss[j++];
                ans += mid - i + 1;
            }
        }
        while(i <= mid) pp[cnt++] = ss[i++];
        while(j <= r) pp[cnt++] = ss[j++];
        for(int i = 0; i < cnt; i++) {
            ss[i + l] = pp[i];
        }
        return ;
    }

public:
    int reversePairs(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        for(int i = 0; i < nums.size(); i++) {
            ss[i] = nums[i];
        }
        meger(0, nums.size() - 1);
        return ans;
    }
};
