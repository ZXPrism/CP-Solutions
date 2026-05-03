class Solution {
public:
	vector<string> divideString(string s, int k, char fill) {
		std::vector<std::string> ans;
		int n = s.size();
		for (int i = 0; i < n; i += k) {
			ans.push_back(s.substr(i, k));
		}
		while (ans.back().size() != k) {
			ans.back().push_back(fill);
		}
		return ans;
	}
};
