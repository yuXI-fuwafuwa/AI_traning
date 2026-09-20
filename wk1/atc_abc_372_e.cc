#include <bits/stdc++.h>

template<class... Args> void dbg(Args... args) {
    auto dbg = [&](auto x) { std::cout << x << " "; };
    std::cout << "--->";
    int arr[] = {(dbg(args), 0)...};
    std::cout << "\n";
}

/*
查询第 k 大, 需要用到有序集合, 合并, 使用启发式合并  
set<int> 没有该函数, 不想用 pbds, 考虑手写  
手写 sgt 合并  
*/

struct Node
{
    int ls, rs;
    int sum;
};
int tot = 0;
int rt[300'000];
Node Arena[5'000'000];

int BEG, END;

void pushup(int p)
{
    if (!p) return ;
    Arena[p].sum = Arena[Arena[p].ls].sum + Arena[Arena[p].rs].sum;
}

void ins(int v, int l, int r, int& p)
{
    if (!p) p = ++tot;
    if (l == r - 1)
    {
        ++Arena[p].sum;
        return;
    }
    int mid = (l + r) >> 1;
    if (v < mid) ins(v, l, mid, Arena[p].ls);
    else ins(v, mid, r, Arena[p].rs);
    pushup(p);
}

int merge(int l, int r, int u, int v)
{
    if (!u) return v;
    if (!v) return u;
    if (l == r - 1)
    {
        Arena[u].sum += Arena[v].sum;
        return u;
    }
    int mid = (l + r) >> 1;
    Arena[u].ls = merge(l, mid, Arena[u].ls, Arena[v].ls);
    Arena[u].rs = merge(mid, r, Arena[u].rs, Arena[v].rs);
    pushup(u);
    return u;
}

int quek(int k, int l, int r, int p)
{
    if (l == r - 1)
        return l;
    int mid = (l + r) >> 1;
    if (Arena[Arena[p].rs].sum >= k)
        return quek(k, mid, r, Arena[p].rs);
    return quek(k - Arena[Arena[p].rs].sum, l, mid, Arena[p].ls);
}

struct DSU
{
    int n;
    std::vector<int> fa, p;

    DSU(int n) : n(n)
    {
        p.resize(n + 1 ,1);
        fa.resize(n + 1);
        std::iota(fa.begin(), fa.end(), 0);
    }

    int get(int x)
    {
        while (x != fa[x])
            x = fa[x] = fa[fa[x]];
        return x;
    }
    int sz(int x)
    {
        return p[get(x)];
    }

    void merge(int x, int y)
    {
        x = get(x), y = get(y);
        if (x == y) return;
        if (p[x] < p[y]) std::swap(x, y);
        fa[y] = x, p[x] += p[y];
    }
};

int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n, q;
    std::cin >> n >> q;

    BEG = 1, END = n + 1;
    DSU d(n);

    for (int i = 1; i <= n; ++i)
        ins(i, BEG, END, rt[d.get(i)]);

    // for (int i = 1; i <= n; ++i) dbg(rt[i]);

    for (int i = 0; i < q; ++i)
    {
        int op;
        std::cin >> op;

        if (op == 1)
        {
            int u, v;
            std::cin >> u >> v;
            if (d.get(u) == d.get(v)) continue;
            int r = merge(BEG, END, rt[d.get(u)], rt[d.get(v)]);
            d.merge(u, v);
            rt[d.get(u)] = r;
        }
        else if (op == 2)
        {
            int v, k;
            std::cin >> v >> k;
            if (d.sz(v) < k) std::cout << "-1\n";
            else std::cout << quek(k, BEG, END, rt[d.get(v)]) << '\n';
        }
        else ; // unreachable
    }
}

/*
4 12
1 1 2
2 1 1
2 1 2
2 1 3
1 1 3
1 2 3
1 3 4
2 1 1
2 1 2
2 1 3
2 1 4
2 1 5

4 7
1 1 2
1 2 3
1 3 4
2 4 1
2 4 2
2 4 3
2 4 4
*/