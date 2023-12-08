#include <iostream>

using namespace std;

typedef long long ll;

#define _CRT_SECURE_NO_DEPRECATE
#define Sukuna (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define edl '\n'

class Solution
{

public:
    Solution() { Sukuna; }
    double fast_power(double x, ll n)
    {
        if (!n)
            return 1.0;
        double half(fast_power(x, n >> 1));
        half *= half;
        if (n & 1)
            half *= x;
        return half;
    }
    double myPow(double x, int n)
    {
        ll N = n;
        if (n < 0)
            x = 1 / x, N = -N;
        return fast_power(x, N);
    }
    void TEST()
    {
        double x(2.00000);
        int n(10);
        cout << myPow(x, n) << edl; // 1024.00000
        x = 2.10000, n = 3;
        cout << myPow(x, n) << edl; // 9.26100
        x = 2.00000, n = -2;
        cout << myPow(x, n) << edl; // 0.25000
        x = 2.00000, n = -4;
        cout << myPow(x, n) << edl; // 0.0625
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