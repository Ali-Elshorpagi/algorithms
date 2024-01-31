#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
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
 *              2- In-Place
 *              3- Not Adaptive
 *              4- Not Online (Offline)
 *              5- Comparison Based
 *
 */

class Algorithm
{
public:
    Algorithm() { __elshorpagi__; }
    ~Algorithm() { cout << edl << "DONE" << edl; }

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
    void TEST()
    {
        vi arr{12, 2, -66, -4, 102, 5, 5, 45, -35, -87, 26, 9, 28, 28, 7};
        Heap_Sort(arr);
        for (auto &it : arr)
            cout << it << ' ';
    }
};

int main()
{
    Algorithm algo;
    // freopen("../test/input.txt", "r", stdin);
    freopen("../test/output.txt", "w", stdout);
    int tc(1);
    // cin >> tc;
    while (tc--)
        cout << "Case #" << tc + 1 << edl, algo.TEST();
    return (0);
}