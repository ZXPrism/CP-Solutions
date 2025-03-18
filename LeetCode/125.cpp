class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (!std::isalnum(s[left])) {
                ++left;
            } else if (!std::isalnum(s[right])) {
                --right;
            } else if ((s[left] | 32) == (s[right] | 32)) {
                ++left;
                --right;
            } else {
                return false;
            }
        }
        return true;
    }
};
