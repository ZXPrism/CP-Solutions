class Solution {
public:
    int countCompleteSubstrings(string word, int k) {
        int n = word.size(), ans = 0;
        for (int left = 0; left < n;) {
            int right = left + 1;
            while (right < n && std::abs(word[right - 1] - word[right]) <= 2) {
                ++right;
            }
            int len = right - left;
            for (int i = 1; i <= 26 && k * i <= len; i++) {
                int window = k * i;
                std::vector<int> cnt(26);
                for (int j = left; j < right; j++) {
                    ++cnt[word[j] - 'a'];
                    if (j - left >= window - 1) {
                        bool check = true;
                        for (int m = 0; m < 26; m++) {
                            if (cnt[m] && cnt[m] != k) {
                                check = false;
                                break;
                            }
                        }
                        if (check) {
                            ++ans;
                        }
                        --cnt[word[j - window + 1] - 'a'];
                    }
                }
            }
            left = right;
        }
        return ans;
    }
};
