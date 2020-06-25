class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map <int, int> ss;
        vector <int> ans;
        for(auto &x : arr2) ss[x]++;
        for(auto &x : arr1) {
            if(!ss.count(x)) ans.push_back(x);
        }
        sort(ans.begin(), ans.end(), [](auto &x, auto &y) {
            return x > y;
        });
        ss.clear();
        for(auto &x : arr1) ss[x]++;
        for(int i = arr2.size() - 1; i >= 0; i--) {
            for(int j = 1; j <= ss[arr2[i]]; j++) {
                ans.push_back(arr2[i]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};