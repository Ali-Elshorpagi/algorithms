#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define Sukuna (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)

class Solution
{
    // for Memoization
    vvi memory;
    vi memory_;

public:
    Solution() { Sukuna, memory_.resize(2505, -1), memory.resize(2505, vi(2505, -1)); }
    int dp(vi &nums, int current_idx, int prev_idx) // O(N^2) time & space
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
    int dp_(vi &nums, int idx) // O(N^2) time, O(N) space
    {
        // using forward approach
        if (idx == sz(nums))
            return 0;
        auto &ref(memory_[idx]);
        if (ref != -1)
            return ref;
        ref = 0;
        fr(j, idx + 1, sz(nums)) // Maximize among all valid positions after idx
        {
            if (nums[j] > nums[idx])
                ref = max(ref, dp_(nums, j));
        }
        return ++ref; // ++ to add idxth position
    }
    int lengthOfLIS_0(vi &nums)
    {
        int mx(0);
        fr(i, 0, sz(nums)) { mx = max(mx, dp_(nums, i)); }
        return mx;
    }
    int lengthOfLIS_1(vi &nums)
    {
        nums.insert(nums.begin(), INT_MIN);
        return dp_(nums, 0) - 1; // -1 for the extra element
        // u can use backward approach by return dp(nums,sz(nums)-1) - 1;
        // and reverse the loop in dp func -> for (int j(idx - 1); j > -1; --j)
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