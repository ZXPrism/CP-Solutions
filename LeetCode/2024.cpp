class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size(), t = 0, ans = 0;
        for (int left = 0, right = 0; right < n; right++) {
            t += (answerKey[right] == 'T');
            while (left <= right && std::min(t, right - left + 1 - t) > k) {
                t -= (answerKey[left] == 'T');
                ++left;
            }
            ans = std::max(ans, right - left + 1);
        }
        return ans;
    }
};
