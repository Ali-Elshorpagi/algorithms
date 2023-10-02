#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'

class Solution
{
    vvi memory; // for Memoization
public:
    Solution() { Mesh_Ali, memory.resize(5005, vi(305, -1)); }
    int dp(vi &coins, int remaining, int idx)
    {
        if (idx >= sz(coins))
            return 0;
        if (!remaining)
            return 1;
        auto &ref(memory[remaining][idx]);
        if (ref != -1)
            return ref;
        int pick(0);
        if (coins[idx] <= remaining)
            pick = dp(coins, remaining - coins[idx], idx);
        int leave(dp(coins, remaining, idx + 1));
        return ref = leave + pick;
    }
    int change(int amount, vi &coins)
    {
        return dp(coins, amount, 0);
    }
    void TEST()
    {
        // int amount(5);
        // vi coins{1, 2, 5};
        // cout << change(amount, coins) << edl; // 4
        // int amount(10);
        // vi coins{10};
        // cout << change(amount, coins) << edl; // 1
        int amount(3);
        vi coins{2};
        cout << change(amount, coins) << edl; // 0
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