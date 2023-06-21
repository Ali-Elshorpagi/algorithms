#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'

/*
 * # Complexities
 *
 * Best-Case Time     O(N)
 * Worst-Case Time    O(N^2)
 * Worst-Case Space   O(1)
 *
 * Properties :
 *              1- Stable
 *              2- In-Place
 *              3- Adaptive
 *              4- Online // not sure
 *              5- Comparison Based
 *
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
        if (!swapped) // that's mean the array is sorted
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

class Solution
{
public:
    Solution() { Mesh_Ali; }
    void TEST() {}
};

int main()
{
    Solution sol;
    // freopen("../test/input.txt", "r", stdin);
    freopen("../test/output.txt", "w", stdout);
    int tc(1);
    cin >> tc;
    while (tc--)
        cout << "Case #" << tc + 1 << edl, sol.TEST();
    cout << edl << "DONE" << edl;
    return (0);
}