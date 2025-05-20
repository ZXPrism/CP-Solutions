class Solution {
public:
	int minDominoRotations(vector<int> &tops, vector<int> &bottoms) {
		int n = tops.size();
		auto Get = [&](const vector<int> &main, const vector<int> &sub) -> int {
			int val = main[0], c1 = 0, c2 = 0;
			for (int i = 0; i < n; i++) {
				if (main[i] == val) {
					if (sub[i] != val) {
						++c1;
					}
				} else {
					if (sub[i] == val) {
						++c2;
					} else {
						return 114514;
					}
				}
			}
			return std::min(c1, c2);
		};
		int x = std::min(Get(tops, bottoms), Get(bottoms, tops));
		return (x == 114514 ? -1 : x);
	}
};
