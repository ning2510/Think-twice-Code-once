class Solution {
public:
    bool isPathCrossing(string path) {
        int n = path.size();
        set <pair<int, int>> ss;
        int x = 0, y = 0;
        ss.insert({x, y});
        for(int i = 0; i < n; i++) {
            if(path[i] == 'N') {
                y++;
                if(ss.count({x, y})) return true;
                ss.insert({x, y});
            }
            else if(path[i] == 'S') {
                y--;
                if(ss.count({x, y})) return true;
                ss.insert({x, y});
            }
            else if(path[i] == 'E') {
                x++;
                if(ss.count({x, y})) return true;
                ss.insert({x, y});
            }
            else {
                x--;
                if(ss.count({x, y})) return true;
                ss.insert({x, y});
            }
        }
        return false;
    }
};