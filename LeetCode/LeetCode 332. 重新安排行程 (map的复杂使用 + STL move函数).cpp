// 方法一: map + vector + move
注意对于每一个节点，它只有最多一个「死胡同」分支。依据半欧拉图的描述，只有那个入度与出度差为 1 的节点会导致死胡同。
class Solution {
public:
    vector <string> ans;
    unordered_map <string, vector<string>> ss;

    void dfs(string now) {
        while(ss.count(now) && ss[now].size() > 0) {
            int n = ss[now].size();
            string next = ss[now][n - 1];
            ss[now].pop_back();
            dfs(move(next));    //move:把next值传递后，next值为空（减少内存消耗）
        }
        ans.emplace_back(now);
        return ;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto &x : tickets) {
            ss[x[0]].emplace_back(x[1]);
        }
        for(auto &x : ss) {
            sort(x.second.begin(), x.second.end(), [](const auto &x, const auto &y) {
                return x > y;
            });
        }
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


// 方法二: map + priority_queue + move
class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>> ss;

    vector<string> pp;

    void dfs(const string& curr) {
        while (ss.count(curr) && ss[curr].size() > 0) {
            string tmp = ss[curr].top();
            ss[curr].pop();
            dfs(move(tmp));
        }
        pp.emplace_back(curr);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& it : tickets) {
            ss[it[0]].emplace(it[1]);
        }
        dfs("JFK");

        reverse(pp.begin(), pp.end());
        return pp;
    }
};