class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        while (--n) {
            string ns;
            int i = 0;
            int count = 1;
            while (i < s.size()) {
                if (i + 1 < s.size() && s[i] == s[i + 1]) {
                    ++count;
                } else {
                    ns += to_string(count) + s[i];
                    count = 1;
                }
                ++i;
            }
            s = ns;
        }
        return s;
    }
};
