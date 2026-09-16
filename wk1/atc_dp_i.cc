#include <bits/stdc++.h>

/*
P(x >= (N + 1) / 2) = 1 - P(x < (N + 1) / 2)
设 dp[i][j] 为前缀 i 中出现了 j 个正面  
dp[i][j] = dp[i - 1][j] * (1 - pi) + dp[i - 1][j - 1] * (pi)
*/

using flt = long double;

int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::vector<flt> a(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];

    std::vector<flt> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = i; j >= 0; --j)
            dp[j] = dp[j] * (1 - a[i]) + (j ? dp[j - 1] : 0) * a[i];
    flt ans = 0;
    for (int i = (n + 1) / 2; i <= n; ++i)
        ans += dp[i];
    std::cout << std::fixed;
    std::cout << std::setprecision(20);
    std::cout << ans << '\n';
}