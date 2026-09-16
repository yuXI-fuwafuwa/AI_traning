#include <bits/stdc++.h>

/*
    区间 dp
    dp[i][j] = [i, j] 的最终 X - Y
*/

using i64 = long long;
constexpr i64 INF = (i64)1e18;

int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    i64 sum = 0;
    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i], sum += a[i];

    std::vector dp(n, std::vector<i64>(n));

    for (int len = 1; len <= n; ++len)
        for (int i = 0; i + len - 1 < n; ++i)
    {
        int j = i + len - 1;
        if (i == j) dp[i][j] = a[i];
        else dp[i][j] = std::max((i + 1 < n ? (-dp[i + 1][j] + a[i]) : -INF), (j - 1 >= 0 ? (-dp[i][j - 1] + a[j]) : -INF));
    }

    std::cout << dp[0][n - 1] << '\n';
}