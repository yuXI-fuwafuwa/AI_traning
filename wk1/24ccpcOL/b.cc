#include <bits/stdc++.h>

using i64 = long long;

i64 get(const std::vector<int>& a)
{
    i64 ans = 0;
    int n = a.size();
    
    for (int l = 0; l < n; ++l)
    {
        int max = a[l], min = a[l];
        for (int r = l; r < n; ++r)
        {
            max = std::max(max, a[r]);
            min = std::min(min, a[r]);
            ans += max - min;
        }
    }

    return ans;
}

i64 fac[1005];
constexpr i64 MOD = 998244353;

int main()
{
    fac[0] = 1;
    for (i64 i = 1; i <= 1000; ++i)
        fac[i] = fac[i - 1] * i % MOD;

    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    std::sort(a.begin(), a.end());

    i64 ans = 1;
    for (int i = 0; i < n; ++i)
        if (a[i] != a[0])
        {
            ans = 2;
            break;
        }

    for (int i = 0, j; i < n; i = j)
    {
        for (j = i; j < n && a[j] == a[i]; ++j) ;
        ans = ans * fac[j - i] % MOD;
    }

    std::cout << get(a) << ' ' << ans << '\n';
}