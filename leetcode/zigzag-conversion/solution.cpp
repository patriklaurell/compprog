class Solution {
public:
    string convert(string s, int numRows) {
        string out;
        out.reserve(s.size());

        if (numRows <= 1) {
            return s;
        }

        for (int i = 0 ; i < s.size() ; i += (numRows-1)*2) {
            out += s[i];
        }

        for (int i = 1; i < numRows - 1 ; i++) {
            int steps[2] = {(numRows-(i+1))*2, i*2};
            for (int j = 0, ind = i ; ind < s.size() ; ind += steps[(j++) % 2]) {
                out += s[ind];
            }
        }
        
        for (int i = numRows-1 ; i < s.size() ; i += (numRows-1)*2) {
            out += s[i];
        }

        return out;
    }
};
