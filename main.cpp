#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<char> vc;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define cl(v) ((v).clear())
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)
#define fl(i, x, n) for (int i(x); i > n; --i)
#define fc(it, v) for (auto &(it) : (v))
#define sq(x) (x) * (x)
#define yes cout << "YES\n"
#define no cout << "NO\n"

bool possible(int n, long long rows)
{
    long sum = (rows * (rows + 1)) / 2;
    return n >= sum;
}

int arrangeCoins(int n) // O(log(N)) time, O(1) space
{
    // 1 + 2 + 3 + 4 + ... + X = N;
    // (1 + X) * (X / 2) = N;
    ll left(0), right(n), ans(0);
    while (left <= right)
    {
        ll mid(left + ((right - left) >> 1));
        ll sum((mid * (mid + 1)) >> 1); // the sum formula
        if (n >= sum)
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
    }
    return ans;
}

void Solve()
{
    int ans(arrangeCoins(29));
    cout << ans << edl;
    // test functions here;
    cout << edl << "DONE" << edl;
}

int main()
{
    Mesh_Ali;
    // freopen("test/input.txt", "r", stdin);
    freopen("test/output.txt", "w", stdout);
    int tc(1);
    // scanf("%d", &tc);
    while (tc--)
        Solve();
    return (0);
}