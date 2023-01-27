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
 * Bubble sort algorithm is the bubble sorting algorithm. The most important reason
 * for calling the bubble is that the largest number is thrown at the end of this
 * algorithm. This is all about the logic. In each iteration, the largest number is
 * expired and when iterations are completed, the sorting takes place.
 *
 * What is Swap?
 *
 * Swap in the software means that two variables are displaced.
 * An additional variable is required for this operation. x = 5, y = 10.
 * We want x = 10, y = 5. Here we create the most variable to do it.
 * int z;
 * z = x;
 * x = y;
 * y = z;
 *
 * The above process is a typical displacement process.
 * When x assigns the value to x, the old value of x is lost.
 * That's why we created a variable z to create the first value of the value of x,
 * and finally, we have assigned to y
 *
 * ### Complexities
 *
 * N is the number of element in the array
 *
 * Worst-Case complexity   O(N²)
 * Best-Case complexity    O(N)
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

int main()
{
    Mesh_Ali;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    return 0;
}