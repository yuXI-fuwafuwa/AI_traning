#include <bits/stdc++.h>

using i64 = long long;
constexpr int N = 105;
constexpr i64 MOD = 998244353;
i64 dp_[N][N], ndp_[N][N];
i64 (*dp)[N] = dp_;
i64 (*ndp)[N] = ndp_;

int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::string s, t;
    std::cin >> s >> t;

    for (int j = 0; j <= t.size(); ++j)
        dp[j][j] = 1;

    for (int i = 0; i < s.size(); ++i)
    {
        std::memset(ndp, 0, sizeof ndp_);
        for (int j = 0; j <= t.size(); ++j)
            ndp[j][j] = 1;

        for (int len = 1; len <= t.size(); ++len)
        for (int l = 0; l <= t.size() - len; ++l)
        {
            int r = l + len;
            // [l, m) m [m+1, r)
            for (int m = l; m < r; ++m)
                if (t[m] == s[i]) ndp[l][r] = (ndp[l][r] + dp[l][m] * dp[m + 1][r] % MOD) % MOD;
            // [l, m) [m, r)
            for (int m = l; m <= r; ++m)
                ndp[l][r] = (ndp[l][r] + dp[l][m] * dp[m][r] % MOD) % MOD;
        };

        std::swap(dp, ndp);
    }

    std::cout << dp[0][t.size()] << '\n';
}