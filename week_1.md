# Week 1：从“会做”到“限时做出”

根据洛谷机器可读快照：你已通过 518 题，难度 5--7 的题不少，说明模板和偏难题并非空白；但 Elo 924，且本地近期记录以 ABC A--E、DP 入门和零散 VP 为主。本周先不堆新模板，集中训练区域赛银牌最需要的三件事：**35 分钟内抓到主观察、75 分钟内完成可提交实现、赛后能复盘成可迁移的套路**。

每天按 8 小时安排。题目后的时间是硬上限，不是最低要求；提前通过就把余下时间用于下面的复盘。到达“思路止损点”后只看题解的第一条提示，不直接看代码；仍无法独立完成时可以看完整题解，但必须合上题解后重新写一遍。

每道题都记录：开始想法时间、得到关键观察时间、首份代码时间、WA/调试原因、最终复杂度。最后把当天最慢的一题在纸上写成三行：状态或观察、转移或构造、复杂度。

## Day 1

主题：DP 状态设计与边界，先建立“有限时间内写出正确转移”的节奏。总计约 8 小时。

- [AtCoder DP K - Stones](https://atcoder.jp/contests/dp/tasks/dp_k)（70 分钟，必做）：博弈 DP，先写出胜负状态再实现。
- [AtCoder DP I - Coins](https://atcoder.jp/contests/dp/tasks/dp_i)（100 分钟，必做）：概率 DP；特别检查浮点边界和状态含义。
- [AtCoder DP L - Deque](https://atcoder.jp/contests/dp/tasks/dp_l)（110 分钟，必做）：区间/回合 DP，先写小规模表格验证转移。
- [AtCoder DP J - Sushi](https://atcoder.jp/contests/dp/tasks/dp_j)（130 分钟，挑战）：三维期望 DP；若 45 分钟仍写不出状态，先读提示再继续。
- 复盘与重写（40+30 分钟）：不看原代码重写 K、I 中较慢的一题，并写出“为什么不会重复计数”。

今天不追求四题全 AC；J 允许只完成状态和转移证明。目标是每道题在规定时间内留下完整、可检查的转移，而不是无限硬想。

## Day 2

主题：观察、贪心和二分，训练把题面操作压缩成一两个参数。总计约 8 小时。

- [CF 279B - Books](https://codeforces.com/problemset/problem/279/B)（55 分钟）：双指针，要求一次写对边界。
- [CF 1485A - Add and Divide](https://codeforces.com/problemset/problem/1485/A)（65 分钟）：枚举小参数的构造性贪心。
- [CF 1542B - Plus and Multiply](https://codeforces.com/problemset/problem/1542/B)（85 分钟）：乘法次数很少的数论/枚举观察；35 分钟没有不变量就看一条提示。
- [CF 1701C - Computer Game](https://codeforces.com/problemset/problem/1701/C)（95 分钟）：二分答案，自己证明每台机器的贡献公式。
- [CF 1615B - And It’s Non-Zero](https://codeforces.com/problemset/problem/1615/B)（75 分钟）：按位计数与前缀预处理，练习把暴力统计变成固定维度。
- 错题重做（65 分钟）：从当天最早看题解的一题开始，关掉题解在 30 分钟内重新写出；剩余时间检查整数范围和复杂度。

## Day 3

主题：图上的状态设计，连接你已有的最短路模板和区域赛中档建模。总计约 8 小时。

- [CSES Flight Discount](https://cses.fi/problemset/task/1195)（90 分钟）：两层最短路/边状态，禁止直接套未经解释的模板。
- [AtCoder ABC342 E - Last Train](https://atcoder.jp/contests/abc342/tasks/abc342_e)（110 分钟）：反向 Dijkstra，重点写清“最晚可出发时间”的转移。
- [CF 1473E - Minimum Path](https://codeforces.com/problemset/problem/1473/E)（140 分钟，挑战）：两种一次性优惠的状态压缩；先画 4 个状态再编码。
- [AtCoder DP G - Longest Path](https://atcoder.jp/contests/dp/tasks/dp_g)（75 分钟）：DAG 记忆化/拓扑 DP，限时写出递归栈安全版本。
- 复盘（65 分钟）：挑一题写出“为什么图无环/为什么状态不会漏解”，再用一组自己构造的极小数据手算。

如果 CF 1473E 超过 140 分钟仍无法落地，记录卡点并换成只完成状态图和转移；不要把整天耗在调一个边界错误上。

## Day 4

主题：数据结构只是手段，先识别可维护的量，再写模板。总计约 8 小时。

- [AtCoder ABC342 D - Square Pair](https://atcoder.jp/contests/abc342/tasks/abc342_d)（80 分钟）：质因数奇偶性/哈希计数，训练分类讨论零值。
- [AtCoder ABC339 E - Smooth Subsequence](https://atcoder.jp/contests/abc339/tasks/abc339_e)（110 分钟）：值域 DP + 线段树，先写朴素转移再优化。
- [AtCoder ABC348 E - Minimize Sum of Distances](https://atcoder.jp/contests/abc348/tasks/abc348_e)（90 分钟）：树形换根 DP，手推一条边两端的增量。
- [CF 1702E - Split Into Two Sets](https://codeforces.com/problemset/problem/1702/E)（80 分钟）：图论建模与度数/环判断，要求解释充分条件。
- [CF 1741F - Multi-Colored Segments](https://codeforces.com/problemset/problem/1741/F)（105 分钟，挑战）：排序、扫描和区间维护；前 45 分钟只做模型，不急着敲树状数组。
- 复盘（15 分钟）：把当天用到的线段树/树状数组接口整理成自己的最小模板，只保留本周实际需要的操作。

## Day 5

主题：区域赛中档题专场，训练读题顺序和止损。使用 [ICPC Online Contest 2（QOJ 2524）](https://qoj.ac/contest/2524)，对应本地 `25-XCPC-Regional-ez-mid/content.md` 中列出的题。

- 无题解限时块（240 分钟）：只做 C、D、E 三题，顺序自选；每题最多 75 分钟，前 20 分钟必须写下输入规模、目标复杂度和一个可验证的观察。不要打开本地 solution PDF。
- 现场补题（90 分钟）：限时块结束后，只选最接近 AC 的一题继续；若仍卡住，读题解到第一处关键引理并独立完成。
- 赛后复盘（90 分钟）：为 C/D/E 各写一张卡片：题型标签、第一关键观察、实现中最容易错的边界、若在正式赛场应在第几分钟放弃。

目标不是三题全过，而是把“不会”分成读不懂、没观察、会观察但实现慢三类。三类问题必须分别记录。

## Day 6

主题：完整区域赛模拟与速度校准。使用 [Xi’an Regional（QOJ 2562）](https://qoj.ac/contest/2562)，本地清单中将 G/L/J、F/I、B/M/C 列为由易到难的中档候选。

- 虚拟赛（300 分钟）：关闭题解和讨论，按正式比赛流程做整场；前 15 分钟快速扫题并排序，之后优先拿稳第一档，再冲第二档。每次放弃题目都写一句原因。
- 赛后统计（45 分钟）：记录通过题、首个正确提交时间、罚时、每题思路用时、WA 原因；不要只看总分。
- 只补两题（75 分钟）：优先补第二档中最接近通过的两题；每题 35 分钟仍没有新进展就看题解并合上重写。
- 周总结（60 分钟）：算出本周 1200--1700 难度题的平均“想出核心观察时间”和平均“从观察到 AC 时间”，列出下周只保留的两个薄弱点。

## 本周验收

- 至少 12 道独立完成并 AC；看过提示或题解的题必须标记，不把“看懂”计作独立 AC。
- DP K/I/L 中至少两道能在不看代码的情况下重写；图论题至少两道能说清状态含义和正确性理由。
- Day 5 的三题和 Day 6 的虚拟赛都完成逐题复盘，并能指出一次“本来可以更早换题”的时刻。
- 下次汇报请按题目列出：`结果（AC/看提示/看题解）| 思路用时 | 实现用时 | WA 次数 | 最大卡点`，再附 Day 5/6 的比赛统计。这样第二周可以按真实瓶颈调难度，而不是盲目加题。
