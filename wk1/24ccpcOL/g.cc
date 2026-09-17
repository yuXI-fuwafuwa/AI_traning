#include <bits/stdc++.h>

#define int long long

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
template <typename T> struct PushRelabel {
    const int inf = 0x3f3f3f3f;
    const T INF = 0x3f3f3f3f3f3f3f3f;
    struct Edge {
        int to, cap, flow, anti;
        Edge(int v = 0, int w = 0, int id = 0) : to(v), cap(w), flow(0), anti(id) {}
    };
    std::vector<std::vector<Edge>> e; 
    std::vector<std::vector<int>> gap;
    std::vector<T> ex; // 超额流
    std::vector<bool> ingap;
    std::vector<int> h;
    int n, gobalcnt, maxH = 0;
    T maxflow = 0;

    PushRelabel(int n) : n(n), e(n + 1), ex(n + 1), gap(n + 1) {}
    void addedge(int u, int v, int w) {
        e[u].push_back({v, w, (int)e[v].size()});
        e[v].push_back({u, 0, (int)e[u].size() - 1});
    }
    void PushEdge(int u, Edge &edge) {
        int v = edge.to, d = std::min(ex[u], 1LL * edge.cap - edge.flow);
        ex[u] -= d;
        ex[v] += d;
        edge.flow += d;
        e[v][edge.anti].flow -= d;
        if (h[v] != inf && d > 0 && ex[v] == d && !ingap[v]) {
            ++gobalcnt;
            gap[h[v]].push_back(v);
            ingap[v] = 1;
        }
    }
    void PushPoint(int u) {
        for (auto k = e[u].begin(); k != e[u].end(); k++) {
            if (h[k->to] + 1 == h[u] && k->cap > k->flow) {
                PushEdge(u, *k);
                if (!ex[u]) break;
            }
        }
        if (!ex[u]) return;
        if (gap[h[u]].empty()) {
            for (int i = h[u] + 1; i <= std::min(maxH, n); i++) {
                for (auto v : gap[i]) {
                    ingap[v] = 0;
                }
                gap[i].clear();
            }
        }
        h[u] = inf;
        for (auto [to, cap, flow, anti] : e[u]) {
            if (cap > flow) {
                h[u] = std::min(h[u], h[to] + 1);
            }
        }
        if (h[u] >= n) return;
        maxH = std::max(maxH, h[u]);
        if (!ingap[u]) {
            gap[h[u]].push_back(u);
            ingap[u] = 1;
        }
    }
    void init(int t, bool f = 1) {
        ingap.assign(n + 1, 0);
        for (int i = 1; i <= maxH; i++) {
            gap[i].clear();
        }
        gobalcnt = 0, maxH = 0;
        std::queue<int> q;
        h.assign(n + 1, inf);
        h[t] = 0, q.push(t);
        while (q.size()) {
            int u = q.front();
            q.pop(), maxH = h[u];
            for (auto &[v, cap, flow, anti] : e[u]) {
                if (h[v] == inf && e[v][anti].cap > e[v][anti].flow) {
                    h[v] = h[u] + 1;
                    q.push(v);
                    if (f) {
                        gap[h[v]].push_back(v);
                        ingap[v] = 1;
                    }
                }
            }
        }
    }
    T work(int s, int t) {
        init(t, 0);
        if (h[s] == inf) return maxflow;
        h[s] = n;
        ex[s] = INF;
        ex[t] = -INF;
        for (auto k = e[s].begin(); k != e[s].end(); k++) {
            PushEdge(s, *k);
        }
        while (maxH > 0) {
            if (gap[maxH].empty()) {
                maxH--;
                continue;
            }
            int u = gap[maxH].back();
            gap[maxH].pop_back();
            ingap[u] = 0;
            PushPoint(u);
            if (gobalcnt >= 10 * n) {
                init(t);
            }
        }
        ex[s] -= INF;
        ex[t] += INF;
        return maxflow = ex[t];
    }
};

#undef int

using i64 = long long;

int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;

    PushRelabel<i64> fst(n + m + 2);
    // 1 => source
    // [2, 2+n-1] => person
    // [2+n, 1+n+m] => food
    // 2+n+m => sink

#define SRC (1)
#define SNK (2 + n + m)

    bool ok = true;
    std::vector<i64> a(n), v(n), w(m);
    std::vector<int> x(m), y(m);
    i64 sum_w = 0;
    for (int i = 0; i < n; ++i)
        std::cin >> a[i] >> v[i], 
        ok &= (a[i] >= v[i]), 
        fst.addedge(SRC, i + 2, a[i] - v[i]);
    for (int i = 0; i < m; ++i)
        std::cin >> x[i] >> y[i] >> w[i], 
        fst.addedge(x[i] + 1, i + 2 + n, INF), 
        fst.addedge(y[i] + 1, i + 2 + n, INF), 
        fst.addedge(i + 2 + n, SNK, w[i]), 
        sum_w += w[i];

    if (not ok)
    {
        std::cout << "NO\n";
        return 0;
    }

    auto fmax = fst.work(SRC, SNK);
    if (fmax != sum_w)
    {
        std::cout << "NO\n";
        return 0;
    }

    std::vector<i64> cost(n + 2);
    PushRelabel<i64> lst(2 + n + m);
    i64 daa = 0;
    for (int u = 1; u <= 2 + n + m; ++u)
    {
        for (auto &ed : fst.e[u])
        {
            i64 r = ed.cap - ed.flow;
            if (r > 0)
                lst.addedge(u, ed.to, r);
            if (u == SRC && ed.cap > 0)
                cost[ed.to] = ed.flow;
        }
    }

    auto delta = lst.work(2, SRC);

    i64 yyq = delta + cost[2];
    for (int u = 1; u <= 2 + n + m; ++u)
    {
        for (auto &ed : lst.e[u])
        {
            i64 r = ed.cap - ed.flow;
            if (u == SRC)
            {
                if (ed.cap > 0) cost[ed.to] += ed.flow;
                else cost[ed.to] -= ed.flow;
            }
        }
    }

    for (int u = 3; u <= 2 + n; ++u)
        if (cost[u] >= yyq) ok = false;

    if (ok) std::cout << "YES\n";
    else std::cout << "NO\n";

#undef SRC
#undef SNK    
}