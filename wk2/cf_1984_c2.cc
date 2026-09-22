// #include <bits/stdc++.h>

// using i64 = long long;

// int main()
// {
//     std::cin.tie(nullptr);
//     std::ios::sync_with_stdio(false);

//     int n;
//     std::cin >> n;

//     std::vector<i64> a(n);
//     for (int i = 0; i < n; ++i)
//         std::cin >> a[i];

//     i64 k = 0;
//     std::vector<int> c(n, 0);
//     std::vector<std::vector<int>> res;
//     auto dfs = [&](auto&& dfs, int i, std::vector<int>& c, i64 acc) -> void
//     {
//         if (i == n)
//         {
//             if (acc > k)
//                 res.clear(), 
//                 res.emplace_back(c), 
//                 k = acc;
//             else if (acc == k)
//                 res.emplace_back(c);
//             return;
//         }
//         c[i] = 1;
//         dfs(dfs, i + 1, c, acc + a[i]);
//         c[i] = 2;
//         dfs(dfs, i + 1, c, std::abs(acc + a[i]));
//     };
//     dfs(dfs, 0, c, 0);

//     std::cout << k << '\n';
//     std::cout << res.size() << '\n';
//     for (const auto& v : res)
//     {
//         for (auto x : v) std::cout << x << ' ';
//         std::cout << '\n';
//     }
// }

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

// 遍历所有从 1..n 中选 k 个的组合，相邻组合只差一个元素。
// 回调参数：
//   a   : 当前组合
//   rem : 相对于上一个组合被移除的元素（第一个组合为 0）
//   add : 相对于上一个组合被加入的元素（第一个组合为 0）
void generate_combinations(int n, int k,
    const std::function<void(const std::vector<int>&, int, int)>& callback) {

    std::vector<int> current;   // 递归中逐渐构建的当前组合
    std::vector<int> prev;      // 上一个完整组合
    bool first = true;

    // 当 current 成为一个完整的 k-子集时调用
    auto emit = [&]() {
        int rem = 0, add = 0;
        if (!first) {
            // 找出 current 中有而 prev 中没有的元素（加入）
            for (int x : current) {
                if (std::find(prev.begin(), prev.end(), x) == prev.end()) {
                    add = x;
                    break;
                }
            }
            // 找出 prev 中有而 current 中没有的元素（移除）
            for (int x : prev) {
                if (std::find(current.begin(), current.end(), x) == current.end()) {
                    rem = x;
                    break;
                }
            }
        }
        callback(current, rem, add);
        prev = current;
        first = false;
    };

    // rev = false 表示正向生成，rev = true 表示反向生成
    std::function<void(int, int, bool)> gen = [&](int n, int k, bool rev) {
        if (k == 0) {
            emit();
            return;
        }
        if (k == n) {
            // 必须全选 1..n
            size_t old_size = current.size();
            for (int i = 1; i <= n; ++i) current.push_back(i);
            emit();
            current.resize(old_size);
            return;
        }

        if (!rev) {
            // 正向：先处理不含 n 的情况，再处理含 n 的情况
            gen(n - 1, k, false);           // 不含 n
            current.push_back(n);           // 加入 n
            gen(n - 1, k - 1, true);        // 含 n，从 1..n-1 中选 k-1 个（反向）
            current.pop_back();             // 移除 n
        } else {
            // 反向：先处理含 n 的情况，再处理不含 n 的情况
            current.push_back(n);           // 加入 n
            gen(n - 1, k - 1, false);       // 含 n，从 1..n-1 中选 k-1 个（正向）
            current.pop_back();             // 移除 n
            gen(n - 1, k, true);            // 不含 n（反向）
        }
    };

    gen(n, k, false);
}

using i64 = long long;

// 示例用法
int main() {
    // int n = 5, k = 3;
    int n, k;
    std::cin >> n >> k;

    std::vector<i64> a(n + 1);
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];

    i64 sum = 0;

    // std::cout << "组合序列及变化 (当前组合, 移除, 加入):\n";
    generate_combinations(n, k,
        [](const std::vector<int>& a, int rem, int add) {
            // std::cout << "{ ";
            // for (int x : a) std::cout << x << " ";
            // std::cout << "}";
            if (rem != 0 || add != 0) {
                // std::cout << "  (移除 " << rem << ", 加入 " << add << ")";
            } else {
                // std::cout << "  (初始组合)";
            }
            std::cout << "\n";
        });
}