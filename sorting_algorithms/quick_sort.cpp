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
 * Best-Case Time     O(N * log(N))
 * Worst-Case Time    O(N²)
 * Worst-Case Space   O(N)
 */

ll Partition(vll &arr, ll iBegin, ll jEnd)
{
    ll i(iBegin), j(jEnd), pivLoc(i);
    while (true)
    {
        while (arr[pivLoc] <= arr[j] && pivLoc != j)
            --j;
        if (pivLoc == j)
            break;
        else if (arr[pivLoc] > arr[j])
        {
            swap(arr[j], arr[pivLoc]);
            pivLoc = j;
        }
        while (arr[pivLoc] >= arr[i] && pivLoc != i)
            ++i;
        if (pivLoc == i)
            break;
        else if (arr[pivLoc] < arr[i])
        {
            swap(arr[i], arr[pivLoc]);
            pivLoc = i;
        }
    }
    return pivLoc;
}

void Quick_Sort(vll &arr, ll low, ll high)
{
    if (low < high)
    {
        ll piv(Partition(arr, low, high));
        Quick_Sort(arr, low, piv - 1);
        Quick_Sort(arr, piv + 1, high);
    }
}

int main()
{
    Mesh_Ali;
    // freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cout << edl << "DONE" << edl;
    return (0);
}