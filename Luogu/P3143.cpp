void solve() {
    int n = 0, k = 0;
    std::cin >> n >> k;

    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    std::ranges::sort(v);

    std::vector<int> pre_mx(n + 1);
    for (int l = 0, r = 0; r < n; r++) {
        while (v[r] - v[l] > k) {
            ++l;
        }
        pre_mx[r + 1] = std::max(pre_mx[r], r - l + 1);
    }

    std::vector<int> suf_mx(n + 2);
    for (int l = n - 1, r = n - 1; l >= 0; l--) {
        while (v[r] - v[l] > k) {
            --r;
        }
        suf_mx[l + 1] = std::max(suf_mx[l + 2], r - l + 1);
    }

    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans = std::max(ans, pre_mx[i + 1] + suf_mx[i + 2]);
    }

    std::cout << ans << '\n';
}
