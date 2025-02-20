class TopVotedCandidate {
public:
    std::vector<int> leading;
    std::vector<int> times_copy;

    TopVotedCandidate(vector<int> &persons, vector<int> &times) {
        times_copy.swap(times);
        int n = persons.size(), max_votes = 0;
        std::vector<int> cnt(n);
        for (int i = 0; i < n; i++) {
            if (++cnt[persons[i]] >= max_votes) {
                max_votes = cnt[persons[i]];
                leading.push_back(persons[i]);
            } else {
                leading.push_back(leading.back());
            }
        }
    }

    int q(int t) {
        int x = std::ranges::upper_bound(times_copy, t) - times_copy.begin();
        return leading[x - 1];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
