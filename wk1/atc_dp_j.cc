#include <bits/stdc++.h>

/*
dp[u][v][w] 表示 1, 2, 3 的个数, sum - u - v - w 表示 0 的个数  

dp[U][V][W] = 0
dp[0][0][0] := Ans

dp[u][v][w] => dp[u - 1][v][w] += sum / (u + v + w)
            => dp[u + 1][v - 1][w] += sum / (u + v + w)
            => dp[u][v + 1][w - 1] += sum / (u + v + w)
*/

using flt = double;

constexpr int MAXN = 305;
flt dp[MAXN][MAXN][MAXN];
int cnt[4];

int to(int u, int v, int w)
{
    return u * MAXN * MAXN + v * MAXN + w;
}
std::tuple<int, int, int> de(int id)
{
    return { id / (MAXN * MAXN), id / MAXN % MAXN, id % MAXN };
}

std::vector<int> g[MAXN * MAXN * MAXN];
int in[MAXN * MAXN * MAXN];
int a[MAXN * MAXN * MAXN];
int tot = 0;

void topo()
{
    std::stack<int> s;
    s.emplace(to(cnt[1], cnt[2], cnt[3]));
    
    while (s.size())
    {
        int cu = s.top();
        s.pop();
        a[tot++] = cu;
        for (auto adj : g[cu])
        {
            --in[adj];
            if (in[adj] == 0) s.emplace(adj);
        }
    }
}

flt p(int u, int v, int w, int x, int y, int z)
{

}

int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    for (int i = 0, x; i < n; ++i)
        std::cin >> x, ++cnt[x];
    cnt[0] = cnt[1] + cnt[2] + cnt[3];

    for (int w = cnt[3]; w >= 0; --w)
    {
        for (int v = cnt[3] + cnt[2] - w; v >= 0; --v)
        {
            for (int u = cnt[0] - v - w; u >= 0; --u)
            {
                int cu = to(u, v, w);
                int nx1 = to(u - 1, v, w);
                int nx2 = to(u, v + 1, w - 1);
                int nx3 = to(u + 1, v - 1, w);
                if (u > 0) g[cu].push_back(nx1), ++in[nx1];
                if (w > 0) g[cu].push_back(nx2), ++in[nx2];
                if (v > 0) g[cu].push_back(nx3), ++in[nx3];
            }
        }
    }

    topo();

    for (int i = 0; i < tot; ++i)
    {
        auto [u, v, w] = de(a[i]);
        flt add = (flt)cnt[0] / (u + v + w) + dp[u][v][w];

        std::cout << u << ' ' << v << ' ' << w << '\n';

        if (u > 0) dp[u - 1][v][w] += add * ();
        if (w > 0) dp[u][v + 1][w - 1] += add;
        if (v > 0) dp[u + 1][v - 1][w] += add;
    }

    std::cout << dp[0][0][0] << '\n';
}