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
 * Insertion sort is a simple sorting algorithm that builds the final
 * sorted array one at a time. It is much less efficient compared to
 * other sorting algorithms like heap sort, merge sort or quick sort.
 * However it has several advantages such as
 * 1. Easy to implement
 * 2. For small set of data it is quite efficient
 * 3. More efficient that other Quadratic complexity algorithms like
 *    Selection sort or bubble sort.
 * 4. It's stable that is it does not change the relative order of
 *    elements with equal keys
 * 5. Works on hand means it can sort the array or list as it receives.
 *
 * It is based on the same idea that people use to sort the playing cards in
 * their hands.
 * the algorithms goes in the manner that we start iterating over the array
 * of elements as soon as we find a unsorted element that is a misplaced
 * element we place it at a sorted position.
 *
 * # Complexities
 *
 * Worst-Case complexity   O(N²)
 * Best-Case complexity    O(N)
 */

void Insertion_Sort(vll &arr)
{
    ll key, j, len(sz(arr));
    for (ll i(1); i < len; ++i)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
            arr[j + 1] = arr[j], --j;
        arr[j + 1] = key;
    }
}

void Insertion_Sort_Recursive(vll &arr, ll size)
{
    if (size <= 1)
        return;
    Insertion_Sort_Recursive(arr, size - 1);
    ll last = arr[size - 1], j = size - 2;
    while (j >= 0 && arr[j] > last)
        arr[j + 1] = arr[j], --j;
    arr[j + 1] = last;
}

int main()
{
    Mesh_Ali;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    return 0;
}