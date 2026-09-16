#include <bits/stdc++.h>

int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> grid(n);
    for (int i = 0; i < n; ++i)
        std::cin >> grid[i];
    int ans = 0;
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < m - 1; ++j)
            if (grid[i][j] == 'c' && grid[i + 1][j] == 'p' && grid[i][j + 1] == 'c' && grid[i + 1][j + 1] == 'c')
                ++ans;
    std::cout << ans << '\n';
}