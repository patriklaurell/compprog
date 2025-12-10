class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> rows(numRows);

        for (int i = 0 ; i < numRows ; i++) {
            vector<int> row(i + 1);
            row[0] = 1;
            row[row.size() - 1] = 1;

            for (int j = 1 ; j < row.size() - 1 ; j++) {
                row[j] = rows[i-1][j-1] + rows[i-1][j];
            }

            rows[i] = row;
        }

        return rows;
    }
};
