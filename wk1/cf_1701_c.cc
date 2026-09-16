#include <bits/stdc++.h>

// template<typename T, const int N>
// struct Tarr
// {
//     T v[N] {};
//     int h {};
//     int t[N] {};

//     void clear() { ++h; }
//     T& operator[](size_t i)
//     {
//         if (t[i] == h) return v[i];
//         t[i] = h, v[i] = {};
//         return v[i];
//     }
// };
// Tarr<int, 200'005> cnt;

int cnt[200'005];

void solve()
{
    // cnt.clear();

    int n, m;
    std::cin >> n >> m;

    std::fill(cnt, cnt + n + 5, 0);

    for (int i = 1, x; i <= m; ++i)
        std::cin >> x, ++cnt[x];

    auto check = [&](int x) -> bool
    {
        int64_t rem = 0;
        for (int i = 1; i <= n; ++i)
            if (cnt[i] > x) rem += cnt[i] - x;
        for (int i = 1; i <= n; ++i)
            if (cnt[i] <= x) rem -= (x - cnt[i]) / 2;
        return rem <= 0;
    };

    int l = 1, r = m, res = r;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid)) res = mid, r = mid - 1;
        else l = mid + 1;
    }
    std::cout << res << '\n';
}

int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int t;
    std::cin >> t;

    while (t--) solve();
}

/*
事实证明 Tarr 比 std fill 快 30ms, 几乎是 2/3 时间!!!
*/