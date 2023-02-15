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
 * Worst-Case Time    O(N * log(N))
 * Worst-Case Space   O(1)
 */

void Heapify(vll &arr, ll n, ll i)
{
    ll largest(i), left((i << 1) + 1), right((i << 1) + 2);
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        Heapify(arr, n, largest);
    }
}

void Heap_Sort(vll &arr)
{
    ll len(sz(arr));
    for (ll i((len >> 1) - 1); i >= 0; --i)
        Heapify(arr, len, i);

    for (ll j(len - 1); j >= 0; --j)
    {
        swap(arr[0], arr[j]);
        Heapify(arr, j, 0);
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