class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> map(26, 0);

        if (s.length() != t.length()) {
            return false;
        }

        for (int i = 0 ; i < s.length() ; i++) {
            map[s[i]-97]++;
            map[t[i]-97]--;
        }

        for (int i = 0 ; i < map.size() ; i++) {
            if (map[i] != 0) {
                return false;
            }
        }

        return true;
    }
};
