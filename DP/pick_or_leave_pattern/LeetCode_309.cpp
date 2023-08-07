#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'

class Solution
{   
    // for memoization
    vvi memory;          //  dp
    vector<vvi> memory_; // dp_
    enum
    {
        COOLDOWN,
        BUY,
        SELL
    };

public:
    Solution() { Mesh_Ali, memory_.resize(5005, vvi(2, vi(3, -1))); /*memory.resize(5005, vi(2, -1));*/ }
    // option = 0 -> buy
    // option = 1 -> sell
    int dp(vi &prices, bool option, int idx)
    {
        if (idx >= sz(prices))
            return 0;
        auto &ref(memory[idx][option]);
        if (ref != -1)
            return ref;
        int profit(0);
        if (option) // buy
            profit = max(-prices[idx] + dp(prices, 0, idx + 1), dp(prices, 1, idx + 1));
        else // !option == sell // idx + 2 to skip the cooldown-day
            profit = max(prices[idx] + dp(prices, 1, idx + 2), dp(prices, 0, idx + 1));
        // third option is sell, but it was handled;
        return ref = profit;
    }
    int dp_(vi &prices, int idx, int have_stoke, int last_operations)
    {
        if (idx >= sz(prices))
            return 0;
        auto &ref(memory_[idx][have_stoke][last_operations]);
        if (ref != -1)
            return ref;
        int cool_down(dp_(prices, idx + 1, have_stoke, COOLDOWN)), buy(0), sell(0);
        if (have_stoke) // can sell
            sell = prices[idx] + dp_(prices, idx + 1, 0, SELL);
        else if (last_operations != SELL) // can buy
            buy = -prices[idx] + dp_(prices, idx + 1, 1, BUY);
        return ref = max({cool_down, sell, buy});
    }
    int maxProfit(vi &prices)
    {
        // return dp(prices, 1, 0); // logically u must buy first;
        return dp_(prices, 0, 0, COOLDOWN);
    }
    void TEST()
    {
        // vi prices{1, 2, 3, 0, 2};
        // cout << maxProfit(prices) << edl; // 3
        // vi prices{1};
        // cout << maxProfit(prices) << edl; // 0
        // vi prices{3, 5};
        // cout << maxProfit(prices) << edl; // 2
        // vi prices{1, 2, 3, 4, 5};
        // cout << maxProfit(prices) << edl; // 5
        vi prices{3, 0, 15, 20, 1, 12};
        cout << maxProfit(prices) << edl; // 26
    }
};

int main()
{
    Solution sol;
    // freopen("../../test/input.txt", "r", stdin);
    freopen("../../test/output.txt", "w", stdout);
    int tc(1);
    // cin >> tc;
    while (tc--)
        cout << "Case #" << tc + 1 << edl, sol.TEST();
    cout << edl << "DONE" << edl;
    return (0);
}