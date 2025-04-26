class Solution {
public:
	int longestValidParentheses(string s) {
		int n = s.size();
		int ans = 0;
		int i = 0;
		while (i < n) {
			if (s[i] == ')') {
				++i;
				continue;
			}
			int j = i, pre = 0;
			while (j < n && pre >= 0) {
				if (s[j] == '(') {
					++pre;
				} else {
					--pre;
				}
				if (!pre) {
					ans = std::max(ans, j - i + 1);
				}
				++j;
			}
			i = j;
		}

		i = n - 1;
		while (i >= 0) {
			if (i == '(') {
				--i;
				continue;
			}
			int j = i, pre = 0;
			while (j >= 0 && pre >= 0) {
				if (s[j] == ')') {
					++pre;
				} else {
					--pre;
				}
				if (!pre) {
					ans = std::max(ans, i - j + 1);
				}
				--j;
			}
			i = j;
		}

		return ans;
	}
};
