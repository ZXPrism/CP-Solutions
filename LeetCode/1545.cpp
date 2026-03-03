class Solution {
public:
	char findKthBit(int n, int k) {
		--k;
		int inv = 0;
		while (n != 1) {
			int len = (1 << n) - 1;
			if (k == len / 2) {
				return (inv ^ 1) + '0';
			}
			if (k > len / 2) {
				k = len - 1 - k;
				inv ^= 1;
			}
			--n;
		}
		return inv + '0';
	}
};
