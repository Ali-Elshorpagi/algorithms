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
 * Best-Case Time     O(N * log(N))
 * Worst-Case Time    O(N * log(N))
 * Worst-Case Space   O(N)
 */

void Merge(vll &arr, ll l, ll m, ll r)
{
    ll i, j, k;
    ll n1(m - l + 1), n2(r - m);
    vll L(n1), R(n2);

    for (i = 0; i < n1; ++i)
        L[i] = arr[l + i];

    for (j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];

    i = 0, j = 0, k = l;
    while (i < n1 || j < n2)
    {
        if (j >= n2 || (i < n1 && L[i] <= R[j]))
            arr[k] = L[i], ++i;
        else
            arr[k] = R[j], ++j;
        ++k;
    }
}

void Merge_Sort(vll &arr, ll begin, ll end)
{
    if (begin >= end)
        return;
    auto mid(begin + ((end - begin) >> 1));
    Merge_Sort(arr, begin, mid);
    Merge_Sort(arr, mid + 1, end);
    Merge(arr, begin, mid, end);
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