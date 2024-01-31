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
 * Best-Case Time      O(N)
 * Worst-Case Time     O(N^2)
 * Worst-Case Space    O(1)
 *
 * Properties :
 *              1- Stable
 *              2- In-Place
 *              3- Adaptive
 *              4- Online
 *              5- Comparison Based
 *
 */

class Algorithm
{
public:
    Algorithm() { __elshorpagi__; }
    ~Algorithm() { cout << edl << "DONE" << edl; }

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
    void TEST()
    {
        vi arr{12, 2, -66, -4, 102, 5, 5, 45, -35, -87, 26, 9, 28, 28, 7};
        // Insertion_Sort_0(arr);
        // Insertion_Sort_1(arr);
        Insertion_Sort_Recursive(arr, sz(arr));
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