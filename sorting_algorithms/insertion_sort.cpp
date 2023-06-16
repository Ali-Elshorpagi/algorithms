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
        while (j > -1 && arr[j] > key) // right shifting
            arr[j + 1] = arr[j], --j;
        arr[j + 1] = key;
    }
}

void Insertion_Sort_1(vi &arr)
{
    int len(sz(arr));
    for (int i(1); i < len; i++)
    {
        for (int j(i); j - 1 > -1 && arr[j] < arr[j - 1]; --j)
            swap(arr[j], arr[j - 1]);
    }
}

void Insertion_Sort_Recursive(vi &arr, int size)
{
    if (size < 2)
        return;
    Insertion_Sort_Recursive(arr, size - 1);
    int last(arr[size - 1]), j(size - 2);
    while (j > -1 && arr[j] > last)
        arr[j + 1] = arr[j], --j;
    arr[j + 1] = last;
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
    // cin >> tc;
    while (tc--)
    {
        cout << "Case #" << tc + 1 << edl;
        sol.TEST();
        cout << edl << "DONE" << edl;
    }
    return (0);
}