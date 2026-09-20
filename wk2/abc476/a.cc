#include <bits/stdc++.h>

int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    std::cout << s;
    if (s.back() == 'e') std::cout << 'r';
    else std::cout << "er";

    std::cout << '\n';
}