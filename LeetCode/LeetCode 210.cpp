class Solution {
    int inn[10005], out[10005];
    int sum[2005][2005];

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int x, y;
        for(int i = 0; i < prerequisites.size(); i++) {
            y = prerequisites[i][0];
            x = prerequisites[i][1];
            inn[y]++;
            sum[x][++out[x]] = y;
        }
        queue <int> ss;
        int flag = 0;
        for(int i = 0; i < numCourses; i++) {
            if(!inn[i]) {
                ss.push(i);
                flag = 1;
            }
        }
        if(!flag) return {};
        vector <int> ans;
        int cnt = 0;
        while(!ss.empty()) {
            int now = ss.front();
            ss.pop();
            ans.push_back(now);
            for(int i = 1; i <= out[now]; i++) {
                int v = sum[now][i];
                inn[v]--;
                if(!inn[v]) {
                    ss.push(v);
                }
            }
        }
        if(ans.size() != numCourses) return {};
        return ans;
    }
};