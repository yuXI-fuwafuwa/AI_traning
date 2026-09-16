#include <bits/stdc++.h>

using i64 = long long;
constexpr i64 MOD = 998244353;

std::unordered_map<std::string, i64> dp, ndp;

std::string subs(const std::string& s, size_t pos, size_t n = std::string::npos)
{
    if (pos >= s.size()) return "";
    return s.substr(pos, n);
}

int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::string s, t;
    std::cin >> s >> t;

    int n = s.size();
    // std::vector<std::string> pref_t, suff_t;
    // for (int i = 0; i < t.size(); ++i)
    //     pref_t.emplace_back(t.substr(0, i));
    // for (int i = 0; i < t.size(); ++i)
    //     suff_t.emplace_back(t.substr(i));

    std::vector<std::string> trans_t;
    for (int i = 0; i < t.size(); ++i)
        trans_t.emplace_back(t.substr(0, i));
    for (int i = 0; i < t.size(); ++i)
        trans_t.emplace_back(t.substr(i));
    std::sort(trans_t.begin(), trans_t.end());
    trans_t.erase(std::unique(trans_t.begin(), trans_t.end()), trans_t.end());

    for (const auto& pt : trans_t)
    {
        if (pt.size() == 1 && pt[0] == s[0]) dp[pt] = 1;
        else if (pt.size() == 0) dp[pt] = 1;
        else dp[pt] = 0;
    }
    // for (const auto& st : suff_t)
    // {
    //     if (st.size() == 1 && st[0] == s[0]) dp[st] = 1;
    //     else if (st.size() == 0) dp[st] = 1;
    //     else dp[st] = 0;
    // }

    for (int j = 1; j < n; ++j)
    {
        ndp.clear();

        char midc = s[j];
        for (const auto& tt : trans_t)
        {
            if (tt.size() == 0)
            {
                ndp[tt] = 1;
                continue;
            }
            // 分割 1 l r
            for (int i = 0; i <= tt.size(); ++i)
            {
                std::string ls = subs(tt, 0, i);
                std::string rs = subs(tt, i);
                ndp[tt] = (ndp[tt] + dp[ls] * dp[rs] % MOD) % MOD;
            }
            // 分割 2 l m r
            for (int i = 0; i <= tt.size() - 1; ++i)
            {
                std::string ls = subs(tt, 0, i);
                std::string rs = subs(tt, i + 1);
                char m = tt[i];
                if (m == midc) ndp[tt] = (ndp[tt] + dp[ls] * dp[rs] % MOD) % MOD;
            }
        }
        // for (const auto& tt : suff_t)
        // {
        //     if (tt.size() == 0)
        //     {
        //         ndp[tt] = 1;
        //         continue;
        //     }
        //     // 分割 1 l r
        //     for (int i = 0; i <= tt.size(); ++i)
        //     {
        //         std::string ls = subs(tt, 0, i);
        //         std::string rs = subs(tt, i);
        //         ndp[tt] = (ndp[tt] + dp[ls] * dp[rs] % MOD) % MOD;
        //         // if (tt == "a") std::cout << "a => " << dp[ls] << ' ' << dp[rs] << '\n';
        //     }
        //     // 分割 2 l m r
        //     for (int i = 0; i <= tt.size() - 1; ++i)
        //     {
        //         std::string ls = subs(tt, 0, i);
        //         std::string rs = subs(tt, i + 1);
        //         char m = tt[i];
        //         if (m == midc) ndp[tt] = (ndp[tt] + dp[ls] * dp[rs] % MOD) % MOD;
        //         // if (tt == "a") std::cout << "a => " << dp[ls] << ' ' << m << ' ' << dp[rs] << '\n';
        //     }
        // }
        
        std::swap(dp, ndp);

        // std::cout << "DP[" << j << "]\n";
        // for (auto [ks, vs] : dp)
        // {
        //     std::cout << ks << ": " << vs << '\n';
        // }
        // std::cout << "=======================\n";
    }

    // dp is the answer
    std::cout << dp[t] << '\n';
}