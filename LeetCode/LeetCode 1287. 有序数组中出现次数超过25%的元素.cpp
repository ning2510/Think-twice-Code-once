class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int m = n / 4 + 1;
        for(int i = 0; i < n; i += m) {
            auto l = lower_bound(arr.begin(), arr.end(), arr[i]);
            auto r = upper_bound(arr.begin(), arr.end(), arr[i]);
            if(r - l >= m) return arr[i];
        }
        return -1;
    }
};