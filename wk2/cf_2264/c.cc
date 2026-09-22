/*
考虑树其实不知道怎么转移, 因此考虑每条边在所有树上的贡献  

sort 之后, 对于一个点, 它的父亲一定在它右侧,  
锚定边 i -- father -> j, 则其余点仍自由, 每个点有不同的父亲, 则可以构成不同的树, 因此对所有非 i 点的可能父亲情况进行乘算  
times{k in [0, n) | k != i} (n - k - 1), 该值只和 i 有关, 可以表示为 i 的函数  

W(i) = times{k in [0, n) | k != i} (n - k - 1)
该值可以通过处理前缀积和后缀积得到

那么对于一个点 i, 可能贡献的值为  
f(i) = sum{j in [i + 1, n)} (a[j] - a[i]) * W(i)
= W(i) * (sum{j}(a[j] - a[i]))
= W(i) * (sum{j}a[j] - (n - i - 1) * a[i])

因此只需要预处理 a 的后缀和  

总答案为 sum{i in [0, n - 1)} f(i)
*/

#include <bits/stdc++.h>

using i64 = long long;
constexpr i64 MOD = 998'244'353;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    std::sort(a.begin(), a.end());

    std::vector<i64> pw(n), sw(n), w(n);
    for (int i = 0; i < n - 1; ++i) pw[i] = (i ? pw[i - 1] : 1ll) * (n - i - 1) % MOD;
    for (int i = n - 2; i >= 0; --i) sw[i] = (i != n - 2 ? sw[i + 1] : 1ll) * (n - i - 1) % MOD;
    for (int i = 0; i < n - 1; ++i) w[i] = (i ? pw[i - 1] : 1ll) * (i != n - 2 ? sw[i + 1] : 1ll) % MOD;

    std::vector<i64> sa(n);
    for (int i = n - 1; i >= 0; --i) sa[i] = ((i != n - 1 ? sa[i + 1] : 0ll) + a[i]) % MOD;
    i64 ans = 0;

    for (int i = 0; i < n - 1; ++i) ans = (ans + w[i] * (sa[i + 1] - 1ll * (n - i - 1) * a[i] % MOD + MOD) % MOD) % MOD;
    std::cout << ans << '\n';
}

int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int t;
    std::cin >> t;

    while (t--) solve();
}