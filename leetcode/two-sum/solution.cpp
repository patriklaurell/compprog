#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;  // value -> index

        for (int i : nums) {
          printf("i: %d\n", i);
        }

        return {}; // Required for compilation, though LeetCode guarantees one solution
    }
};

int main() {
    // Example usage:
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = solution.twoSum(nums, target);
    
    // result should be [0, 1]
    printf("Indices: [%d, %d]\n", result[0], result[1]);
    return 0;
}
