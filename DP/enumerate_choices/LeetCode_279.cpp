#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

#define _CRT_SECURE_NO_DEPRECATE
#define Sukuna (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define edl '\n'
#define sq(x) (x) * (x)

class Solution
{
    vi memeory; // for memoization

public:
    Solution() { Sukuna, memeory.resize(1e4 + 1, -1); }
    int dp(int n)
    {
        if (!n)
            return 0;
        auto &ref(memeory[n]);
        if (ref != -1)
            return ref;
        int min_(INT_MAX);
        for (int i(1); sq(i) <= n; ++i)
        {

            min_ = min(min_, 1 + dp(n - sq(i)));
        }
        return ref = min_;
    }
    int numSquares(int n) { return dp(n); }
    void TEST()
    {
        int n(12);
        // cout << numSquares(n) << edl; // 3
        // n = 17;
        // cout << numSquares(n) << edl; // 2
        n = 15;
        cout << numSquares(n) << edl; // 4
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