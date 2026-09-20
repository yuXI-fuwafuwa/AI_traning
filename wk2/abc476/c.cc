#include <bits/stdc++.h>

int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::priority_queue<int, std::vector<int>, std::greater<>> pq;
    int ans;

    for (int i = 0, x; i < n; ++i)
    {
        std::cin >> x;
        pq.emplace(x);

        if (pq.size() > 2)
        {
            ans = std::max(ans, pq.top());
            pq.pop();
        }

        if (i >= 2)
            std::cout << ans << '\n';
    }
}