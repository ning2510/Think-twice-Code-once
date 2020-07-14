class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map <int, int> ss;
        for(auto &x : nums1) {
            ss[x] = 1;
        }
        vector <int> ans;
        for(auto &x : nums2) {
            if(ss.count(x) && ss[x] > 0) {
                ss[x]--;
                ans.push_back(x);
            }
        }
        return ans;
    }
};