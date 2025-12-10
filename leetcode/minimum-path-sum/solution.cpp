class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> table(n * m);

        auto dp = [&](int i, int j) -> int& {
            return table[i * m + j];
        };

        for (int i = 0 ; i < n ; i++) {
            for (int j = 0; j < m ; j++) {
                if (i-1 < 0 && j-1 < 0) {
                    table[i * m + j] = grid[i][j];
                } else if (i-1 < 0) {
                    table[i * m + j] = grid[i][j] + dp(i,j-1);
                } else if (j-1 < 0) {
                    table[i * m + j] = grid[i][j] + dp(i-1,j);
                } else {
                    table[i * m + j] = grid[i][j] + min(dp(i-1,j), dp(i,j-1));
                }
            }
        }

        return table[table.size()-1];
    }
};
