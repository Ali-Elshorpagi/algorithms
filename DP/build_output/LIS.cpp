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
#define fc(it, v) for (auto &(it) : (v))

class Solution
{
    // for Memoization
    vi memory_;
    vvi memory;

public:
    Solution() { Sukuna, memory_.resize(2505, -1), memory.resize(2505, vi(2505, -1)); }
    int dp_lis(vi &nums, int current_idx, int prev_idx)
    {
        if (current_idx == sz(nums))
            return 0;
        auto &ref(memory[current_idx][prev_idx + 1]);
        if (ref != -1)
            return ref;
        int pick(0);
        if (prev_idx == -1 || nums[current_idx] > nums[prev_idx])
            pick = 1 + dp_lis(nums, current_idx + 1, current_idx);
        int leave(dp_lis(nums, current_idx + 1, prev_idx));
        return ref = max(pick, leave);
    }
    int dp_lis_(vi &nums, int idx)
    {
        if (idx == sz(nums))
            return 0;
        auto &ref(memory_[idx]);
        if (ref != -1)
            return ref;
        ref = 0;
        fr(j, idx + 1, sz(nums))
        {
            if (nums[j] > nums[idx])
                ref = max(ref, dp_lis_(nums, j));
        }
        return ++ref;
    }
    void dp_print_(vi &nums, int idx, vi &output)
    {
        if (idx >= sz(nums))
            return;

        if (idx) // avoid the dummy value;
            output.emplace_back(nums[idx]);

        int optimal(dp_lis_(nums, idx));

        // finding next choice
        fr(i, idx + 1, sz(nums))
        {
            if (nums[idx] < nums[i])
            {
                int choice(1 + dp_lis_(nums, i));
                if (choice == optimal) // found an optimal solution
                {
                    dp_print_(nums, i, output);
                    return;
                }
            }
        }
    }
    void dp_print(vi &nums, int curr_idx, int prev_idx)
    {
        if (curr_idx >= sz(nums))
            return;
        int optimal(dp_lis(nums, curr_idx, prev_idx));

        int choice1(dp_lis(nums, curr_idx + 1, prev_idx)); // leave;

        if (prev_idx == -1 || nums[prev_idx] < nums[curr_idx])
            int choice2(1 + dp_lis(nums, curr_idx + 1, curr_idx)); // pick;

        if (optimal == choice1)
            dp_print(nums, curr_idx + 1, prev_idx);
        else
        {
            cout << nums[curr_idx] << ' ';
            dp_print(nums, curr_idx + 1, curr_idx);
        }
    }
    int LIS(vi &nums)
    {
        int ans(dp_lis(nums, 0, -1));
        dp_print(nums, 0, -1);
        cout << edl;
        return ans;
    }
    vi LIS_(vi &nums)
    {
        nums.insert(nums.begin(), INT_MIN);
        vi output;
        dp_print_(nums, 0, output);
        return output;
    }
    void TEST()
    {
        // there are multiple solutions, so any of them is true
        vi nums{10, 9, 2, 5, 3, 7, 101, 18};
        cout << LIS(nums) << edl;
        // 2 3 7 18
        // 4
        cout << edl << "************" << edl << edl;
        vi output = LIS_(nums);
        fc(it, output) { cout << it << ' '; } // 2 5 7 101
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