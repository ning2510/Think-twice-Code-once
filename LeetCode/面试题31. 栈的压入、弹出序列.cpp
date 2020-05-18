class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack <int> ss;
        int now = 0;
        for(auto x : pushed) {
            ss.push(x);
            while(!ss.empty() && ss.top() == popped[now]) {
                ss.pop();
                now++;
            }
        }
        return now == popped.size();
    }
};