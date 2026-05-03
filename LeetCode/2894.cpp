class Solution {
public:
	int differenceOfSums(int n, int m) {
		int cnt = n / m;
		return (1 + n) * n / 2 - (m + cnt * m) * cnt;
	}
};
