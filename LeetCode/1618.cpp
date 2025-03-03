/**
 * // This is the FontInfo's API interface.
 * // You should not implement it, or speculate about its implementation
 * class FontInfo {
 *   public:
 *     // Return the width of char ch when fontSize is used.
 *     int getWidth(int fontSize, char ch);
 *
 *     // Return Height of any char when fontSize is used.
 *     int getHeight(int fontSize)
 * };
 */
class Solution {
public:
    int maxFont(string text, int w, int h, vector<int> &fonts, FontInfo fontInfo) {
        int n = fonts.size();
        auto check = [&](int sz) -> bool {
            long long tot_w = 0, tot_h = fontInfo.getHeight(sz);
            for (auto ch : text) {
                tot_w += fontInfo.getWidth(sz, ch);
            }
            return tot_w <= w && tot_h <= h;
        };
        int left = -1, right = n, mid = 0;
        while (left + 1 < right) {
            mid = (left + right) / 2;
            if (check(fonts[mid])) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return (left == -1 ? -1 : fonts[left]);
    }
};
