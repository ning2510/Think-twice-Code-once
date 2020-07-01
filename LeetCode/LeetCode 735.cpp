class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack <int> ss;
        for(int i = 0; i < asteroids.size(); i++) {
            if(!ss.size()) {
                ss.push(asteroids[i]);
            }
            else {
                int flag = 0;
                int y = asteroids[i];
                while(!ss.empty()) {
                    int x = ss.top();
                    if(x > 0 && y < 0) {
                        if(abs(x) == abs(y)) {
                            flag = 1;
                            ss.pop();
                            break;
                        }
                        else if(abs(x) > abs(y)) {
                            flag = 1;
                            break;
                        }
                        else ss.pop();
                    }
                    else {
                        flag = 1;
                        ss.push(y);
                        break;
                    }
                }
                if(!flag) ss.push(y);
            }
        }
        vector <int> ans;
        while(!ss.empty()) {
            ans.push_back(ss.top());
            ss.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};