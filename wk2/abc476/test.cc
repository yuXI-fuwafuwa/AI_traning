#include <bits/stdc++.h>

using i64 = long long;

/*
x < n < y
n = ix + u;
y = n + u;

n - y = ix - jn
2n = ix + y
n = (ix + y) / 2;
*/

void solve()
{
    i64 x, y;
    std::cin >> x >> y;

    if (x > y) std::cout << x + y << '\n';
    else if (x == y) std::cout << x << '\n';
    else std::cout << (y / x) * x + (y - (y / x) * x) / 2 << '\n';
}

int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int t;
    std::cin >> t;

    while (t--) solve();
}