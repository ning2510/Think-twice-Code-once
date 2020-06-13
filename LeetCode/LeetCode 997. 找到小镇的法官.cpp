// 方法一：链式前向星建图  660ms
class Solution {
public:
    struct stu {
        int to, next;
    }edge[50005];

    int num_edge = 0, head[1005];

    void add_edge(int from, int to) {
        edge[++num_edge].to = to;
        edge[num_edge].next = head[from];
        head[from] = num_edge;
    }

    int findJudge(int N, vector<vector<int>>& trust) {
        num_edge = 0;
        if(N == 1) return 1;
        for(int i = 0; i < trust.size(); i++) {
            add_edge(trust[i][0], trust[i][1]);
        }
        unordered_map <int, int> ss;
        int x = -1;
        for(int u = 1; u <= N; u++) {
            for(int i = head[u]; i; i = edge[i].next) {
                int v = edge[i].to;
                ss[v]++;
                if(ss[v] == N - 1) x = v;
            }
        }
        if(x == -1) return -1;
        if(head[x]) return -1;
        return x;
    }
};

// 方法二：入度和出度    432ms
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector <int> sum(N + 1, 0);
        for(auto &x : trust) {
            sum[x[0]]--;
            sum[x[1]]++;
        }
        for(int i = 1; i <= N; i++) {
            if(sum[i] == N - 1) return i;
        }
        return -1;
    }
};