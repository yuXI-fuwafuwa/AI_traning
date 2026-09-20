#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n, m;
    i64 k, x, y;
    std::cin >> n >> m >> k;
    std::cin >> x >> y;

    std::vector<i64> a(n), b(m);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = 0; i < m; ++i) std::cin >> b[i];

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    std::vector<i64> sa(n, 0);
    for (int i = 0; i < n; ++i)
        sa[i] = (i ? sa[i - 1] : 0) + a[i];

    i64 chg = x + y * k;
    i64 ans = std::upper_bound(sa.begin(), sa.end(), chg) - sa.begin();
    i64 sumtk = 0;
    for (int i = 0; i < m; ++i)
    {
        i64 tk = (b[i] + k - 1) / k;
        if (sumtk + tk > y) break;
        sumtk += tk;
        chg -= k * tk;
        chg += k * tk - b[i];
        ans = std::max<i64>(
            ans, 
            std::upper_bound(sa.begin(), sa.end(), chg) - sa.begin() + i + 1
        );
    }

    std::cout << ans << '\n';
}