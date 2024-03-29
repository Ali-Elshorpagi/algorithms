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
    vi memory;

public:
    Solution() { __elshorpagi__, memory.resize(505, -1); }
    int dp(vi &arr, int start_idx, int k)
    {
        if (start_idx >= sz(arr))
            return 0;
        auto &ref(memory[start_idx]);
        if (ref != -1)
            return ref;

        ref = INT_MIN;
        int max_(INT_MIN);
        for (int i(start_idx); i < start_idx + k && i < sz(arr); ++i) // i == block_end
        {
            max_ = max(max_, arr[i]);
            int length(i - start_idx + 1);
            ref = max(ref, length * max_ + dp(arr, i + 1, k));
        }
        return ref;
    }
    int maxSumAfterPartitioning(vi &arr, int k)
    {
        return dp(arr, 0, k);
    }
    void TEST()
    {
        // vi arr{1, 15, 7, 9, 2, 5, 10};
        // int k(3);
        // cout << maxSumAfterPartitioning(arr, k) << edl; // 84
        vi arr{1, 4, 1, 5, 7, 3, 6, 1, 9, 9, 3};
        int k(4);
        cout << maxSumAfterPartitioning(arr, k) << edl; // 83
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