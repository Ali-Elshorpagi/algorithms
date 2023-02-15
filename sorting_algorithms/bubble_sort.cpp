#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<char> vc;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define edl '\n'

/*
 * # Complexities
 *
 * Best-Case Time     O(N)
 * Worst-Case Time    O(N²)
 * Worst-Case Space   O(1)
 */

void Bubble_Sort(vll &arr)
{
    ll len(sz(arr));
    bool swapped;
    for (ll i(0); i < len - 1; ++i)
    {
        swapped = false;
        for (ll j(0); j < len - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]), swapped = true;
        }
        if (swapped == false)
            break;
    }
}

void Bubble_Sort_Recursive(vll &arr, ll size)
{
    if (size == 1)
        return;
    for (ll i(0); i < size - 1; ++i)
    {
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
    }
    Bubble_Sort_Recursive(arr, size - 1);
}

int main()
{
    Mesh_Ali;
    // freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cout << edl << "DONE" << edl;
    return (0);
}