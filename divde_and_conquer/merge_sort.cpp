#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define _CRT_SECURE_NO_DEPRECATE
#define Sukuna (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'

/*
 * # Complexities
 *
 * Best-Case Time     O(N * log(N))
 * Worst-Case Time    O(N * log(N))
 * Worst-Case Space   O(N)
 *
 * # Properties :
 *              1- Stable
 *              2- Not In-Place
 *              3- Not Adaptive
 *              4- Not Online (Offline)
 *              5- Comparison Based
 *
 */

class Solution
{
public:
    Solution() { Sukuna; }
    void Merge(vi &arr, int left, int mid, int right)
    {
        int len_left(mid - left + 1), len_right(right - mid);
        vi left_arr(len_left), right_arr(len_right);

        for (int i(0); i < len_left; ++i)
            left_arr[i] = arr[left + i];

        for (int j(0); j < len_right; ++j)
            right_arr[j] = arr[mid + 1 + j];

        int x(0), y(0), k(left);
        while (x < len_left || y < len_right)
        {
            if (y >= len_right || (x < len_left && left_arr[x] <= right_arr[y]))
                arr[k] = left_arr[x], ++x;
            else
                arr[k] = right_arr[y], ++y;
            ++k;
        }
    }
    void Merge_Sort(vi &arr, int begin, int end)
    {
        if (begin >= end)
            return;
        int mid(begin + ((end - begin) >> 1));
        Merge_Sort(arr, begin, mid);
        Merge_Sort(arr, mid + 1, end);
        Merge(arr, begin, mid, end);
    }
    void TEST()
    {
        vi arr{12, 35, 87, 26, 9, 28, 7};
        Merge_Sort(arr, 0, sz(arr) - 1);
        for (auto &it : arr)
            cout << it << ' ';
    }
};

int main()
{
    Solution sol;
    // freopen("../test/input.txt", "r", stdin);
    freopen("../test/output.txt", "w", stdout);
    int tc(1);
    // cin >> tc;
    while (tc--)
        cout << "Case #" << tc + 1 << edl, sol.TEST();
    cout << edl << "DONE" << edl;
    return (0);
}