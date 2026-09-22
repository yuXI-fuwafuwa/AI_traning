/*
m * b[m] - m * b[m - 1] + 
(m - 1) * b[m - 1] - (m - 1) * b[m - 2] + 
...
1 * b[1]
=>

m * b[m] - b[m - 1] - b[m - 2] -... - b[1] 求 max

前 m - 1 个尽可能小, b[m] 尽可能大  

那我动态地维护前面的集合, 以及维护 m - 1 小, 枚举 i 作为 b[m]  
*/

#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    
    std::priority_queue<int> pq; 
    i64 sum = 0;

    for (int i = 0; i < m - 1; ++i)
        pq.emplace(a[i]), 
        sum += a[i];
    
    i64 ans = (i64)m * a[m - 1] - sum;
    for (int i = m - 1; i < n; ++i)
    {
        i64 res = (i64)m * a[i] - sum;
        ans = std::max(res, ans);

        sum += a[i];
        pq.emplace(a[i]);
        sum -= pq.top();
        pq.pop();
    }

    std::cout << ans << '\n';
}

int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int t;
    std::cin >> t;

    while (t--) solve();
}