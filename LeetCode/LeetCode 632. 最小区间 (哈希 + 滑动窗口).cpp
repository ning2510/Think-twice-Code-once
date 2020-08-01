class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        unordered_map <int, vector<int>> ss;
        int n = nums.size();
        int minx = INT_MAX, maxn = INT_MIN;
        for(int i = 0; i < n; i++) {
            for(auto &x : nums[i]) {
                ss[x].push_back(i);
                minx = min(minx, x);
                maxn = max(maxn, x);
            }
        }
        int sum = 0, l = minx, r = minx - 1;
        int ans_left = minx, ans_right = maxn;
        vector <int> vis(n, 0);
        while(r < maxn) {
            r++;
            if(ss.count(r)) {
                for(auto &x : ss[r]) {
                    if(!vis[x]) {
                        sum++;
                    }
                    vis[x]++;
                }
            }
            while(sum == n) {
                if(r - l < ans_right - ans_left) {
                    ans_left = l;
                    ans_right = r;
                }
                if(ss.count(l)) {
                    for(auto &x : ss[l]) {
                        vis[x]--;
                        if(!vis[x]) sum--;
                    }
                }
                l++;
            }
        }
        return {ans_left, ans_right};
    }
};