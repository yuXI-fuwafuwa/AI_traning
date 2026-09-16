#include <bits/stdc++.h>

int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n, t;
    std::cin >> n >> t;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    int sum = 0, ans = 0;
    for (int i = 0, j = 0; i < n; ++i)
    {
        for (; j < n; ++j)
            if (sum + a[j] <= t) sum += a[j];
            else break;
        ans = std::max(ans, j - i);
        sum -= a[i];
    }

    std::cout << ans << '\n';
}