// 方法一：BFS (单向) 160ms
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set <string> pp(wordList.begin(), wordList.end());
        queue <pair<string, int>> ss;
        ss.push({beginWord, 1});
        while(!ss.empty()) {
            if(ss.front().first == endWord) return ss.front().second;
            string x = ss.front().first;
            int y = ss.front().second;
            ss.pop();
            for(int i = 0; i < x.size(); i++) {
                char c = x[i];
                for(auto j = 'a'; j <= 'z'; j++) {
                    if(j == c) continue;
                    x[i] = j;
                    if(pp.find(x) != pp.end()) {
                        ss.push({x, y + 1});
                        pp.erase(x);
                    }
                }
                x[i] = c;
            }
        }
        return 0;
    }
};

// 方法二：BFS (双向) 76ms
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set <string> pp(wordList.begin(), wordList.end());
        if(pp.find(endWord) == pp.end()) return 0;
        unordered_set <string> beginset, endset, vis, tmp;
        beginset.insert(beginWord);
        endset.insert(endWord);
        int ans = 1;
        while(!beginset.empty() && !endset.empty()) {
            if(beginset.size() > endset.size()) {
                tmp = beginset;
                beginset = endset;
                endset = tmp;
            }
            tmp.clear();
            for(auto x : beginset) {
                for(int i = 0; i < x.size(); i++) {
                    char c = x[i];
                    for(auto j = 'a'; j <= 'z'; j++) {
                        if(j == c) continue;
                        x[i] = j;
                        if(endset.find(x) != endset.end()) return ans + 1;
                        if(vis.find(x) == vis.end() && pp.find(x) != pp.end()) {
                            vis.insert(x);
                            tmp.insert(x);
                        }
                    }
                    x[i] = c;
                }
            }
            beginset = tmp;
            ans++;
        }
        return 0;
    }
};