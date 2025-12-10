class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int longest_j = 0;
        int longest_prefix = 0;
        for (int i = 0 ; i < 200 ; i++) {
            if (i > strs[longest_j].size()) {
                while(longest_j + 1 < strs.size() && strs[++longest_j].size() > i);
                if (i > strs[longest_j].size()) {
                    break;
                }
            }

            for (int j = 0; j < strs.size() ; j++) {
                if (strs[j].size() == 0) {
                    return "";
                }
                if (i >= strs[j].size() || strs[j][i] != strs[0][i]) {
                    return strs[longest_j].substr(0, longest_prefix);
                }
            }
            
            if (strs[longest_j].size() > 0) {
                longest_prefix++;
            }
            
        }
        return strs[longest_j].substr(0, longest_prefix);
    }
};
