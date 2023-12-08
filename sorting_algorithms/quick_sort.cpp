#include <iostream>
#include <vector>
#include <random>

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
 * Worst-Case Time    O(N^2)
 * Worst-Case Space   O(N) - log(N)
 *
 * # Properties :
 *              1- Not Stable
 *              2- In-Place : Depends on the implementation
 *              3- Not Adaptive
 *              4- Not Online (Offline)
 *              5- Comparison Based
 */

class Algorithm
{
public:
    Algorithm() { Sukuna; }
    ~Algorithm() { cout << edl << "DONE" << edl; }

    void quick_sort(vi &arr, int low, int high)
    {
        if (low >= high)
            return;

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distribution(low, high);

        int random_index(distribution(gen)), pivot(arr[random_index]);

        swap(arr[low], arr[random_index]);

        int i(low + 1), j(high);
        while (i <= j)
        {
            while (i <= high && arr[i] <= pivot)
                ++i;
            while (j >= low && arr[j] > pivot)
                --j;
            if (i < j)
                swap(arr[i], arr[j]);
        }

        swap(arr[low], arr[j]);

        quick_sort(arr, low, j - 1);
        quick_sort(arr, j + 1, high);
    }
    int partition(vi &arr, int start, int end)
    {
        int i(start), j(end), pivot(start);
        while (true)
        {
            while (arr[pivot] <= arr[j] && pivot != j)
                --j;
            if (pivot == j)
                break;
            else if (arr[pivot] > arr[j])
                swap(arr[j], arr[pivot]), pivot = j;
            while (arr[pivot] >= arr[i] && pivot != i)
                ++i;
            if (pivot == i)
                break;
            else if (arr[pivot] < arr[i])
                swap(arr[i], arr[pivot]), pivot = i;
        }
        return pivot;
    }
    void quick_sort_(vi &arr, int low, int high)
    {
        if (low < high)
        {
            int pivot(partition(arr, low, high));
            quick_sort_(arr, low, pivot - 1);
            quick_sort_(arr, pivot + 1, high);
        }
    }
    void TEST()
    {
        vi arr{12, 2, -66, -4, 102, 5, 5, 45, -35, -87, 26, 9, 28, 28, 7};
        // quick_sort(arr, 0, sz(arr) - 1);
        quick_sort_(arr, 0, sz(arr) - 1);
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