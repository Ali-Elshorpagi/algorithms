#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

#define _CRT_SECURE_NO_DEPRECATE
#define Sukuna (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define edl '\n'
#define fc(it, v) for (auto &(it) : (v))

class Solution
{
    vi memory; // for Memoization
public:
    Solution() { Sukuna, memory.resize(1005, -1); }
    int dp(vi &nums, int remaining)
    {
        if (!remaining)
            return 1;
        auto &ref(memory[remaining]);
        if (ref != -1)
            return ref;
        ref = 0;
        fc(it, nums)
        {
            if (it <= remaining)
                ref += dp(nums, remaining - it);
        }
        return ref;
    }
    int combinationSum4(vi &nums, int target)
    {
        return dp(nums, target);
    }
    void TEST()
    {
        int target(4);
        vi nums{1, 2, 3};
        cout << combinationSum4(nums, target) << edl; // 7
        // int target(3);
        // vi nums{9};
        // cout << combinationSum4(nums, target) << edl; // 0
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