class Solution {
public:
    char nextGreatestLetter(vector<char> &letters, char target) {
        int x = std::ranges::upper_bound(letters, target) - letters.begin();
        return (x == letters.size() ? letters.front() : letters[x]);
    }
};
