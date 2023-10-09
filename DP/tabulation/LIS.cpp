#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define Sukuna (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)
#define fl(i, x, n) for (int i(x); i > n; --i)

class Solution
{
    // for Memoization
    vvi memory;
    vi memory_;

public:
    Solution() { Sukuna; }
    int lengthOfLIS_(vi &nums) // using binary search
    {
        // https://www.youtube.com/watch?v=TocJOW6vx_I
        vi seq;
        seq.push_back(nums[0]);
        fr(i, 1, sz(nums))
        {
            if (seq.back() < nums[i])
                seq.push_back(nums[i]);
            else
            {
                int idx(lower_bound(all(seq), nums[i]) - seq.begin());
                seq[idx] = nums[i];
            }
        }
        return sz(seq);
    }
    int lengthOfLIS__(vi &nums)
    {
        nums.insert(nums.end(), INT_MAX);
        memory_.assign(2505, -1);
        // base case
        memory_[0] = 1;
        // the backword appraoch converted to forward appraoch
        fr(i, 1, sz(nums))
        {
            auto &ret(memory_[i]);
            ret = 1;
            fl(j, i - 1, -1)
            {
                if (nums[j] < nums[i])
                    ret = max(ret, 1 + memory_[j]);
            }
        }
        return memory_[sz(nums) - 1] - 1;
    }
    int lengthOfLIS(vi &nums) // convert pick or leave to tabulation
    {
        memory.assign(2505, vi(2505, -1));
        int len(sz(nums));
        // 0 -> sz - 1 convert to sz - 1 -> 0
        fl(current, len - 1, -1)
        {
            // sz - 1 -> 0 convert to 0 -> sz - 1
            fr(prev, 0, current + 1)
            {
                if (prev == current)
                    prev = len;
                if (current == len - 1) // base case
                {
                    if (prev == len || nums[current] > nums[prev])
                        memory[current][prev] = 1;
                    else
                        memory[current][prev] = 0;
                }
                else
                {
                    int pick(0);
                    if (prev == len || nums[current] > nums[prev])
                    {
                        assert(memory[current + 1][current] != -1);
                        pick = 1 + memory[current + 1][current];
                    }
                    assert(memory[current + 1][prev] != -1);
                    int leave(memory[current + 1][prev]);
                    memory[current][prev] = max(pick, leave);
                }
            }
        }
        return memory[0][sz(nums)];
    }
    void TEST()
    {
        vi nums{10, 9, 2, 5, 3, 7, 101, 18};
        cout << lengthOfLIS__(nums) << edl; // 4
        nums = {0, 1, 0, 3, 2, 3};
        cout << lengthOfLIS__(nums) << edl; // 4
        nums = {7, 7, 7, 7, 7, 7, 7};
        cout << lengthOfLIS__(nums) << edl; // 1
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