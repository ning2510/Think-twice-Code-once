class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector <int> ss(26, 0);
        for(auto &x : chars) {
            ss[x - 'a']++;
        }
        vector <int> m = ss;
        int ans = 0, flag = 1;
        for(int i = 0; i < words.size(); i++) {
            flag = 1;
            ss = m;
            for(auto &x : words[i]) {
                if(ss[x - 'a'] > 0) {
                    ss[x - 'a']--;
                }
                else {
                    flag = 0;
                    break;
                }
            }
            if(flag) ans += words[i].size();
        }
        return ans;
    }
};