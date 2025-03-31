class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        std::unordered_map<std::string, std::vector<int>> hashmap;
        int n = strs.size();
        for (int i = 0; i < n; i++) {
            std::string cnt(26, 0);
            for (auto ch : strs[i]) {
                ++cnt[ch - 'a'];
            }
            hashmap[cnt].push_back(i);
        }
        std::vector<std::vector<std::string>> ans;
        for (auto &[_, idx] : hashmap) {
            ans.emplace_back();
            for (auto id : idx) {
                ans.back().push_back(strs[id]);
            }
        }
        return ans;
    }
};
