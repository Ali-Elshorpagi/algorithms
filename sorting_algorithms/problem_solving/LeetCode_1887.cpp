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

class Solution
{
public:
    Solution() { __elshorpagi__; }
    int reductionOperations(vi &nums)
    {
        sort(all(nums));
        int len(sz(nums)), cnt(0);
        fr(i, 1, len)
        {
            if (nums[i] != nums[i - 1])
                cnt += len - i; // by simulation
        }
        return cnt;
        // idxs -> 0 1 2 3 4 , len = 5
        // arr =   1 2 3 4 5
        // operations :
        //         1 2 3 4 4
        //         1 2 3 3 4
        //         1 2 3 3 3
        //         1 2 2 3 3
        //         1 2 2 2 3
        //         1 2 2 2 2
        //         1 1 2 2 2
        //         1 1 1 2 2
        //         1 1 1 1 2
        //         1 1 1 1 1
    }
    void TEST()
    {
        vi arr{5, 1, 3};
        cout << reductionOperations(arr) << edl; // 3
        arr = {1, 1, 1};
        cout << reductionOperations(arr) << edl; // 0
        arr = {1, 1, 2, 2, 3};
        cout << reductionOperations(arr) << edl; // 4
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