#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fc(it, v) for (auto &(it) : (v))

class Solution
{
public:
    Solution() { Mesh_Ali; }
    void count_sort(vi &arr)
    {
        int min_(*min_element(all(arr))), limit(1e4);
        vi frequency_arr(limit - min_ + 1);
        fc(it, arr) { ++frequency_arr[it - min_]; }
        for (int idx(0), i(0); i < (limit - min_ + 1); ++i)
        {
            if (frequency_arr[i])
            {
                for (int j(0); j < frequency_arr[i]; ++j)
                    arr[idx++] = i + min_;
            }
        }
    }
    int arrayPairSum(vi &arr)
    {
        count_sort(arr);
        // sort(all(arr));
        int len(sz(arr)), ans(0);
        for (int i(0); i < len; i += 2)
            ans += arr[i];
        return ans;
    }

    void TEST()
    {
        vi arr{1, 4, 3, 2};
        cout << arrayPairSum(arr) << edl; // 4
        arr = {6, 2, 6, 5, 1, 2};
        cout << arrayPairSum(arr) << edl; // 9
    }
};

int main()
{
    Solution sol;
    // freopen("../../test/input.txt", "r", stdin);
    freopen("../../test/output.txt", "w", stdout);
    int tc(1);
    // cin >> tc;
    while (tc--)
        cout << "Case #" << tc + 1 << edl, sol.TEST();
    cout << edl << "DONE" << edl;
    return (0);
}