class Solution {
public:
    int Binary_search(int x, vector <int>& arr) {
        int l = 0, r = arr.size() - 1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(arr[mid] <= x) l = mid + 1;
            else r = mid - 1;
        }
        return l;
    }

    int findBestValue(vector<int>& arr, int target) {
        int n = arr.size();
        vector <int> sum(n, 0);
        sort(arr.begin(), arr.end());
        for(int i = 0; i < n; i++) {
            if(i == 0) sum[i] = arr[i];
            else sum[i] = sum[i - 1] + arr[i];
        }
        int ans1 = target, ans = target, l = 0, r = arr[n - 1];
        while(l <= r) {
            int mid = (l + r) >> 1;
            int x = Binary_search(mid, arr);
            int s = (x == 0 ? 0 : sum[x - 1]) + mid * (n - x);
            if(ans1 > abs(s - target)) {
                ans1 = abs(s - target);
                ans = mid;
            }
            else if(ans1 == abs(s - target)) {
                ans = min(ans, mid);
            }
            if(s < target) l = mid + 1;
            else r = mid - 1; 
        }
        return ans;
    }
};