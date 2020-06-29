class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        int n = values.size();
        vector <vector <int>> ss;
        for(int i = 0; i < n; i++) {
            ss.push_back({values[i], labels[i]});
        }
        sort(ss.begin(), ss.end(), [](auto &x, auto &y) {
            return x[0] > y[0];
        });
        unordered_map <int, int> pp;
        int ans = 0, sum = 0;
        for(auto &x : ss) {
            if(pp[x[1]] == use_limit) continue;
            pp[x[1]]++;
            ans += x[0];
            sum++;
            if(sum == num_wanted) break;
        }
        return ans;
    }
};