#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)

// link : https://leetcode.com/problems/longest-increasing-subsequence/
// name : LeetCode 300

class Solution // O(N^2) time, O(N) space
{
    vi memory; // for Memoization

public:
    Solution() { Mesh_Ali, memory.resize(2505, -1); }
    int dp(vi &nums, int idx) // using forward approach
    {
        if (idx == sz(nums))
            return 0;
        auto &ref(memory[idx]);
        if (ref != -1)
            return ref;
        ref = 0;
        fr(j, idx + 1, sz(nums)) // Maximize among all valid positions after idx
        {
            if (nums[j] > nums[idx])
                ref = max(ref, dp(nums, j));
        }
        return ++ref; // ++ to add it's position
    }
    int lengthOfLIS_(vi &nums)
    {
        int mx(0);
        fr(i, 0, sz(nums)) { mx = max(mx, dp(nums, i)); }
        return mx;
    }
    int lengthOfLIS(vi &nums)
    {
        nums.insert(nums.begin(), INT_MIN);
        return dp(nums, 0) - 1; // -1 for the extra element
        // u can use backward approach by return dp(nums,sz(nums)-1) - 1;
        // and reverse the loop in dp func -> for (int j(idx - 1); j > -1; --j)
    }
    void TEST()
    {
        // vi nums{10, 9, 2, 5, 3, 7, 101, 18};
        // cout << lengthOfLIS(nums) << edl; // 4
        // vi nums{0, 1, 0, 3, 2, 3};
        // cout << lengthOfLIS(nums) << edl; // 4
        vi nums{7, 7, 7, 7, 7, 7, 7};
        cout << lengthOfLIS(nums) << edl; // 1
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