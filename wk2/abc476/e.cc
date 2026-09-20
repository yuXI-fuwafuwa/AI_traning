#include <bits/stdc++.h>

struct Node
{
    int maxv, minv;
    int maxp, minp;
};

constexpr int N = 200'000;
Node sgt[(N + 5) << 2];

#define lson (p << 1)
#define rson (p << 1 | 1)

Node merge(const Node& lhs, const Node& rhs)
{
    Node res;
    if (lhs.maxv > rhs.maxv)
        res.maxv = lhs.maxv, res.maxp = lhs.maxp;
    else 
        res.maxv = rhs.maxv, res.maxp = rhs.maxp;
    if (lhs.minv < rhs.minv)
        res.minv = lhs.minv, res.minp = lhs.minp;
    else 
        res.minv = rhs.minv, res.minp = rhs.minp;
    return res;
}

void build(int l, int r, int p, const std::vector<int>& a)
{
    if (l == r - 1)
    {
        sgt[p] = { a[l], a[l], l, l };
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, lson, a);
    build(mid, r, rson, a);
    sgt[p] = merge(sgt[lson], sgt[rson]);
}

void ins(int x, int v, int l, int r, int p)
{
    if (l == r - 1)
    {
        sgt[p] = { v, v, l, l };
        return;
    }
    int mid = (l + r) >> 1;
    if (x < mid) ins(x, v, l, mid, lson);
    else ins(x, v, mid, r, rson);
    sgt[p] = merge(sgt[lson], sgt[rson]);
}

Node que(int x, int y, int l, int r, int p)
{
    if (x <= l && r <= y) return sgt[p];
    int mid = (l + r) >> 1;
    if (y <= mid) return que(x, y, l, mid, lson);
    if (x >= mid) return que(x, y, mid, r, rson);
    return merge(que(x, y, l, mid, lson), que(x, y, mid, r, rson));
}

#undef lson
#undef rson

int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;

    const int beg = 1, end = n + 1, rt = 1;

    std::vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i)
        std::cin >> p[i];
    build(beg, end, rt, p);

    for (int _ = 0; _ < m; ++_)
    {
        int l, r;
        std::cin >> l >> r;

        auto [maxv, minv, maxp, minp] = que(l, r + 1, beg, end, rt);
        std::swap(p[minp], p[maxp]);
        ins(minp, p[minp], beg, end, rt);
        ins(maxp, p[maxp], beg, end, rt);
    }

    for (int i = 1; i <= n; ++i)
        std::cout
            << que(i, i + 1, beg, end, rt).maxv
            << ' ';
    std::cout << '\n';
}