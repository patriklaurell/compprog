class Solution {
public:
    string longestPalindrome(string s) {
        vector<int> longest(s.size(), 1);

        int max_len = 1, start = 0, j;
        for (int i = 0 ; i < s.size() ; i++) {
            for (j = 0 ; i-j >= 0 && j+j < s.size() && s[i-j] == s[i+j] ; j++);
            if (max_len < (j-1)*2 + 1) {
                start = i-j + 1;
                max_len = (j-1) * 2 + 1;    
            }
            for (j = 0 ; i-j >= 0 && i+j+1 < s.size() && s[i-j] == s[i+j+1] ; j++);
            if (max_len < j*2) {
                start = i-j + 1;
                max_len = j*2;
            }
        }

        printf("max_len = %i, start = %i, s = %s\n", max_len, start, s.c_str());
        return s.substr(start, max_len);
    }
};
