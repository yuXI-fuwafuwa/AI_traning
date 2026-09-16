#include <bits/stdc++.h>

struct SG
{
    using K = std::pair<int, int>;
    
    int k;
    std::map<K, int> memo;
    SG(int k) : k(k) {}
    
    bool sg(int x, int g)
    {
        if (memo.count(K{x, g})) return memo[K{x, g}];
        if (x == 0) return memo[K{x, g}] = false;
        
        bool res = false;
        for (int i = 1; i <= k; ++i)
            if (g % i == 0 && x >= i) res |= !sg(x - i, std::gcd(g, i));
        return memo[K{x, g}] = res;
    }
};



int hbit(int x)
{
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return x - (x >> 1);
}

bool solve(int n, int k)
{
    if (n & 1 || n <= k)
    {
        // std::cout << "Alice\n";
        return true;
    }

    if (n % (hbit(k) * 2) == 0) return false;
    return true;
}

int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n, k;
    std::cin >> n >> k;

    SG game(k);

    for (int i = 0; i <= n; ++i)
        std::cout << game.sg(i, 0) << ' ';
    std::cout << '\n';

    for (int i = 0; i <= n; ++i)
        std::cout << solve(i, k) << ' ';
    std::cout << '\n';
}