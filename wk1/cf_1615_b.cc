#include <bits/stdc++.h>

int cnt[200'005][20];

void solve()
{
    int l, r;
    std::cin >> l >> r;

    int ans = r - l + 1;
    for (int u = 0; u < 20; ++u)
    {
        int c = cnt[r][u] - cnt[l - 1][u];
        int s = r - l + 1;
        ans = std::min(ans, s - c);
    }

    std::cout << ans << '\n';
}

int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    for (int i = 1; i <= 200'000; ++i)
        for (int u = 0; u < 20; ++u)
            cnt[i][u] += (i >> u) & 1;
    for (int i = 1; i <= 200'000; ++i)
        for (int u = 0; u < 20; ++u)
            cnt[i][u] += cnt[i - 1][u];

    int t;
    std::cin >> t;

    while (t--) solve();
}