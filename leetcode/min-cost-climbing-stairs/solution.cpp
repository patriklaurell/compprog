class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int c1 = cost[cost.size()-1];
        int c = cost[cost.size()-2];

        int tmp;
        for (int i = cost.size()-3 ; i >= 0 ; i--) {
            tmp = cost[i] + min(c, c1);
            c1 = c;
            c = tmp;
        }

        return min(c, c1);
    }
};
