#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)

class Solution // O(N * log(N)) time, O(1) space
{
public:
    Solution() { __elshorpagi__; }
    int longestConsecutive(vi &nums)
    {
        if (!sz(nums))
            return 0;
        sort(all(nums));
        int len(sz(nums)), tmp(1), cnt(0);
        fr(i, 1, len)
        {
            if (nums[i] != nums[i - 1])
            {
                if (nums[i] - nums[i - 1] == 1)
                    ++tmp;
                else
                    cnt = max(cnt, tmp), tmp = 1;
            }
        }
        return max(cnt, tmp);
    }
    void TEST()
    {
        vi nums{100, 4, 200, 1, 3, 2};
        cout << longestConsecutive(nums) << ' ';
        nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
        cout << longestConsecutive(nums) << edl;
        // output 1: 4 9
    }
};

int main()
{
    Solution sol;
    // freopen("test/input.txt", "r", stdin);
    freopen("test/output.txt", "w", stdout);
    int tc(1);
    // cin >> tc;
    while (tc--)
        cout << "Case #" << tc + 1 << edl, sol.TEST();
    cout << edl << "DONE" << edl;
    return (0);
}