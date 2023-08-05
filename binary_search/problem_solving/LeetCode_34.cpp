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

class Solution
{
public:
    Solution() { Mesh_Ali; }
    vi searchRange_(vi &arr, int target) // using built-in functions
    {
        auto indices(equal_range(all(arr), target));
        int left(indices.first - arr.begin()),
            right((indices.second - arr.begin()));
        if (binary_search(all(arr), target))
            return {left, right - 1};
        return {-1, -1};
    }
    vi searchRange(vi &arr, int target)
    {
        int left(0), right(sz(arr) - 1),
            first_idx(-1), last_idx(-1);
        while (left <= right)
        {
            int mid(left + ((right - left) >> 1));
            if (arr[mid] == target)
                first_idx = mid, right = mid - 1;
            else if (arr[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        left = 0, right = sz(arr) - 1;
        while (left <= right)
        {
            int mid(left + ((right - left) >> 1));
            if (arr[mid] == target)
                last_idx = mid, left = mid + 1;
            else if (arr[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return {first_idx, last_idx};
    }
    void TEST()
    {
        vi arr{5, 7, 7, 8, 8, 10};
        int target(8);
        vi ans = searchRange(arr, target);
        cout << ans[0] << ' ' << ans[1] << edl; // [3, 4]
        target = 6;
        ans = searchRange(arr, target);
        cout << ans[0] << ' ' << ans[1] << edl; // [-1, -1]
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