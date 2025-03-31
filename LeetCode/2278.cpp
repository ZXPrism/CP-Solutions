class Solution {
public:
    int percentageLetter(string s, char letter) {
        int n = s.size();
        int cnt = 0;
        for (auto ch : s) {
            cnt += ch == letter;
        }
        return cnt * 100.0 / n;
    }
};
