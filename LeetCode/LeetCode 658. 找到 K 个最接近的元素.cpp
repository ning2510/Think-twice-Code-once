class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector <int> ss;
        if(x <= arr[0]) {
            for(int i = 0; i < k; i++) {
                ss.push_back(arr[i]);
            }
            return ss;
        }
        if(x >= arr[arr.size() - 1]) {
            for(int i = arr.size() - k; i < arr.size(); i++) {
                ss.push_back(arr[i]);
            }
            return ss;
        }
        int l, r;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] <= x && arr[i + 1] >= x) {
                l = i;
                r = i + 1;
                break;
            }
        }
        int now = 0;
        while(l >= 0 && r < arr.size()) {
            int p = x - arr[l];
            int q = arr[r] - x;
            if(p <= q) ss.push_back(arr[l--]);
            else ss.push_back(arr[r++]);
            now++;
            if(now == k) break;
        }
        while(now < k && l >= 0) {
            ss.push_back(arr[l--]);
            now++;
        }
        while(now < k && r < arr.size()) {
            ss.push_back(arr[r++]);
            now++;
        }
        sort(ss.begin(), ss.end());
        return ss;
    }
};