#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define edl '\n'

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

int main()
{
    Mesh_Ali;
    // freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cout << edl << "DONE" << edl;
    return (0);
}