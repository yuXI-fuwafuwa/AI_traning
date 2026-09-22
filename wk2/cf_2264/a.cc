#include <bits/stdc++.h>

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n), p;
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    for (int i = 0; i < n; ++i)
        if (a[i] != i + 1) p.push_back(i);
    
    for (int i = 0; i < p.size() / 2; ++i)
        std::swap(a[p[i]], a[p[p.size() - i - 1]]);

    bool ok = true;
    for (int i = 0; i < n && ok; ++i)
        if (a[i] != i + 1) ok = false;
    
    if (ok) std::cout << "YES\n";
    else std::cout << "NO\n";

    // for (int i = 0; i < n; ++i)
    //     std::cout << a[i] << ' ';
    // std::cout << '\n';
}

int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int t;
    std::cin >> t;

    while (t--) solve();
}