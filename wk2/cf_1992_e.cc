#include <bits/stdc++.h>

const std::unordered_map<int, std::string> ans
{
    { 2, "3\n20 18\n219 216\n2218 2214\n" }, 
    { 3, "1\n165 162\n" }, 
    { 4, "3\n14 12\n147 144\n1480 1476\n" }, 
    { 5, "1\n138 135\n" }, 
    { 7, "1\n129 126\n" }, 
    { 10, "1\n1262 2519\n" }, 
    { 11, "3\n12 21\n123 242\n1234 2463\n" }, 
    { 13, "1\n119 234\n" }, 
    { 14, "1\n1178 2351\n" }, 
    { 16, "1\n1154 2303\n" }, 
    { 18, "1\n1136 2267\n" }, 
    { 20, "1\n112 220\n" }, 
    { 21, "1\n11 19\n" }, 
    { 24, "1\n110 216\n" }, 
    { 35, "1\n107 210\n" }, 
    { 68, "1\n104 204\n" }, 
    { 90, "1\n1033 2061\n" }, 
    { 94, "1\n1032 2059\n" }, 
};

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
            b <= std::min({10000, a * n, (int)s.size() - 1}); 
            ++b)
        {
            std::string tmp = s.substr(0, s.size() - b);
            if (a * n - b == std::atoi(tmp.c_str()))
                ans.emplace_back(a, b);
        }
    }

    std::cout << ans.size() << '\n';
    for (auto [a, b] : ans)
        std::cout << a << ' ' << b << '\n';

    // if (ans.size())
    // {
    //     std::cout << "{ " << n << ", \"";
    //     std::cout << ans.size() << "\\n";
    //     for (auto [a, b] : ans)
    //         std::cout << a << ' ' << b << "\\n";
    //     std::cout << "\" }, \n";
    // }
}

void solve()
{
    int n;
    std::cin >> n;

    if (n == 1) solve(1);
    else if (ans.count(n)) 
        std::cout << ans.at(n);
    else 
        std::cout << "0\n";
}

int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int t;
    std::cin >> t;

    while (t--) solve();
}