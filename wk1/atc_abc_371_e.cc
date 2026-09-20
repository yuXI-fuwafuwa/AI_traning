#include <bits/stdc++.h>

/*
观察到 x + y 的奇偶性和可达性有关, 奇偶性相同则可达, 不同则不可达 
std::max(x_dis, y_dis) 感觉很是?

那直接分成两组, 每组分别做就好  

P1 和 P2 怎么求距离? 

切比雪夫距离, max(dx, dy) = (abs(dx - dy) + abs(dx + dy)) / 2;
= abs(x1 - x2 - y1 + y2) = abs((x1 - y1) - (x2 - y2))
+ abs(x1 - x2 + y1 - y2) = abs((x1 + y1) - (x2 + y2))
u = x - y, v = x + y;
= abs(u1 - u2) + abs(v1 - v2)

原式 = 全对答案 / 2

所以 sort u, 保证 u 按小到大遍历
然后查前缀 v 的和以及后缀 v 的和, 数量, 进行一个加减法  
最后 / 2
*/

using i64 = long long;

struct Data
{
    i64 u, v;
};

struct Node
{
    int ls, rs;
    int cnt;
    i64 sum;
};
Node sgt[6'000'000];
int tot = 0;
constexpr int BEG = 0, END = 100'000'001;

auto pushup(int p)
{
    sgt[p].sum = sgt[sgt[p].ls].sum + sgt[sgt[p].rs].sum;
    sgt[p].cnt = sgt[sgt[p].ls].cnt + sgt[sgt[p].rs].cnt;
}

auto ins(int v, int l, int r, int& p) -> void
{
    if (!p) p = ++tot;
    if (l == r - 1)
    {
        sgt[p].sum += v, ++sgt[p].cnt;
        return;
    }
    int mid = (l + r) >> 1;
    if (v < mid) ins(v, l, mid, sgt[p].ls);
    else ins(v, mid, r, sgt[p].rs);
    pushup(p);
}

auto que(int x, int y, int l, int r, int p) -> std::pair<int, i64>
{
    if (!p) return {0, 0};
    if (x <= l && r <= y) return {sgt[p].cnt, sgt[p].sum};
    int mid = (l + r) >> 1;
    int c = 0;
    i64 s = 0;
    std::pair<int, i64> res;
    if (x < mid)
        res = que(x, y, l, mid, sgt[p].ls), 
        c += res.first, s += res.second;
    if (y > mid)
        res = que(x, y, mid, r, sgt[p].rs), 
        c += res.first, s += res.second;
    return {c, s};
}

int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::vector<Data> a(n);
    for (int i = 0, x, y; i < n; ++i)
        std::cin >> x >> y, 
        a[i].u = x - y, a[i].v = x + y;

    std::sort(a.begin(), a.end(), [](const Data& lhs, const Data& rhs)
    {
        return lhs.u < rhs.u; 
    });

    i64 ans = 0, su = 0;
    for (int i = 0; i < n; ++i)
    {
        ans += su;



        su += a[i].u;
    }
}