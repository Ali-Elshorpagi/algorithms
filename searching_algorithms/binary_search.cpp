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
 * Binary search is a search algorithm that finds the position of a target value
 * within a sorted array. Binary search compares the target value to the middle
 * element of the array. If they are not equal, the half in which the target
 * cannot lie is eliminated and the search continues on the remaining half,
 * again taking the middle element to compare to the target value, and repeating
 * this until the target value is found. If the search ends with the remaining
 * half being empty, the target is not in the array.
 *
 * ### Implementation
 *
 * Binary search works on sorted arrays. Binary search begins by comparing an
 * element in the middle of the array with the target value. If the target value
 * matches the element, its position in the array is returned. If the target
 * value is less than the element, the search continues in the lower half of
 * the array. If the target value is greater than the element, the search
 * continues in the upper half of the array. By doing this, the algorithm
 * eliminates the half in which the target value cannot lie in each iteration.
 *
 * ### Complexities
 *
 * N is the number of element in the array.
 *
 * Worst-case time complexity	O(log N)
 * Best-case time complexity	O(1)
 * Average time complexity	    O(log N)
 * Worst-case space complexity  0(1)
 */

ll Binary_Search(vll &arr, ll value)
{
    ll low(0), high(sz(arr) - 1);
    while (low <= high)
    {
        ll mid((low + high) >> 1);
        if (arr[mid] == value)
            return mid;
        else if (arr[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    Mesh_Ali;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    return 0;
}
