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
 * heapsort is a comparison-based sorting algorithm.
 * Heapsort can be thought of as an improved selection sort:
 * like selection sort, heapsort divides its input into a sorted and an unsorted region,
 * and it iteratively shrinks the unsorted region by extracting the largest element from it
 * and inserting it into the sorted region. Unlike selection sort,
 * heapsort does not waste time with a linear-time scan of the unsorted region;
 * rather, heap sort maintains the unsorted region in a heap data structure to more quickly
 * find the largest element in each step
 *
 * # Complexities
 *
 * Worst-Case complexity    O(N * log(N))
 * Best-Case complexity     O(N * log(N))
 */

void Heapify(vll &arr, ll n, ll i)
{
    ll largest(i), left(2 * i + 1), right(2 * i + 2);
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
    for (ll i(len / 2 - 1); i >= 0; --i)
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
    // freopen("output.txt", "w", stdout);

    return 0;
}