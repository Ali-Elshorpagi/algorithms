#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<char> vc;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define cl(v) ((v).clear())
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)
#define fl(i, x, n) for (int i(x); i > n; --i)
#define fc(it, v) for (auto &(it) : (v))
#define sq(x) (x) * (x)
#define yes printf("YES\n")
#define no printf("NO\n")

/*
 * # Complexities
 *
 * Best-Case Time     O(1)
 * Worst-Case Time    O(log N)
 * Worst-Case Space   O(1), but in recursive implementation will be O(log N)
 */

int Binary_Search(vi &arr, int value)
{
    int left(0), right(sz(arr) - 1);
    while (left <= right)
    {
        // we can use ==> mid = left + (right - left + 1) / 2; it's depends on problem
        int mid(left + ((right - left) >> 1));
        if (arr[mid] == value)
            return mid;
        else if (arr[mid] > value)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int Binary_Search_Recursive(vi &arr, int left, int right, int value)
{
    if (right >= left)
    {
        int mid(left + ((right - left) >> 1));
        if (arr[mid] == value)
            return mid;
        if (arr[mid] > value)
            return Binary_Search_Recursive(arr, left, mid - 1, value);
        return Binary_Search_Recursive(arr, mid + 1, right, value);
    }
    return -1;
}

void Solve()
{
    // test functions here;
    cout << edl << "DONE" << edl;
}

int main()
{
    Mesh_Ali;
    // freopen("../test/input.txt", "r", stdin);
    freopen("../test/output.txt", "w", stdout);
    int tc(1);
    // scanf("%d", &tc);
    while (tc--)
        Solve();
    return (0);
}