class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int last = 0;
        for(auto &x : arr) {
            int sum = x - last - 1;
            if(sum >= k) return last + k;
            k -= sum;
            last = x;
        }
        return arr[arr.size() - 1] + k;
    }
};