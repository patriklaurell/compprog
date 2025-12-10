#include <vector>

using namespace std;

class Solution {
private:
    vector<int> num_ways;

public:
    int climbStairs(int n) {
        num_ways.assign(n + 1, -1);

        return climb(n);
    }

    int climb(int n) {
        if (n == 2) {
            return 2;
        } else if (n == 1) {
            return 1;
        }

        if (num_ways[n] != -1) {
            return num_ways[n];
        } else {
            int val = climb(n - 1) + climb(n - 2);
            num_ways[n] = val;
            return val;
        }
    }
};

int main() {
    Solution solution;
    int n = 5; // Example input
    int result = solution.climbStairs(n);
    return 0;
}
