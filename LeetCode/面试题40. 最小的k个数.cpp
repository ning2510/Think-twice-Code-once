class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        vector <int> ss;
        for(int i = 0; i < k; i++) {
            ss.push_back(arr[i]);
        }
        return ss;
    }
};