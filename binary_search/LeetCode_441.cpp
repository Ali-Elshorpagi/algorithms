#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define edl '\n'

class Solution
{
public:
    Solution() { __elshorpagi__; }
    int arrangeCoins_(int n)
    {
        // 1 + 2 + 3 + 4 + ... + X = N;
        // (1 + X) * (X / 2) = N;
        // (1 + X) * X = 2 * N;
        // X^2 + X = 2 * N;
        // X^2 + X + 0.25 = 2 * N + 0.25;
        // (X + 0.5)^2 = 2 * N + 0.25;
        // X = sqrt(2 * N + 0.25) - 0.5;
        return floor(sqrt((ll)2 * n + 0.25) - 0.5);
    }
    bool possible(int n, ll mid)
    {
        ll sum((mid * (mid + 1)) >> 1); // sum formula
        return n >= sum;
    }
    int arrangeCoins(int n)
    {
        int ans(0), left(0), right(n);
        while (left <= right)
        {
            // 1 + 2 + 3 + 4 + ... + X = N;
            // ((1 + X) * X) / 2 = N;
            int mid(left + ((right - left) >> 1));
            if (possible(n, mid))
                ans = mid, left = mid + 1;
            else
                right = mid - 1;
        }
        return ans;
    }
    void TEST()
    {
        int n(5);
        cout << arrangeCoins(n) << edl; // 2
        n = 8;
        cout << arrangeCoins(n) << edl; // 3
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