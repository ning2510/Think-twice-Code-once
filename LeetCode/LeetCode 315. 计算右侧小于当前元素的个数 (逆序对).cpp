class Solution {
public:
    int n;
    vector <int> c;

    int lowbit(int x) {
        return x & (-x);
    }

    void update(int i, int x) {
        while(i <= n) {
            c[i] += x;
            i += lowbit(i);
        }
        return ;
    }

    int get_sum(int i) {
        int ans = 0;
        while(i > 0) {
            ans += c[i];
            i -= lowbit(i);
        }
        return ans;
    }

    vector<int> countSmaller(vector<int>& nums) {
        n = nums.size();
        c.resize(n + 1, 0);
        vector <int> ss;
        for(int i = 0; i < n; i++) {
            ss.push_back(nums[i]);
        }
        sort(ss.begin(), ss.end());
        vector <int> ans(n, 0);
        for(int i = n - 1; i >= 0; i--) {
            auto it = lower_bound(ss.begin(), ss.end(), nums[i]) - ss.begin();
            int sum = get_sum(it);
            update(it + 1, 1);
            ans[i] = sum;
        }
        return ans;
    }
};