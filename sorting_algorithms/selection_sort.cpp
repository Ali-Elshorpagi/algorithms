#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

#define _CRT_SECURE_NO_DEPRECATE
#define sz(v) ((int)((v).size()))
#define edl '\n'

/*
 * # Complexities
 *
 * Best-Case Time      O(N^2)
 * Worst-Case Time     O(N^2)
 * Worst-Case Space    O(1)
 *
 * Properties :
 *              1- Not Stable
 *              2- In-Place
 *              3- Not Adaptive
 *              4- Not Online (Offline)
 *              5- Comparison Based
 */

class Algorithm
{
public:
    void Selection_Sort(vi &arr)
    {
        int min_idx, len(sz(arr));
        for (int i(0); i < len - 1; ++i)
        {
            min_idx = i;
            for (int j(i + 1); j < len; ++j) // Find the minimum element in unsorted array
            {
                if (arr[j] < arr[min_idx])
                    min_idx = j;
            }
            if (min_idx != i)
                swap(arr[min_idx], arr[i]); // Put the min in its right place
        }
    }
    int min_idx(vi &arr, int i, int j)
    {
        if (i == j)
            return i;
        int k(min_idx(arr, i + 1, j));
        return (arr[i] < arr[k]) ? i : k;
    }
    void Selection_Sort_Recursive(vi &arr, int n, int index = 0)
    {
        if (index == n)
            return;
        int k(min_idx(arr, index, n - 1));
        if (k != index)
            swap(arr[k], arr[index]);
        Selection_Sort_Recursive(arr, n, index + 1);
    }
    void TEST()
    {
        int n;
        cin >> n;
        vi arr(n);
        for (auto &it : arr)
            cin >> it;
        // Selection_Sort(arr);
        Selection_Sort_Recursive(arr, n);
        for (auto &it : arr)
            cout << it << ' ';
    }
};

int main()
{
    Algorithm algo;
    freopen("../test/input.txt", "r", stdin);
    freopen("../test/output.txt", "w", stdout);
    int tc(1);
    // cin >> tc;
    while (tc--)
        cout << "Case #" << tc + 1 << edl, algo.TEST();
    cout << edl << "DONE" << edl;
    return (0);
}