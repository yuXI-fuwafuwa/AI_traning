#include <bits/stdc++.h>

using i64 = long long;
constexpr i64 MOD = 998244353;

i64 dp[3005][3005];
i64 nd[3005];
i64 tpow[3005];

std::vector<int> prime, minp;
void sieve(int n = 3000)
{
    minp.resize(n + 1);
    for (int i = 2; i <= n; ++i)
    {
        if (!minp[i])
        {
            minp[i] = i;
            prime.push_back(i);
        }
        for (auto j : prime)
        {
            if (j > minp[i] || j > n / i) break;
            minp[i * j] = j;
        }
    }

    for (int i = 2; i <= n; ++i)
    {
        nd[i] = 1;
        int j = i;
        while (j > 1)
        {
            int now = minp[j];
            while (j % now == 0) j /= now;
            nd[i] *= now;
        }
    }

    tpow[0] = 1;
    for (int i = 1; i <= n; ++i)
        tpow[i] = tpow[i - 1] * 2 % MOD;
}

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> cnt(n + 1), sc(n + 1, 0);
    for (int i = 0, x; i < n; ++i)
        std::cin >> x, ++cnt[x];
    for (int x = 1; x <= n; ++x)
        sc[x] = sc[x - 1] + cnt[x];

    for (int i = 1; i <= n; ++i) dp[i][i] = i;
    for (int x = 1; x <= n; ++x) for (int y = x + 1; y <= n; ++y)
    {
        if (x % nd[y] == 0) dp[x][y] = dp[x - 1][y - 1];
        else dp[x][y] = dp[x][y - 1];
    }

    i64 ans = 0;
    for (int x = 1; x <= n; ++x)
    {
        if (cnt[x] == 0) continue;
        i64 cx = tpow[cnt[x]] - 1;
        ans = (ans + (i64)x * cx) % MOD;
        for (int y = x + 1; y <= n; ++y)
        {
            if (cnt[y] == 0) continue;
            i64 cy = tpow[cnt[y]] - 1;
            i64 mid = sc[y - 1] - sc[x];
            ans = (ans + cx * cy % MOD * tpow[mid] % MOD * dp[x][y] % MOD) % MOD;
        }
    }

    std::cout << ans << '\n';
}

int main()
{
    sieve();

    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int t;
    std::cin >> t;

    while (t--) solve();
}
