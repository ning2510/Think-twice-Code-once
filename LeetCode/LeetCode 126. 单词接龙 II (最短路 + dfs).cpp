class Solution {
public:
    vector <vector<string>> ans;
    vector <vector<int>> fa;
    struct stu {
        int next, to, dis;
    }edge[50005];
    int n, val, num_edge = 0, vis[10005], head[50005];
    string sta;

    void add_edge(int from, int to, int dis) {
        edge[++num_edge].to = to;
        edge[num_edge].dis = dis;
        edge[num_edge].next = head[from];
        head[from] = num_edge;
    }

    vector <string> now;

    void dfs(int s, vector<string>& wordList) {
        if(s == wordList.size() - 1) {
            ans.push_back(now);
            return ;
        }
        for(auto &x : fa[s]) {
            now.push_back(wordList[x]);
            dfs(x, wordList);
            now.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int flag = -1;
        for(int i = 0; i < wordList.size(); i++) {
            if(wordList[i] == endWord) flag = i;
        }
        if(flag == -1) return ans;
        wordList.push_back(beginWord);
        n = wordList.size();
        num_edge = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int sum = 0;
                for(int k = 0; k < wordList[i].size(); k++) {
                    if(wordList[i][k] != wordList[j][k]) {
                        sum++;
                        if(sum > 1) break;
                    }
                }
                if(sum != 1) continue;
                add_edge(i, j, 1);
                add_edge(j, i, 1);
            }
        }
        memset(vis, 0, sizeof(vis));
        queue <int> ss;
        ss.push(n - 1);
        vis[n - 1] = 1;
        int dis[10005];
        memset(dis, 0x3f3f3f, sizeof(dis));
        dis[n - 1] = 0;
        fa.resize(n, vector<int>());
        while(!ss.empty()) {
            int k = ss.front();
            ss.pop();
            vis[k] = 0;
            for(int i = head[k]; i; i = edge[i].next) {
                int v = edge[i].to;
                if(dis[v] >= dis[k] + edge[i].dis) {
                    dis[v] = dis[k] + edge[i].dis;
                    fa[v].push_back(k);
                    if(!vis[v]) {
                        vis[v] = 1;
                        ss.push(v);
                    }
                }
            }
        }
        //val = dis[flag];
        //cout << val << endl;

        now.push_back(wordList[flag]);
        dfs(flag, wordList);
        for(auto &x : ans) {
            reverse(x.begin(), x.end());
        }
        return ans;
    }
};