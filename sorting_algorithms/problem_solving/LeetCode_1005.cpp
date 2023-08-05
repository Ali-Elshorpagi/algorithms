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
    int largestSumAfterKNegations(vi &arr, int k)
    {
        sort(all(arr));
        int i(0), len(sz(arr)), sum(0), min_(INT_MAX);
        while (k && i < len && arr[i] < 0)
        {
            arr[i] = -arr[i];
            --k, ++i;
        }
        if (k & 1)
        {
            min_ = min_element(all(arr)) - arr.begin();
            arr[min_] = -arr[min_];
        }
        fc(it, arr) sum += it;
        return sum;
    }
    int largestSumAfterKNegations_(vi &arr, int k)
    {
        sort(all(arr));
        int i(0), len(sz(arr)), sum(0), min_(INT_MAX);
        while (i < len)
        {
            if (k && arr[i] < 0)
                arr[i] = -arr[i], --k;
            sum += arr[i];
            min_ = min(min_, arr[i]);
            ++i;
        }
        if (k & 1)
            sum -= (min_ << 1); // multiply by 2 cus we add it to sum in the above while-loop
        return sum;
    }

    void TEST()
    {
        vi arr{4, 2, 3};
        int k(1);
        cout << largestSumAfterKNegations(arr, k) << edl; // 5
        arr = {3, -1, 0, 2}, k = 3;
        cout << largestSumAfterKNegations(arr, k) << edl; // 6
        arr = {2, -3, -1, 5, -4}, k = 2;
        cout << largestSumAfterKNegations(arr, k) << edl; // 13
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