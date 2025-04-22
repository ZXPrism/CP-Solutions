class Solution {
public:
	vector<int> partitionLabels(string s) {
		int n = s.size();
		std::vector<int> max_pos(26);
		for (int i = 0; i < n; i++) {
			max_pos[s[i] - 'a'] = i;
		}
		std::vector<int> ans;
		int i = 0;
		while (i < n) {
			int j = i + 1, target = max_pos[s[i] - 'a'];
			while (j <= target) {
				target = std::max(target, max_pos[s[j] - 'a']);
				++j;
			}
			ans.push_back(j - i);
			i = j;
		}
		return ans;
	}
};
