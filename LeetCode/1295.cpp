class Solution {
public:
	int findNumbers(vector<int> &nums) {
		int ans = 0;
		for (auto elem : nums) {
			auto x = std::to_string(elem);
			if (x.size() % 2 == 0) {
				++ans;
			}
		}
		return ans;
	}
};
