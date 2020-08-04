class Solution {    //与 LeetCode210 类似
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector <int> inn(numCourses, 0);
        vector <int> out(numCourses, 0);
        vector <vector<int>> sum(numCourses, vector<int>(numCourses, 0));
        for(auto &x : prerequisites) {
            inn[x[0]]++;
            sum[x[1]][++out[x[1]]] = x[0];
        }
        queue <int> ss;
        for(int i = 0; i < numCourses; i++) {
            if(!inn[i]) ss.push(i);
        }
        if(ss.empty()) return false;
        vector <int> vis;
        while(!ss.empty()) {
            auto k = ss.front();
            ss.pop();
            vis.push_back(k);
            for(int i = 1; i <= out[k]; i++) {
                int u = sum[k][i];
                inn[u]--;
                if(!inn[u]) {
                    ss.push(u);
                }
            }
        }
        return vis.size() == numCourses;
    }
};