class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if(start > destination) swap(start, destination);
        int sum = 0, sum1 = 0;
        for(auto &x : distance) {
            sum += x;
        }
        for(int i = start; i < destination; i++) {
            sum1 += distance[i];
        }
        return min(sum1, sum - sum1);
    }
};