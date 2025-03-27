class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        int n = a.size();

        std::vector<int> dp_a((n + 1) / 2 + 1, 1);
        for (int i = (n - 1) / 2; i >= 0; i--) {
            dp_a[i] = dp_a[i + 1] && (a[i] == a[n - 1 - i]);
        }
        std::vector<int> dp_b((n + 1) / 2 + 1, 1);
        for (int i = (n - 1) / 2; i >= 0; i--) {
            dp_b[i] = dp_b[i + 1] && (b[i] == b[n - 1 - i]);
        }

        if (dp_a[0] || dp_b[0]) {
            return true;
        }

        auto check = [&]() -> bool {
            int left = 0, right = n - 1;
            while (left < right) {
                if (a[left] == b[right]) {
                    if (dp_a[left + 1] || dp_b[left + 1]) {
                        return true;
                    }
                    ++left;
                    --right;
                } else {
                    break;
                }
            }
            return false;
        };
        if (check()) {
            return true;
        }
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());
        return check();
    }
};
