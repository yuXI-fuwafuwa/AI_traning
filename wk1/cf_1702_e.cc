#include <bits/stdc++.h>

void solve()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>>
    g (n, std::vector<int>{});
    std::vector<int> cnt(n, 0);
    bool ok = true;

    for (int i = 0; i < n; ++i)
    {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
        ++cnt[u], ++cnt[v];
        if (u == v) ok = false;
    }

    for (int i = 0; i < n && ok; ++i)
        if (cnt[i] != 2) ok = false;

    std::vector<int> clr(n, -1);

    auto dfs = [&](auto&& dfs, int cur, int fa, int c) -> void
    {
        if (!ok) return;
        if (clr[cur] != -1) 
        {
            if (clr[cur] != c) ok = false;
            return;
        }
        clr[cur] = c;
        for (auto adj : g[cur])
        {
            if (adj == fa) continue;
            dfs(dfs, adj, cur, c ^ 1);
        }
    };
    for (int i = 0; i < n && ok; ++i)
        if (clr[i] == -1) dfs(dfs, i, -1, 0);
    
    // for (int i = 0; i < n; ++i)
    //     std::cout << clr[i] << ' ';
    // std::cout << '\n';

    if (ok) std::cout << "YES\n";
    else std::cout << "NO\n";
}

int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int t;
    std::cin >> t;

    while (t--) solve();
}