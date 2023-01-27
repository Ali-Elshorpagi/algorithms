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
 * merge sort (also commonly spelled as mergesort) is an efficient,
 * general-purpose, and comparison-based sorting algorithm.
 * Most implementations produce a stable sort,
 * which means that the order of equal elements is the same in the input and output.
 * Merge sort is a divide-and-conquer algorithm
 *
 * * # Complexities
 *
 * Worst-Case complexity   O(N * log(N))
 * Space complexity        O(N)
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
    auto mid(begin + (end - begin) / 2);
    Merge_Sort(arr, begin, mid);
    Merge_Sort(arr, mid + 1, end);
    Merge(arr, begin, mid, end);
}

int main()
{
    Mesh_Ali;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    return 0;
}