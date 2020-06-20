class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        int sta = 0, len = 0, num1 = 0, num2 = 0;
        unordered_map <int, int> ss;
        ss[0] = -1;
        for(int i = 0; i < array.size(); i++) {
            if(array[i][0] >= '0' && array[i][0] <= '9') num1++;
            else num2++;
            int c = num1 - num2;
            if(ss.count(c)) {
                if(i - ss[c] > len) {
                    len = i - ss[c];
                    sta = ss[c];
                }
                else if(i - ss[c] == len && ss[c] < sta) {
                    sta = ss[c];
                }
            }
            else ss[c] = i;
        }
        vector <string> ans;
        for(int i = sta + 1; i < sta + 1 + len; i++) {
            ans.push_back(array[i]);
        }
        return ans;
    }
};