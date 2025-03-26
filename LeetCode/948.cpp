class Solution {
public:
    int bagOfTokensScore(vector<int> &tokens, int power) {
        std::ranges::sort(tokens);
        int n = tokens.size(), ans = 0, score = 0;
        int left = 0, right = n - 1;
        while (left <= right) {
            if (power >= tokens[left]) {
                power -= tokens[left++];
                ++score;
                ans = std::max(ans, score);
            } else if (score) {
                power += tokens[right--];
                --score;
            } else {
                break;
            }
        }
        return ans;
    }
};
