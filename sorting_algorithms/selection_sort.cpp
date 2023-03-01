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
 * Best-Case Time      O(N²)
 * Worst-Case Time     O(N²)
 * Worst-Case Space    O(1)
 */

void Selection_Sort(vll &arr)
{
    ll min_idx, len(sz(arr));
    for (ll i(0); i < len - 1; ++i)
    {
        min_idx = i;
        for (ll j(i + 1); j < len; ++j)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}

ll min_idx(vll &arr, ll i, ll j)
{
    if (i == j)
        return i;
    ll k(min_idx(arr, i + 1, j));
    return (arr[i] < arr[k]) ? i : k;
}

void Selection_Sort_Recursive(vll &arr, ll n, ll index = 0)
{
    if (index == n)
        return;
    ll k(min_idx(arr, index, n - 1));
    if (k != index)
        swap(arr[k], arr[index]);
    Selection_Sort_Recursive(arr, n, index + 1);
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