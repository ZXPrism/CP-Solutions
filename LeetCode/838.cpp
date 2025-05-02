class Solution {
public:
	string pushDominoes(string dominoes) {
		dominoes.push_back('R');

		int n = dominoes.size(), prev = -1;
		for (int i = 0; i < n; i++) {
			if (dominoes[i] != '.') {
				if (prev == -1) {
					if (dominoes[i] == 'L') {
						for (int j = 0; j < i; j++) {
							dominoes[j] = 'L';
						}
					}
				} else {
					if (dominoes[i] == 'L') {
						if (dominoes[prev] == 'L') {
							for (int j = prev + 1; j < i; j++) {
								dominoes[j] = 'L';
							}
						} else {
							int left = prev + 1, right = i - 1;
							while (left < right) {
								dominoes[left++] = 'R';
								dominoes[right--] = 'L';
							}
						}
					} else {
						if (dominoes[prev] == 'R') {
							for (int j = prev + 1; j < i; j++) {
								dominoes[j] = 'R';
							}
						}
					}
				}
				prev = i;
			}
		}
		dominoes.pop_back();

		return dominoes;
	}
};
