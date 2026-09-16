#include <bits/stdc++.h>

void solve()
{
    int a, b;
    std::cin >> a >> b;

    int ores = 0;
    int aa = a, bb = b;

    if (b == 1) ++bb, ++ores;
    while (aa) aa /= bb, ++ores;

    int ans = ores;
    for (int b_add = 1; b_add <= ores; ++b_add)
    {
        int cres = b_add;
        int bb = b + b_add;
        int aa = a;
        while (aa) aa /= bb, ++cres;
        ans = std::min(ans, cres);
    }

    std::cout << ans << '\n';
}

int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int t;
    std::cin >> t;

    while (t--) solve();
}