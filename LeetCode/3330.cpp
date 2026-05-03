class Solution {
public:
	int possibleStringCount(string word) {
		int left = 0, n = word.size(), ans = 1;
		while (left < n) {
			int right = left + 1;
			while (right < n && word[left] == word[right]) {
				++right;
			}
			ans += right - left - 1;
			left = right;
		}
		return ans;
	}
};
