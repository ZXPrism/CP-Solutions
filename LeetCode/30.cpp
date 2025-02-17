class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        int n = s.size();

        std::unordered_map<std::string_view, int> pattern;
        for (auto &str : words) {
            ++pattern[str];
        }

        std::string_view sv(s);
        std::vector<int> ans;
        int nWords = words.size(), step = words[0].size();
        for (int start = 0; start < step; start++) {
            std::unordered_map<std::string_view, int> cnt;
            int req = nWords;
            for (int i = start, j = 0; i < n; i += step, ++j) {
                auto v = sv.substr(i, step);
                if (++cnt[v] <= pattern[v]) {
                    --req;
                } else {
                    ++req;
                }
                if (j >= nWords - 1) {
                    if (req == 0) {
                        ans.push_back(i - (nWords - 1) * step);
                    }
                    auto v = sv.substr(i - (nWords - 1) * step, step);
                    if (--cnt[v] >= pattern[v]) {
                        --req;
                    } else {
                        ++req;
                    }
                }
            }
        }

        return ans;
    }
};
