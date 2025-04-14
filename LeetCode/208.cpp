struct TrieNode {
    bool term;
    std::array<int, 26> next;
};

class Trie {
public:
    std::vector<TrieNode> _Data;
    TrieNode $;

    Trie() {
        $.term = false;
        std::fill($.next.begin(), $.next.end(), -1);
        _Data.push_back($);
    }

    int _find(const string &word) {
        int curr = 0, n = word.size();
        for (int i = 0; i < n; i++) {
            if (_Data[curr].next[word[i] - 'a'] == -1) {
                return 0;
            }
            curr = _Data[curr].next[word[i] - 'a'];
        }
        return _Data[curr].term ? 1 : 2;
    }

    void insert(string word) {
        int curr = 0;
        for (auto ch : word) {
            if (_Data[curr].next[ch - 'a'] == -1) {
                _Data[curr].next[ch - 'a'] = _Data.size();
                _Data.push_back($);
            }
            curr = _Data[curr].next[ch - 'a'];
        }
        _Data[curr].term = true;
    }

    bool search(string word) {
        return _find(word) == 1;
    }

    bool startsWith(string prefix) {
        return _find(prefix) > 0;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
