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
 * Quicksort is an efficient, general-purpose sorting algorithm.
 * it is still a commonly used algorithm for sorting.
 * Overall,it is slightly faster than merge sort and heapsort for randomized data,
 * particularly on larger distributions.
 * Quicksort is a divide-and-conquer algorithm.
 * It works by selecting a 'pivot' element from the array and
 * partitioning the other elements into two sub-arrays,
 * according to whether they are less than or greater than the pivot.
 * For this reason, it is sometimes called partition-exchange sort.
 * The sub-arrays are then sorted recursively. This can be done in-place,
 * requiring small additional amounts of memory to perform the sorting.
 * Quicksort is a comparison sort,
 * meaning that it can sort items of any type for which a "less-than" relation
 * (formally, a total order) is defined.
 * Most implementations of quicksort are not stable,
 * meaning that the relative order of equal sort items is not preserved.
 *
 * # Complexities
 *
 * Worst-Case complexity   O(N²)
 * Best-Case complexity    O(N * log(N))
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
    // freopen("output.txt", "w", stdout);

    return 0;
}