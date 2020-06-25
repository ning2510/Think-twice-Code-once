/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int ans = 0;
    unordered_map <int, Employee*> ss;

    void dfs(Employee* x) {
        ans += x->importance;
        for(auto &now : x->subordinates) {
            dfs(ss[now]);
        }
        return ;
    }

    int getImportance(vector<Employee*> employees, int id) {
        for(auto &x : employees) {
            ss[x->id] = x;
        }
        dfs(ss[id]);
        return ans;
    }
};