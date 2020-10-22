class Solution {
public:
    vector<int> partitionLabels(string S) {
        int vis[30];
        for(int i = 0; i < S.size(); i++) {
            vis[S[i] - 'a'] = i;
        }
        vector <int> ans;
        int l = 0, r = 0;
        for(int i = 0; i < S.size(); i++) {
            r = max(r, vis[S[i] - 'a']);
            if(r == i) {
                ans.push_back(r - l + 1);
                l = r + 1;
            }
        }
        return ans;
    }
};