#include <bits/stdc++.h>

/*
如果存在, 也即 n = a * x + b * y  
其中 x 也满足 n 的条件, 递归展开可以得到 n = a^k + by
其中 y 也任意, 因为总能把 b 都放在最外层  
枚举 a 的幂, 求是否能整除 b

ee, 特判 a = 1
*/

using i64 = long long;

void solve()
{
    int n, a, b;
    std::cin >> n >> a >> b;

    if (a == 1)
    {
        if ((n - 1) % b == 0) std::cout << "yes\n";
        else std::cout << "no\n";
        return ;
    }

    for (i64 r = 1; r <= n; r *= a)
    {
        int by = n - r;
        if (by % b == 0) 
        {
            std::cout << "yes\n";
            return ;
        }
    }
    std::cout << "no\n";
}

int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int t;
    std::cin >> t;

    while (t--) solve();
}