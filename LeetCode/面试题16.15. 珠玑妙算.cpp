class Solution {
public:
    vector<int> masterMind(string solution, string guess) {
        int a = 0, b = 0;
        unordered_map <int, int> ss;
        for(int i = 0; i < 4; i++) {
            if(solution[i] == guess[i]) a++;
            else ss[guess[i]]++;
        }
        for(int i = 0; i < 4; i++) {
            if(solution[i] != guess[i]) {
                if(ss[solution[i]] > 0) {
                    b++;
                    ss[solution[i]]--;
                }
            }
        }
        return {a, b};
    }
};