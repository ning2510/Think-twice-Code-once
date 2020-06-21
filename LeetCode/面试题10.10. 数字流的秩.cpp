class StreamRank {
public:
    int n = 50000, m = 0;
    vector <int> c;

    int lowbit(int x) {
        return x & (-x);
    }

    void update(int i, int x) {
        while(i <= n) {
            c[i] += x;
            i += lowbit(i);
        }
    }

    int get_sum(int i) {
        int ans = 0;
        while(i > 0) {
            ans += c[i];
            i -= lowbit(i);
        }
        return ans;
    }

    StreamRank() {
        c.resize(50005, 0);
    }
    
    void track(int x) {
        if(!x) m++;
        else update(x, 1);
    }
    
    int getRankOfNumber(int x) {
        if(!x) return m;
        else return m + get_sum(x);
    }
};

/**
 * Your StreamRank object will be instantiated and called as such:
 * StreamRank* obj = new StreamRank();
 * obj->track(x);
 * int param_2 = obj->getRankOfNumber(x);
 */