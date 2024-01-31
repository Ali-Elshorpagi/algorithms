#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)

class Solution
{
    // for memoization
    vi memeory_;
    vvi memeory;

public:
    Solution() { __elshorpagi__, memeory_.resize(60, -1), memeory.resize(60, vi(60, -1)); }
    int dp_(int n)
    {
        if (!n)
            return 1;

        auto &ref(memeory_[n]);
        if (ref != -1)
            return ref;

        int max_(0);
        fr(i, 1, n + 1) { max_ = max(max_, i * dp_(n - i)); }
        return ref = max_;
    }
    int dp(int n, int sum)
    {
        if (n == 1)
            return 1;

        auto &ref(memeory[n][sum]);
        if (ref != -1)
            return ref;

        int pick(0);
        if (sum >= n)
            pick = n * dp(n, sum - n);
        int leave(dp(n - 1, sum));

        return ref = max(pick, leave);
    }
    int integerBreak(int n)
    {
        if (n < 4)
            return n - 1;
        // return dp_(n);
        return dp(n, n);
    }
    void TEST()
    {
        int n(10);
        // cout << integerBreak(n) << edl; // 36
        n = 7;
        cout << integerBreak(n) << edl; // 12
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