class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector <string> ans;
        for(int i = 0; i < nums.size(); i++) {
            string ss = to_string(nums[i]);
            int now = i;
            while(i < nums.size() - 1 && nums[i] + 1 == nums[i + 1]) i++;
            if(i != now) {
                ss += "->" + to_string(nums[i]);
            }
            ans.push_back(ss);
        }
        return ans;
    }
};