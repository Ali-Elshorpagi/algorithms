#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

#define _CRT_SECURE_NO_DEPRECATE
#define Sukuna (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define edl '\n'

class Fibonacci
{
    vll arr;
    void power(vvll &fib, ll n)
    {
        if (n < 2)
            return;
        vvll org_mat{{1, 1}, {1, 0}};
        power(fib, n >> 1);
        multiply(fib, fib);
        if (n & 1)
            multiply(fib, org_mat);
    }
    void multiply(vvll &fib, vvll &org_mat)
    {
        ll x((fib[0][0] * org_mat[0][0]) + (fib[0][1] * org_mat[1][0])),
            y((fib[0][0] * org_mat[0][1]) + (fib[0][1] * org_mat[1][1])),
            z((fib[1][0] * org_mat[0][0]) + (fib[1][1] * org_mat[1][0])),
            w((fib[1][0] * org_mat[0][1]) + (fib[1][1] * org_mat[1][1]));

        fib[0][0] = x;
        fib[0][1] = y;
        fib[1][0] = z;
        fib[1][1] = w;
    }

public:
    Fibonacci() { Sukuna; }
    ll fib_0(ll n) // O(2^N) time & space, Exponential Time & Space
    {
        if (n < 2)
            return 1;
        return fib_0(n - 1) + fib_0(n - 2);
    }
    ll fib_1(ll n) // O(N) time & space, Linear Time & Space
    {
        // using DP-Memoization approach;
        // or Top-Down approach;
        if (n < 2)
            return 1;
        if (arr[n] != -1)
            return arr[n];
        return arr[n] = fib_1(n - 1) + fib_1(n - 2);
    }
    ll fib_2(ll n) // O(N) time & space, Linear Time & Space
    {
        if (n < 2)
            return 1;
        ll &ref(arr[n]); // it's reference, so any change upon the variable(ref) will change the arr[n]
        if (ref != -1)
            return ref;
        return ref = fib_2(n - 1) + fib_2(n - 2);
    }
    ll fib_3(ll n) // O(N) time & space, Linear Time & Space
    {
        // using Bottom-Up approach;
        arr[0] = arr[1] = 1;
        for (int i(2); i <= n; ++i)
            arr[i] = arr[i - 1] + arr[i - 2];
        return arr[n];
    }
    ll fib_4(ll n) // O(n) time, O(1) space, Linear Time & Constant Space
    {
        ll a(1), b(1), c(-1);
        for (int i(2); i <= n; ++i)
        {
            c = a + b;
            a = b, b = c;
        }
        // c == b;
        return b;
    }
    // source : https://en.wikipedia.org/wiki/Fibonacci_sequence#Matrix_form
    ll fib_5(ll n) // O(log(n)) time & space, Logarithmic Time & Space
    {
        // using approach Matrix-Power approach;
        ++n; // doing this to make the sequence start with 1,1,2...etc
        vvll fib{{1, 1}, {1, 0}};
        power(fib, n - 1);
        return fib[0][0];
    }

    ll fib_6(ll n) // O(log(n)) time, O(1) space, Logarithmic Time & Constant Space
    {              // it's log(n) cus the pow(), sqrt() functions;
        // using Binet's Formula
        // F(n)	= ((phi^n)-(-phi)^(-n))/(sqrt(5));
        // F(n) =  ((phi^n) - (1-phi)^n)/√5;
        // phi = Golden Ratio = 0.5*(1 + sqrt(5))
        ++n; // doing this to make the sequence start with 1,1,2...etc
        double phi((1 + sqrt(5)) * 0.5);
        return round(pow(phi, n) / sqrt(5));
        // in large numbers it's not fully accurate, but it's work
    }
    void TEST()
    {
        ll n(80);
        arr.resize(n + 1, -1);
        // cout << fib_0(n) << edl; // will crashed, cus TLE & MLE
        // cout << fib_1(n) << edl; // 37889062373143906
        // cout << fib_2(n) << edl; // 37889062373143906
        // cout << fib_3(n) << edl; // 37889062373143906
        // cout << fib_4(n) << edl; // 37889062373143906
        cout << fib_5(n) << edl; // 37889062373143906
        cout << fib_6(n) << edl; // 37889062373143896
    }
};

int main()
{
    Fibonacci fib;
    // freopen("../test/input.txt", "r", stdin);
    freopen("../test/output.txt", "w", stdout);
    int tc(1);
    // cin >> tc;
    while (tc--)
        cout << "Case #" << tc + 1 << edl, fib.TEST();
    cout << edl << "DONE" << edl;
    return (0);
}