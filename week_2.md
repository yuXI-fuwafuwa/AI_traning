# Week 2：观察、构造、式子与概率

## 训练依据

第一周的 `wp.md` 显示：基础 DP、二分、二分图和一般数据结构题进入状态很快；DP J 的后向期望建模是第一次明显卡点。2026 CCPC Online 存档中可以看到你完成了 B、C、E、H、I、K、M、N 这一组题，覆盖构造、几何、哈希、期望最短路和组合计数；D、J 的正确实现不在本机，因此不把它们作为你的个人失分样本。

第二周不安排第一周未完成题。选题以 2024--2025 正式比赛为主，历史题的难度按“相对 2026 rating 下调约 200”校准。每天 480 分钟，题目后的时间是硬上限。链接行只列题目和时间，不附解法提示。

每题记录：`结果（AC/看提示/看题解）| 首次可写时间 | 首次提交时间 | WA 次数 | 卡点类型`。卡点类型只从 `观察、建模、证明、实现、边界、调试` 中选择。

## Day 1

主题：思维题与性质题。总计 480 分钟。

- [CF 1984C2 - Magnitude (Hard Version)](https://codeforces.com/problemset/problem/1984/C2)（75 分钟）
- [AtCoder ABC386 E - Maximize XOR](https://atcoder.jp/contests/abc386/tasks/abc386_e)（90 分钟）
- [CF 1992E - Novice's Mistake](https://codeforces.com/problemset/problem/1992/E)（65 分钟）
- [AtCoder ABC363 F - Palindromic Expression](https://atcoder.jp/contests/abc363/tasks/abc363_f)（125 分钟）
- [AtCoder ABC373 E - How to Win the Election](https://atcoder.jp/contests/abc373/tasks/abc373_e)（100 分钟）
- 记录与重写（25 分钟）

## Day 2

主题：构造与式子。总计 480 分钟。

- [CF 2020C - Bitwise Balancing](https://codeforces.com/problemset/problem/2020/C)（70 分钟）
- [AtCoder ABC365 E - Xor All](https://atcoder.jp/contests/abc365/tasks/abc365_e)（70 分钟）
- [AtCoder ABC358 F - Easiest Maze](https://atcoder.jp/contests/abc358/tasks/abc358_f)（110 分钟）
- [AtCoder ABC348 F - Oddly Similar](https://atcoder.jp/contests/abc348/tasks/abc348_f)（90 分钟）
- [AtCoder ABC353 D - Another Sigma Problem](https://atcoder.jp/contests/abc353/tasks/abc353_d)（90 分钟）
- 记录与重写（50 分钟）

## Day 3

主题：期望与概率。总计 480 分钟。

- [AtCoder ABC360 E - Random Swaps of Balls](https://atcoder.jp/contests/abc360/tasks/abc360_e)（60 分钟）
- [AtCoder ABC342 F - Black Jack](https://atcoder.jp/contests/abc342/tasks/abc342_f)（90 分钟）
- [AtCoder ABC332 E - Lucky bag](https://atcoder.jp/contests/abc332/tasks/abc332_e)（110 分钟）
- [AtCoder ABC362 E - Count Arithmetic Subsequences](https://atcoder.jp/contests/abc362/tasks/abc362_e)（100 分钟）
- [AtCoder ABC349 F - Subsequence of Subset](https://atcoder.jp/contests/abc349/tasks/abc349_f)（100 分钟）
- 记录与重写（20 分钟）

## Day 4

主题：组合计数与复杂式子。总计 480 分钟。

- [AtCoder ABC351 F - Double Sum](https://atcoder.jp/contests/abc351/tasks/abc351_f)（80 分钟）
- [CF 2000E - Photoshoot for Gorillas](https://codeforces.com/problemset/problem/2000/E)（80 分钟）
- [CF 2000F - Color Rows and Columns](https://codeforces.com/problemset/problem/2000/F)（100 分钟）
- [AtCoder ABC366 F - Maximum Composition](https://atcoder.jp/contests/abc366/tasks/abc366_f)（100 分钟）
- [AtCoder ABC383 E - Sum of Max Matching](https://atcoder.jp/contests/abc383/tasks/abc383_e)（100 分钟）
- 记录与重写（20 分钟）

## Day 5

主题：近期中高档综合题。总计 480 分钟。

- [AtCoder ABC344 F - Earn to Advance](https://atcoder.jp/contests/abc344/tasks/abc344_f)（130 分钟）
- [AtCoder ABC352 E - Clique Connect](https://atcoder.jp/contests/abc352/tasks/abc352_e)（100 分钟）
- [AtCoder ABC377 F - Avoid Queen Attack](https://atcoder.jp/contests/abc377/tasks/abc377_f)（100 分钟）
- [CF 1997D - Maximize the Root](https://codeforces.com/problemset/problem/1997/D)（120 分钟）
- 记录与重写（30 分钟）

## Day 6

主题：正式区域赛速度训练与复盘。总计 480 分钟。

- [2025 ICPC Asia Nanjing Regional Contest](https://qoj.ac/contest/2581)（虚拟赛，300 分钟）
- 赛后逐题统计（45 分钟）
- 选择两道最接近通过的题重做（90 分钟）
- 周总结（45 分钟）

## 执行规则

- Day 1--5 单题到时即停；没有提交代码也要记录停下时的状态。
- Day 3 的题如果只会写递推式但不能解释状态含义，按“建模”卡点记录，不算独立 AC。
- Day 4 的题如果式子正确但实现超过时限，按“实现”卡点记录，不延长当日题目时间。
- Day 6 虚拟赛期间不看题解、不看本地代码、不搜索题目讨论；赛后才允许打开资料。
- 赛后重写必须合上题解独立完成；只看懂题解不记作 AC。

## 本周验收

- Day 1--2 至少各有 3 道独立 AC，且至少完成 2 道构造/性质题的无提示重写。
- Day 3 至少独立完成 3 道，并为每道题写出状态定义、转移和边界条件。
- Day 4 至少独立完成 3 道，记录一次“式子正确但实现失败”的具体原因；若没有发生，主动做一次复杂度审计。
- Day 5 完成至少 2 道；Day 6 完成一场 300 分钟正式区域赛虚拟赛和两道赛后重做。
- 下次汇报附上每天的统一记录、Day 6 的通过题与罚时，以及五类薄弱题中各自最慢的一道。
