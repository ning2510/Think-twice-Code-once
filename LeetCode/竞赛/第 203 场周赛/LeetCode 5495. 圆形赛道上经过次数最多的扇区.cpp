class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector <vector<int>> sum(105, vector<int>(2, 0));
        sum[0][0] = 0;
        int x = rounds[0];
        sum[x][0]++;
        sum[x][1] = x;
        for(int i = 0; i < rounds.size() - 1; i++) {
            x = rounds[i];
            int y = x;
            while(x != rounds[i + 1]) {
                if(x != y) {
                    sum[x][0]++;
                    sum[x][1] = x;
                }
                x = x % n + 1;
            }
            sum[x][0]++;
            sum[x][1] = x;
        }
        sort(sum.begin(), sum.end(), [](auto &x, auto & y) {
            return x[0] > y[0];
        });
        int i = 0;
        x = sum[0][0];
        vector <int> ans;
        while(i < sum.size()) {
            if(sum[i][0] == x && sum[i][0] != 0) ans.push_back(sum[i][1]);
            i++;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};