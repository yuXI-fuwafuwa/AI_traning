#include <bits/stdc++.h>

/*
设 1 个寿司的盘子数量为 u, 2 个为 v, 3 个为 w, n 为盘子总数

E(u, v, w) => 答案, 即 u, v, w 到吃完的期望次数, 它可以由选择了一次的其它状态 + 1 得来
E(u, v, w) = 1 + 
    (n - u - v - w) / n * E(u, v, w) + // 吃了空盘子
    u / n * E(u - 1, v, w) + // 吃了有一个寿司的盘子
    v / n * E(u + 1, v - 1, w) + // 吃了有两个寿司的盘子
    w / n * E(u, v + 1, w - 1)   // 吃了有三个寿司的盘子

移项

(u + v + w) / n E(u, v, w) = 1 + avg
E(u, v, w) = n / (u + v + w) + 
    u / (u + v + w) E(u - 1, v, w) + 
    v / (u + v + w) E(u + 1, v - 1, w) + 
    w / (u + v + w) E(u, v + 1, w - 1)

规定转移方向  
枚举 w, 枚举 v, 枚举 u (0 -> limit)
u 只依赖更小的 u, 之前已经枚举了  
v 只依赖更小的 v, 且更小 v 的所有 u 已经枚举

for w in 0..cnt[3]
    for v in 0..cnt[2] + cnt[3] - w
        for u in 0..n - v - w
            dp[u][v][w] = n / (u + v + w)
            if (u - 1) + dp[u - 1][v][w] * u / (u + v + w)
            if (v - 1) + dp[u + 1][v - 1][w] * v / (u + v + w)
            if (w - 1) + dp[u][v + 1][w - 1] * w / (u + v + w)
*/

using flt = double;
constexpr int MAXN = 305;

int cnt[4];
flt dp[MAXN][MAXN][MAXN];

int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    for (int i = 0, x; i < n; ++i)
        std::cin >> x, ++cnt[x];

    for (int w = 0; w <= cnt[3]; ++w)
        for (int v = 0; v <= cnt[2] + cnt[3] - w; ++v)
            for (int u = 0; u <= n - v - w; ++u)
                if (u + v + w) dp[u][v][w] = n + 
                    (u ? u * dp[u - 1][v][w] : 0) + 
                    (v ? v * dp[u + 1][v - 1][w] : 0) + 
                    (w ? w * dp[u][v + 1][w - 1] : 0), 
                dp[u][v][w] /= (u + v + w);
    std::cout << std::fixed;
    std::cout << std::setprecision(20);
    std::cout << dp[cnt[1]][cnt[2]][cnt[3]] << '\n';
}