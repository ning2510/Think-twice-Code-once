class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack <int> ss;
        if(popped.size() == 0) return true;
        int i = 0, j = 0;
        ss.push(pushed[i++]);
        while(!ss.empty()) {
            while(!ss.empty() && i < pushed.size() && ss.top() != popped[j]) {
                ss.push(pushed[i++]);
            }
            if(i >= popped.size() && ss.top() != popped[j]) return false;
            while(!ss.empty() && ss.top() == popped[j]) {
                ss.pop();
                j++;
            }
            //cout << i << ' ' << j << endl;
            if(ss.empty() && i < pushed.size()) ss.push(pushed[i++]);
        }
        return true;
    }
};