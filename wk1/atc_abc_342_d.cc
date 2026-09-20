#include <bits/stdc++.h>

using i64 = long long;

std::vector<int> prime, minp;
void sieve(int n = 2e5)
{
    minp.resize(n + 1);
    for (int i = 2; i <= n; ++i)
    {
        if (!minp[i])
        {
            minp[i] = i;
            prime.push_back(i);
        }
        for (auto j : prime)
        {
            if (j > minp[i] || j > n / i) break;
            minp[i * j] = j;
        }
    }
}
// size = 17984
// sqrt ~ 135

/*
平方数这个意思就是 唯一分解的指数奇偶性相同  
维护一个结构, 动态插入并且查询指数奇偶性的

搞一个 135 层的动态开点树, 然后对于叶节点逐个匹配
*/

bool is_sq(i64 x)
{
    i64 r = std::sqrt(x);
    return r * r == x;
}

constexpr int N = 2e5 * 169;
struct Trie
{
    int ch[N][2], idx = 0;
    std::vector<int> val[N];
    void ins(const std::bitset<135>& b, int v)
    {
        int u = 0;
        for (int i = 0; i < b.size(); ++i)
        {
            int v = b[i];
            if (!ch[u][v]) ch[u][v] = ++idx;
            u = ch[u][v];
        }
        val[u].push_back(v);
    }
    int que(const std::bitset<135>& b, int v)
    {
        int u = 0;
        for (int i = 0; i < b.size(); ++i)
        {
            int v = b[i];
            if (!ch[u][v]) return 0;
            u = ch[u][v];
        }
        int res = 0;
        for (auto x : val[u])
            res += is_sq((i64)x * v);
        return res;
    }
} t;

int main()
{
    sieve();
    // std::cout << prime.size() << '\n';

    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    int cnt0 = 0;
    i64 ans = 0;
    for (int i = 0, x; i < n; ++i)
    {
        std::cin >> x;
        if (x == 0)
        {
            ans += i;
            ++cnt0;
            continue;
        }

        ans += cnt0;
        
        int xx = x;
        std::bitset<135> b;
        for (int u = 0; u < 135; ++u)
            while (xx % prime[u] == 0) 
                xx /= prime[u], b.flip(u);
        ans += t.que(b, x);
        t.ins(b, x);
    }
    std::cout << ans << '\n';
}