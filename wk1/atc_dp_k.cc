#include <bits/stdc++.h>

struct SG
{
    const std::vector<int>& a;
    std::array<int, 100'005> memo;
    SG(const std::vector<int>& a) : a(a) 
    {
        std::fill(memo.begin(), memo.end(), -1);
    }

    bool sg(int k)
    {
        if (~memo[k]) return memo[k];
        if (k == 0) return memo[k] = false;
        
        bool res = false;
        for (const auto v : a)
            if (k >= v) res |= !sg(k - v);
        return memo[k] = res;
    }
};

int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n, k;
    std::cin >> n >> k;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    SG game(a);

    // for (int i = 0; i <= 5; ++i)
    //     std::cout << game.sg(i) << ' ';
    // std::cout << '\n';

    if (game.sg(k)) std::cout << "First\n";
    else std::cout << "Second\n";
}