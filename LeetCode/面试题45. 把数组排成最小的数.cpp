class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector <string> ss;
        for(int i = 0; i < nums.size(); i++) {
            ss.push_back(to_string(nums[i]));
        }
        sort(ss.begin(), ss.end(), [](const auto x, const auto y) {
            return x + y < y + x;
        });
        string ans;
        for(int i = 0; i < ss.size(); i++) {
            ans += ss[i];
        }
        return ans;
    }
};