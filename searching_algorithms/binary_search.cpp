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
 * Best-Case Time     O(1)
 * Worst-Case Time    O(log N)
 * Worst-Case Space   O(1), but in recursive implementation will be O(log N)
 */

ll Binary_Search(vll &arr, ll value)
{
    ll low(0), high(sz(arr) - 1);
    while (low <= high)
    {
        // we can use ==> mid = low + (high - low + 1) / 2; it's depends on problem
        ll mid(low + ((high - low) >> 1));
        if (arr[mid] == value)
            return mid;
        else if (arr[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

ll Binary_Search_Recursive(vll &arr, ll low, ll high, ll value)
{
    if (high >= low)
    {
        ll mid(low + ((high - low) >> 1));
        if (arr[mid] == value)
            return mid;
        if (arr[mid] > value)
            return Binary_Search_Recursive(arr, low, mid - 1, value);
        return Binary_Search_Recursive(arr, mid + 1, high, value);
    }
    return -1;
}

int main()
{
    Mesh_Ali;
    // freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cout << edl << "DONE" << edl;
    return (0);
}
