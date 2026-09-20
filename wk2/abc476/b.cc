#include <bits/stdc++.h>

int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::string s, t;
    std::cin >> s >> t;

    bool ok = true;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == t[i] || t[i] == '*') ;
        else ok = false;
    }

    if (ok) std::cout << "Yes\n";
    else std::cout << "No\n";
}