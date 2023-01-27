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
 * Linear Search is defined as a sequential search algorithm that starts at one end and goes
 * through each element of a list until the desired element is found,
 * otherwise the search continues till the end of the data set.
 * It is the easiest searching algorithm

 * # Complexities
 *
 * N is the number of element in the array.
 *
 * Worst-case time complexity	O(N)
 * Worst-case space complexity  O(N)
 * Space complexity             O(1)
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

int main()
{
    Mesh_Ali;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    return 0;
}