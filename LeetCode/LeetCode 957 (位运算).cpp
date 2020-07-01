class Solution {
public:
    int js(vector <int>& cells) {
        int s = 0;
        for(auto x : cells) {
            s <<= 1;
            s |= x;
        }
        return s;
    }

    void next_sta(vector <int>& cells) {
        for(int i = 1; i < cells.size() - 1; i++) {
            cells[i] |= (1 - ((cells[i - 1] & 1) ^ (cells[i + 1] & 1))) << 1;
            //注意这里，为什么要 <<1 ?
            //通过 <<1 可以让二进制中的第一位转换到第二位，然后通过 cells[i]|= 操作将此结果保留在cells[i]二进制的第二位，这样第一位不会被覆盖，当i++进行到下一次计算时，不会被cells[i-1]的值影响，因为我们只需要cells[i-1]和cells[i+1]二进制的第一位去进行计算
        }
        cells[0] = 0;
        cells.back() = 0;
        for(int i = 1; i < cells.size() - 1; i++) {
            cells[i] >>= 1;
        }
    }

    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        unordered_map <int, int> ss;
        int sta = js(cells);
        ss[sta] = 0;
        while(N > 0) {
            N--;
            next_sta(cells);
            sta = js(cells);
            if(ss.count(sta)) break;
            ss[sta] = ss.size();
        }
        int loop = ss.size() - ss[sta];
        N %= loop;
        while(N > 0) {
            N--;
            next_sta(cells);
        }
        return cells;
    }
};