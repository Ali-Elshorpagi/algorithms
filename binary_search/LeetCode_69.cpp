#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define edl '\n'
#define sq(x) (x) * (x)

class Solution
{
public:
    Solution() { __elshorpagi__; }
    int mySqrt_(int x)
    {
        if (!x || x == 1)
            return x;
        ll ans(-1), left(1), right(x >> 1);
        while (left <= right)
        {
            ll mid(left + ((right - left) >> 1));
            if (sq(mid) == x)
                return mid;
            else if (sq(mid) < x)
                left = mid + 1, ans = mid;
            else
                right = mid - 1;
        }
        return ans;
    }
    int mySqrt(int x)
    {
        if (!x || x == 1)
            return x;
        double left(1), right(x >> 1), EPS(1e-9);
        while (right - left > EPS)
        {
            double mid(left + ((right - left) / 2));
            if (sq(mid) < x) // it's equal to (sq(mid) - x < 0.0)
                left = mid;
            else
                right = mid;
        }
        return left + EPS;
        // we add EPS cus the result wil be 1.99999999 or something like that;
    }
    void TEST()
    {
        int x(4);
        cout << mySqrt(x) << edl; // 2
        x = 8;
        cout << mySqrt(x) << edl; // 2
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