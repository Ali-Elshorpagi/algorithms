#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'

// link : https://leetcode.com/problems/longest-increasing-subsequence/
// name : Longest Increasing Subsequence - LeetCode 300

class Solution // O(N^2) time & space
{
    vvi memory; // for Memoization

public:
    Solution() { Mesh_Ali, memory.resize(2505, vi(2505, -1)); }
    int dp(vi &nums, int current_idx, int prev_idx)
    {
        if (current_idx == sz(nums))
            return 0;
        // +1 cuz its start with -1, so it will access to garbage or RTE
        auto &ref(memory[current_idx][prev_idx + 1]);
        if (ref != -1)
            return ref;
        int pick(0);
        if (prev_idx == -1 || nums[current_idx] > nums[prev_idx])
            pick = 1 + dp(nums, current_idx + 1, current_idx);
        int leave(dp(nums, current_idx + 1, prev_idx));
        return ref = max(pick, leave);
    }
    int lengthOfLIS(vi &nums)
    {
        return dp(nums, 0, -1);
    }
    void TEST()
    {
        vi nums{10, 9, 2, 5, 3, 7, 101, 18};
        cout << lengthOfLIS(nums) << edl; // 4
        // vi nums{0, 1, 0, 3, 2, 3};
        // cout << lengthOfLIS(nums) << edl; // 4
        // vi nums{7, 7, 7, 7, 7, 7, 7};
        // cout << lengthOfLIS(nums) << edl; // 1
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