#include <bits/stdc++.h>

using i64 = long long;
constexpr int MOD = 998244353;

template<const int MOD = MOD>
i64 fpow(i64 a, i64 b)
{
    i64 res = 1 % MOD;
    for (; b; b >>= 1, a = a * a % MOD)
        if (b & 1) res = res * a % MOD;
    return res;
}

template<const int MOD = MOD>
i64 inv(i64 a)
{
    return fpow<MOD>(a, MOD - 2);
}

int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    i64 n, m;
    std::cin >> n >> m;

    i64 maxans = 0;
    int dep = 0;
    for (i64 cnt = 1; dep <= m; cnt *= 26, ++dep)
        if (cnt <= n) maxans = (maxans + cnt) % MOD;
        else break;
    if (m - dep + 1 >= 0) maxans = (maxans + (m - dep + 1) * n % MOD) % MOD;

    std::cout << maxans << ' ';

    i64 e = 1;
    for (int i = 1; i <= m; ++i)
    {
        i64 p = inv(fpow(26, i));
        i64 not_choose = fpow(((1 - p) % MOD + MOD) % MOD, n);
        i64 choose = ((1 - not_choose) % MOD + MOD) % MOD;
        e = (e + choose * fpow(26, i) % MOD) % MOD;
    }
    std::cout << e << '\n';
}