#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define Sukuna (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define cl(v) ((v).clear())
#define edl '\n'
#define fc(it, v) for (auto &(it) : (v))
#define fr(i, x, n) for (int i(x); i < n; ++i)

class Solution
{
    vvi ans;
    vi prefix;

public:
    Solution() { Sukuna; }
    void backtracking_(vi &nums, int idx)
    {
        if (idx == sz(nums))
        {
            ans.push_back(nums);
            return;
        }
        fr(i, idx, sz(nums))
        {
            swap(nums[i], nums[idx]); // update the state
            backtracking_(nums, idx + 1);
            swap(nums[i], nums[idx]); // undo the state
        }
    }
    vvi permute_(vi &nums)
    {
        cl(ans);
        backtracking_(nums, 0);
        return ans;
    }
    void backtracking(unordered_set<int> &nums, vi &prefix)
    {
        if (!sz(nums))
        {
            ans.push_back(prefix);
            return;
        }
        unordered_set<int> remaining(all(nums));
        fc(it, nums)
        {
            // update the state
            remaining.erase(it);
            prefix.push_back(it);
            backtracking(remaining, prefix);
            // undo the state
            remaining.insert(it);
            prefix.pop_back();
        }
    }
    vvi permute(vi &nums)
    {
        cl(ans), cl(prefix);
        unordered_set<int> arr(all(nums));
        backtracking(arr, prefix);
        return ans;
    }
    void TEST()
    {
        vi nums{1, 2, 3};
        vvi result = permute(nums);
        fc(it, result)
        {
            fc(jt, it) { cout << jt << ' '; }
            // [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]];
            cout << edl;
        }
        nums = {0, 1}, result = permute(nums);
        fc(it, result)
        {
            fc(jt, it) { cout << jt << ' '; }
            // [[0, 1], [1, 0]];
            cout << edl;
        }
    }
};

int main()
{
    Solution sol;
    // freopen("../test/input.txt", "r", stdin);
    freopen("../test/output.txt", "w", stdout);
    int tc(1);
    // cin >> tc;
    while (tc--)
        cout << "Case #" << tc + 1 << edl, sol.TEST();
    cout << edl << "DONE" << edl;
    return (0);
}