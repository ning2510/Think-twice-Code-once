class Solution {
public:
    typedef long long ll;
    const int mod = 1e9 + 7;
    
    ll ksm(ll a, ll b) {
        ll ans = 1, base = a;
        while(b > 0) {
            if(b & 1) ans = (ans * base) % mod;
            base = (base * base) % mod;
            b >>= 1;
        }
        return ans;
    }
    
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        ll ans = 0;
        int n = nums.size();
        int k = target / 2;
        for(int i = 0; i < n; i++) {
            if(nums[i] > k) break;
            auto it = upper_bound(nums.begin(), nums.end(), target - nums[i]) - nums.begin();
            ans = (ans + ksm(2, it - i - 1)) % mod;
        }
        return ans;
    }
};