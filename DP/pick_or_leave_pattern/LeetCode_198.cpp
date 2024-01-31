#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'

class Solution
{
    vi memory; // for memoization
public:
    Solution() { __elshorpagi__, memory.resize(405, -1); }
    int dp(vi &nums, int idx)
    {
        if (idx >= sz(nums))
            return 0;
        auto &ref(memory[idx]);
        if (ref != -1)
            return ref;
        int pick(nums[idx] + dp(nums, idx + 2)), leave(dp(nums, idx + 1));
        return ref = max(pick, leave);
    }
    int rob(vi &nums) { return dp(nums, 0); }
    void TEST()
    {
        // vi nums{2, 7, 9, 3, 1};
        // cout << rob(nums) << edl; // 12
        vi nums{1, 2, 3, 1};
        cout << rob(nums) << edl; // 4
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