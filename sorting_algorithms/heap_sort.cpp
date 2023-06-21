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
 * Best-Case Time     O(N * log(N))
 * Worst-Case Time    O(N * log(N))
 * Worst-Case Space   O(1)
 *
 * Properties :
 *              1- Not Stable
 *              2- Not In-Place
 *              3- Adaptive
 *              4- Not Online
 *              5- Comparison Based
 *
 */

void Heapify(vi &arr, int n, int i)
{
    int largest(i), left((i << 1) + 1), right((i << 1) + 2);
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        Heapify(arr, n, largest);
    }
}

void Heap_Sort(vi &arr)
{
    int len(sz(arr));
    for (int i((len >> 1) - 1); i > -1; --i)
        Heapify(arr, len, i);

    for (int j(len - 1); j > -1; --j)
    {
        swap(arr[0], arr[j]);
        Heapify(arr, j, 0);
    }
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