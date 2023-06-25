#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<double> vd;
typedef vector<vd> vvd;

#define _CRT_SECURE_NO_DEPRECATE
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)
#define fl(i, x, n) for (int i(x); i > n; --i)
#define fc(it, v) for (auto &(it) : (v))

/*
 * # Complexities
 *
 * Best-Case Time     O(N + K)
 * Worst-Case Time    O(N^2)
 * Worst-Case Space   O(N * K)
 *
 * Properties :
 *              1- Stable
 *              2- Not In-Place (Out-Place)
 *              3- Not Adaptive
 *              4- Not Online (Offline)
 *              5- Non-Comparison Based, but it can implemented to become Comparison Based
 *  Note : it's work on real numbers
 */

class Algorithm
{
public:
    void Bucket_Sort(vd &arr, int no_buckets)
    {
        int len(sz(arr));
        double max_val(*max_element(all(arr))),
            min_val(*min_element(all(arr))),
            range((max_val - min_val) / no_buckets);

        vvd tmp(no_buckets);
        for (int i(0); i < len; ++i)
        {
            double diff(((arr[i] - min_val) / range) - int(((arr[i] - min_val) / range)));
            if (!diff && arr[i] != min_val)
                tmp[int((arr[i] - min_val) / range) - 1].emplace_back(arr[i]);
            else
                tmp[int((arr[i] - min_val) / range)].emplace_back(arr[i]);
        }
        for (int i(0); i < sz(tmp); ++i)
        {
            if (!tmp[i].empty())
                sort(all(tmp[i]));
        }
        int k(0);
        for (auto &lst : tmp)
        {
            if (!lst.empty())
            {
                for (auto i : lst)
                    arr[k] = i, ++k;
            }
        }
    }
    void TEST()
    {
        int n;
        cin >> n;
        vd arr(n);
        for (auto &it : arr)
            cin >> it;
        Bucket_Sort(arr, n);
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