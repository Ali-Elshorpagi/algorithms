#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

#define _CRT_SECURE_NO_DEPRECATE
#define Sukuna (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define edl '\n'

/*
 * # Complexities
 *
 * Best-Case Time      O(N * K), where K is the max value
 * Worst-Case Time     O(D * (N + K)), where D is the no.digits of the max value ||
 * Worst-Case Space    O(N + K)
 *
 * Properties :
 *              1- Stable, it depends on the count sort
 *              2- Not In-Place (Out-Place)
 *              3- Not Adaptive
 *              4- Not Online (Offline)
 *              5- Non-Comparison Based
 */

class Algorithm
{
public:
    Algorithm() { Sukuna; }
    ~Algorithm() { cout << edl << "DONE" << edl; }

    vi Count_Sort(vi &arr, int place, int max_val)
    {
        int len(sz(arr));
        vi freq(max_val + 1);
        for (auto &it : arr)
            ++freq[(it / place) % 10];

        for (int i(1); i <= max_val; ++i)
            freq[i] += freq[i - 1];

        vi output(len);
        for (int i(len - 1); i > -1; --i)
        {
            output[freq[(arr[i] / place) % 10] - 1] = arr[i];
            --freq[(arr[i] / place) % 10];
        }
        return output;
    }
    void radix_sort(vi &arr)
    {
        // knowing max cus the max's digits = to the passes that the algorithm will do
        int max_val(*max_element(all(arr)));
        // Do counting sort for every digit.
        // instead of passing digit number, place is passed. place is 10^idx
        // where idx is current digit number
        for (int place(1); (max_val / place) > 0; place *= 10)
            arr = Count_Sort(arr, place, max_val);
    }
    void TEST()
    {
        vi arr{12, 2, 66, 4, 102, 5, 5, 45, 35, 87, 26, 9, 28, 28, 7};
        radix_sort(arr);
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