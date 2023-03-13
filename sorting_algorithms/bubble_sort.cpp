#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vpii = vector<pii>;
using vc = vector<char>;

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
#define yes cout << "YES\n"
#define no cout << "NO\n"

/*
 * # Complexities
 *
 * Best-Case Time     O(N)
 * Worst-Case Time    O(N²)
 * Worst-Case Space   O(1)
 */

void Bubble_Sort(vi &arr)
{
    int len(sz(arr));
    for (int i(0); i < len - 1; ++i)
    {
        bool swapped(false);
        for (int j(0); j < len - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]), swapped = true;
        }
        if (!swapped)
            break;
    }
}

void Bubble_Sort_Recursive(vi &arr, int size)
{
    if (size == 1)
        return;
    for (int i(0); i < size - 1; ++i)
    {
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
    }
    Bubble_Sort_Recursive(arr, size - 1);
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