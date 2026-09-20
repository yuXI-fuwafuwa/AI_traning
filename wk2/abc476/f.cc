#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n;
    i64 m;
    std::cin >> n >> m;

    std::vector<i64> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    for (int j = 1; j <= n; ++j) std::cin >> b[j];

    const int U = 2 * n;
    std::vector<i64> pu(U + 1), pv(U + 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            i64 w = a[i] * b[j] % m;
            pu[i + j] += w;
            pv[i - j + n] += w;
        }

    auto prefix = [&](const std::vector<i64> &w)
    {
        int sz = w.size();
        std::vector<i64> sw(sz), tw(sz);
        for (int i = 0; i < sz; ++i)
        {
            sw[i] = (i ? sw[i - 1] : 0) + w[i];
            tw[i] = (i ? tw[i - 1] : 0) + w[i] * i;
        }
        return std::pair{sw, tw};
    };

    auto [su, tu] = prefix(pu);
    auto [sv, tv] = prefix(pv);

    auto cost = [&](int t, const std::vector<i64> &sw, const std::vector<i64> &tw) -> i64
    {
        i64 s_all = sw.back();
        i64 t_all = tw.back();
        return 2 * t * sw[t] - 2 * tw[t] + t_all - t * s_all;
    };

    i64 ans = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            i64 f = (cost(i + j, su, tu) + cost(i - j + n, sv, tv)) / 2;
            ans ^= f + 1ll * (i - 1) * n + (j - 1);
        }

    std::cout << ans << '\n';
}
