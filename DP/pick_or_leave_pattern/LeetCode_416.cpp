#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define Sukuna (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fc(it, v) for (auto &(it) : (v))
#define yes cout << "YES\n"
#define no cout << "NO\n"

class Solution
{
    vvi memory; // for memoization
public:
    Solution() { Sukuna, memory.resize(205, vi(100 * 201, -1)); }
    bool dp(vi &nums, int cur_idx, int remains)
    {
        if (cur_idx >= sz(nums) || remains < 0)
            return false;
        if (!remains)
            return true;
        auto &ref(memory[cur_idx][remains]);
        if (ref != -1)
            return ref;
        if (dp(nums, cur_idx + 1, remains)) // leave
            return ref = true;
        return ref = dp(nums, cur_idx + 1, remains - nums[cur_idx]); // pick
    }
    bool canPartition(vi &nums)
    {
        int sum(0);
        fc(it, nums) { sum += it; }
        if (sum & 1) // odd
            return false;
        sum >>= 1;
        return dp(nums, 0, sum);
    }
    void TEST()
    {
        // vi nums{1, 5, 11, 5};
        // canPartition(nums) ? yes : no; // YES
        vi nums{1, 2, 3, 5};
        canPartition(nums) ? yes : no; // NO
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