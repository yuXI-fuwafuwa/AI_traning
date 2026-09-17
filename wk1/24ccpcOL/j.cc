#include <bits/stdc++.h>

constexpr int BASE = 31;
int base[BASE + 1];
bool ins(int val)
{
    for (int i = BASE - 1; i >= 0; --i)
    {
        if ((val >> i) & 1)
        {
            if (!base[i]) 
            {
                base[i] = val;
                return true;
            }
            val ^= base[i];
        }
    }
    return false;
}
void clear()
{
    memset(base, 0, sizeof base);
}

constexpr int N = 1e6 + 5;
int a[N], b[N];

void solve()
{
    clear();

    int n;
    std::cin >> n;

    int xor_a = 0, xor_b = 0;

    for (int i = 0; i < n; ++i) 
        std::cin >> a[i], xor_a ^= a[i];
    for (int i = 0; i < n; ++i) 
        std::cin >> b[i], xor_b ^= b[i];

    for (int i = 0; i < n; ++i)
        ins(a[i] ^ b[i]);

    int ans = std::max(xor_a, xor_b);
    for (int i = BASE - 1; i >= 0; --i)
    {
        int nans = std::max(xor_a ^ base[i], xor_b ^ base[i]);
        if (nans < ans)
            xor_a ^= base[i], xor_b ^= base[i], ans = nans;
    }

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