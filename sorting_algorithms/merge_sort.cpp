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
#define fl(i, x, n) for (int i(x); i > n; --i)
#define fc(it, v) for (auto &(it) : (v))
#define sq(x) (x) * (x)
#define yes printf("YES\n")
#define no printf("NO\n")

/*
 * # Complexities
 *
 * Best-Case Time     O(N * log(N))
 * Worst-Case Time    O(N * log(N))
 * Worst-Case Space   O(N)
 */

void Merge(vi &arr, int l, int m, int r)
{
    int len_left(m - l + 1), len_right(r - m);
    vi left(len_left), right(len_right);

    for (int i(0); i < len_left; ++i)
        left[i] = arr[l + i];

    for (int j(0); j < len_right; ++j)
        right[j] = arr[m + 1 + j];

    int x(0), y(0), z(l);
    while (x < len_left || y < len_right)
    {
        if (y >= len_right || (x < len_left && left[x] <= right[y]))
            arr[z] = left[x], ++x;
        else
            arr[z] = right[y], ++y;
        ++z;
    }
}

void Merge_Sort(vi &arr, int begin, int end)
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