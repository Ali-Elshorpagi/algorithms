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
#define fr(i, x, n) for (int i(x); i < n; ++i)
#define fl(i, x, n) for (int i(x); i > n; --i)

class Solution
{
public:
    Solution() { Mesh_Ali; }
    int findUnsortedSubarray_(vi &arr) // O(N * log(N)) time, O(N) space
    {
        vi tmp = arr;
        sort(all(arr));
        if (arr == tmp)
            return 0;
        int len(sz(arr)), right(-1), left(-1);
        fr(i, 0, len)
        {
            if (arr[i] != tmp[i])
            {
                left = i;
                break;
            }
        }
        fl(j, len - 1, -1)
        {
            if (arr[j] != tmp[j])
            {
                right = j;
                break;
            }
        }
        return (right - left) + 1;
    }
    int findUnsortedSubarray(vi &arr) // O(N) time, O(1) space
    {
        int min_(INT_MAX), max_(INT_MIN), len(sz(arr)), right(-1), left(-1);
        // find the leftmost index of the unsorted subarray
        fr(i, 0, len)
        {
            if (arr[i] < max_)
                right = i;
            else
                max_ = arr[i];
        }
        // find the rightmost index of the unsorted subarray
        fl(j, len - 1, -1)
        {
            if (arr[j] > min_)
                left = j;
            else
                min_ = arr[j];
        }
        return left == -1 && right == -1 ? 0 : (right - left) + 1;
    }
    void TEST()
    {
        vi arr{2, 6, 4, 8, 10, 9, 15};
        cout << findUnsortedSubarray(arr) << edl; // 5
        arr = {1, 2, 3, 4};
        cout << findUnsortedSubarray(arr) << edl; // 0
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