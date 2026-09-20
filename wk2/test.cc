#include <bits/stdc++.h>

void solve(int n)
{
    std::vector<std::pair<int, int>> ans;

    std::string s;
    std::string sn = std::to_string(n);
    for (int a = 1; a <= 10000; ++a)
    {
        s += sn;
        for (
            int b = std::max(1, (int)s.size() - (int)std::to_string(n * a).size()); 
            b <= std::min({10000, a * n, (int)s.size()}); 
            ++b)
        {
            std::string tmp = s.substr(0, s.size() - b);
            if (a * n - b == std::atoi(tmp.c_str()))
                ans.emplace_back(a, b);
        }
    }

    // std::cout << ans.size() << '\n';
    // for (auto [a, b] : ans)
    //     std::cout << a << ' ' << b << '\n';

    if (ans.size())
    {
        std::cout << "{ " << n << ", \"";
        std::cout << ans.size() << "\\n";
        for (auto [a, b] : ans)
            std::cout << a << ' ' << b << "\\n";
        std::cout << "\" }, \n";
    }
}

int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    for (int i = 1; i <= 100; ++i)
        solve(i);
}