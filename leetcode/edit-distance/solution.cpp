class Solution {

public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        vector<int> table((n + 1) * (m + 1));

        auto dp = [&](int i, int j) -> int& {
            return table[i * (m + 1) + j];
        };


        for (int i = 0 ; i < n ; i++) {
            dp(i,m) = n - i;
        }
        for (int j = 0 ; j < m ; j++) {
            dp(n,j) = m - j;
        }

        for (int i = n-1 ; i >= 0 ; i--) {
            for (int j = m-1 ; j >= 0 ; j--) {
                if (word1[i] == word2[j]) {
                    dp(i,j) = dp(i+1,j+1);
                } else {
                    dp(i,j) = 1 + min({dp(i+1,j), dp(i,j+1), dp(i+1,j+1)});
                }
            }
        }

        return table[0];
    }
};
