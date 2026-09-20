#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

std::mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());

std::vector<u64> phash;
std::vector<int> prime, minp;
void sieve(int n = 2e5)
{
    minp.resize(n + 1);
    for (int i = 2; i <= n; ++i)
    {
        if (!minp[i])
        {
            minp[i] = i;
            prime.push_back(i);
            phash.push_back(rng());
        }
        for (auto j : prime)
        {
            if (j > minp[i] || j > n / i) break;
            minp[i * j] = j;
        }
    }
}

int main()
{
    sieve();

    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::map<u64, i64> cnt;
    i64 ans = 0, cnt0 = 0;
    for (int i = 0; i < n; ++i)
    {
        int a;
        std::cin >> a;
        u64 xa = 0;

        if (a == 0)
        {
            ++cnt0;
            ans += i;
            continue;
        }

        ans += cnt0;

        while (a > 1)
        {
            int now = minp[a], cnt = 0;
            while (a % now == 0)
            {
                a /= now;
                ++cnt;
            }
            size_t id = std::lower_bound(prime.begin(), prime.end(), now) - prime.begin();
            if (cnt & 1) xa ^= phash[id];
        }

        ans += cnt[xa];
        ++cnt[xa];
    }

    std::cout << ans << '\n';
}