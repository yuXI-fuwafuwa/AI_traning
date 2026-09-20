#include <bits/stdc++.h>

std::vector<std::pair<int, int>> find_answers(int n)
{
    std::vector<std::pair<int, int>> answers;
    const std::string sn = std::to_string(n);
    std::string repeated;

    for (int a = 1; a <= 10000; ++a)
    {
        repeated += sn;
        const int length = static_cast<int>(repeated.size());
        const int answer_digits = static_cast<int>(std::to_string(a * n).size());
        const int first_b = std::max(1, length - answer_digits);
        const int last_b = std::min({10000, a * n, length - 1});

        for (int b = first_b; b <= last_b; ++b)
        {
            const std::string remaining = repeated.substr(0, length - b);
            int value = 0;
            for (char digit : remaining)
                value = value * 10 + (digit - '0');

            if (value == a * n - b)
                answers.emplace_back(a, b);
        }
    }
    return answers;
}

int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        std::cin >> n;
        const auto answers = find_answers(n);
        std::cout << answers.size() << '\n';
        for (const auto [a, b] : answers)
            std::cout << a << ' ' << b << '\n';
    }
}
