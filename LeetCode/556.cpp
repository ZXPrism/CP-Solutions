class Solution {
public:
	int nextGreaterElement(int n) {
		std::string s = std::to_string(n);
		int len = s.size();
		int i = len - 2;
		while (i >= 0 && s[i] >= s[i + 1]) {
			--i;
		}
		if (i >= 0) {
			int j = len - 1;
			while (s[i] >= s[j]) {
				--j;
			}
			std::swap(s[i], s[j]);
		} else {
			return -1;
		}
		std::reverse(s.begin() + i + 1, s.end());
		long long res = std::stoll(s);
		return (res > std::numeric_limits<int>::max() ? -1 : res);
	}
};
