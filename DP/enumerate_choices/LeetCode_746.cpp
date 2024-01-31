#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'

class Solution
{
    vi memeory; // for memoization
public:
    Solution() { __elshorpagi__, memeory.resize(1001, -1); }
    int dp(vi &arr, int idx)
    {
        if (idx >= sz(arr))
            return 0;
        auto &ref(memeory[idx]);
        if (ref != -1)
            return ref;
        int pick(arr[idx] + dp(arr, idx + 1)),
            leave(arr[idx] + dp(arr, idx + 2));
        return ref = min(pick, leave);
    }
    int minCostClimbingStairs(vi &cost)
    {
        return min(dp(cost, 0), dp(cost, 1));
    }
    void TEST()
    {
        vi costs{10, 15, 20};
        cout << minCostClimbingStairs(costs) << edl; // 15
        // vi costs{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
        // cout << minCostClimbingStairs(costs) << edl; // 6
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