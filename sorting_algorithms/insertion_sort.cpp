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
 * Best-Case Time      O(N)
 * Worst-Case Time     O(N²)
 * Worst-Case Space    O(1)
 */

void Insertion_Sort_0(vi &arr)
{
    int key, j, len(sz(arr));
    for (int i(1); i < len; ++i)
    {
        key = arr[i], j = i - 1;
        while (j > -1 && arr[j] > key) // shift right
            arr[j + 1] = arr[j], --j;
        arr[j + 1] = key;
    }
}

void Insertion_Sort_1(vi &arr)
{
    int len(sz(arr));
    for (int i(1); i < len; i++)
        for (int j(i); j - 1 > -1 && arr[j] < arr[j - 1]; --j)
            swap(arr[j], arr[j - 1]);
}

void Insertion_Sort_Recursive(vi &arr, int size)
{
    if (size <= 1)
        return;
    Insertion_Sort_Recursive(arr, size - 1);
    int last(arr[size - 1]), j(size - 2);
    while (j > -1 && arr[j] > last)
        arr[j + 1] = arr[j], --j;
    arr[j + 1] = last;
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