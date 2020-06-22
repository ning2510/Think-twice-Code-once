class Solution {
public:
    bool patternMatching(string pattern, string value) {
        int count_a = 0, count_b = 0;
        for(auto &x : pattern) {
            if(x == 'a') count_a++;
            else count_b++;
        }
        if(count_a < count_b) {
            swap(count_a, count_b);
            for(auto &x : pattern) {
                if(x == 'a') x = 'b';
                else x = 'a';
            }
        }
        if(!value.size()) return count_b == 0;
        if(!pattern.size()) return false;
        for(int len_a = 0; len_a * count_a <= value.size(); len_a++) {
            int rest = value.size() - len_a * count_a;
            if((count_b == 0 && rest == 0) || (count_b != 0 && rest % count_b == 0)) {
                int pos = 0, flag = 1, len_b = (count_b == 0 ? 0 : rest / count_b);
                string value_a, value_b;
                for(auto &x : pattern) {
                    if(x == 'a') {
                        string t = value.substr(pos, len_a);
                        if(!value_a.size()) {
                            value_a = t;
                        }
                        else if(value_a != t) {
                            flag = 0;
                            break;
                        }
                        pos += len_a;
                    }
                    else {
                        string t = value.substr(pos, len_b);
                        if(!value_b.size()) {
                            value_b = t;
                        }
                        else if(value_b != t) {
                            flag = 0;
                            break;
                        }
                        pos += len_b;
                    }
                }
                if(flag && value_a != value_b) return true;
            }
        }
        return false;
    }
};