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

int main()
{
    Mesh_Ali;
    // freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cout << edl << "DONE" << edl;
    return (0);
}