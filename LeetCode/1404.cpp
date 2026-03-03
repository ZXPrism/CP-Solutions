class Solution {
public:
	int numSteps(string s) {
		// flood or ceil?
		// 100100011100
		// eliminate all 0: 1001000111 (2)
		// +1: 1001001000 (1)
		// eliminate all 0: 1001001 (3)
		// +1: 1001010 (1)
		// eliminate all 0: 100101 (1)
		// +1: 100110 (1)
		// eliminate all 0: 10011 (1)
		// +1: 10100 (1)
		// eliminate all 0: 101 (2)
		// +1: 110 (1)
		// eliminate all 0: 11 (1)
		// +1: 100 (1)
		// eliminate all 0: 1 (2)
		// ----
		// since always end with 1, the last +1 op must happens on sth like 1111
		int ans = 0;

		// simulation can solve, but too cumbersome
		// only when current number is 111.111, we need to pay an extra / 2, since carry produces an extra bit
		// and after that, we only need to do / 2 until the number becomes 1
		// so we can know the number of / 2 !
		// but what about +1? +1 is the number of zeros, including the final leading zero
		// but do not include trailing zero !
		int p = s.size() - 1;
		while (p >= 0 && s[p] == '0') {
			++ans;
			--p;
		}

		if (p == 0) {
			return ans;
		}

		++ans;  // leading zero
		ans += p + 1;
		while (p >= 0) {
			if (s[p] == '0') {
				++ans;  // for + 1
			}
			--p;
		}

		return ans;
	}
};
