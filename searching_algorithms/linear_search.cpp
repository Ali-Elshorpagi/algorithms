#include <bits/stdc++.h>

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
#define fl(i, x, n) for (int i(x); i >= n; --i)
#define fc(it, v) for (auto &(it) : (v))
#define sq(x) (x) * (x)
#define yes cout << "YES\n"
#define no cout << "NO\n"

/*
 * # Complexities
 *
 * Best-case Time     O(1)
 * Worst-case Time    O(N)
 * Worst-case Space   O(1)
 */

ll Linear_Search(vll &arr, ll value)
{
    ll len(sz(arr));
    for (ll i(0); i < len; ++i)
    {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

ll Linear_Search_Recursive(vll &arr, ll size, ll value)
{
    --size;
    if (size < 0)
        return -1;
    if (arr[size] == value)
        return size;
    return Linear_Search_Recursive(arr, size, value);
}

void Solve()
{
    // test functions here;
    cout << edl << "DONE" << edl;
}

int main()
{
    Mesh_Ali;
    // freopen("../test/input.txt", "r", stdin);
    freopen("../test/output.txt", "w", stdout);
    int tc(1);
    // scanf("%d", &tc);
    while (tc--)
        Solve();
    return (0);
}