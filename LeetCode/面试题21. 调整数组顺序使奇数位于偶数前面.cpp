class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        vector <int> ss, pp;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] & 1) ss.push_back(nums[i]);
            else pp.push_back(nums[i]);
        }
        for(int i = 0; i < pp.size(); i++) {
            ss.push_back(pp[i]);
        }
        return ss;
    }
};