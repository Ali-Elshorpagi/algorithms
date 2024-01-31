#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)

class Solution
{
public:
    Solution() { __elshorpagi__; }
    int triangleNumber_(vi &nums) // O(N^2) time, O(1) space
    {
        int cnt(0), len(sz(nums));
        sort(all(nums));
        fr(i, 0, len - 2)
        {
            int k(i + 2);
            for (int j(i + 1); j < len - 1 && nums[i]; ++j)
            {
                while (k < len && nums[i] + nums[j] > nums[k])
                    ++k;
                cnt += k - j - 1;
            }
        }
        return cnt;
    }
    int BS(vi &arr, int left, int target)
    {
        int right(sz(arr) - 1), pos(sz(arr));
        while (left <= right)
        {
            int mid(left + ((right - left) >> 1));
            if (arr[mid] >= target)
                pos = mid, right = mid - 1;
            else
                left = mid + 1;
        }
        return pos;
    }
    int triangleNumber(vi &arr) // O(N^2 * log(N)) time, O(1) space
    {
        sort(all(arr));
        int cnt(0), len(sz(arr));
        fr(i, 0, len - 2)
        {
            int k(i + 2);
            for (int j(i + 1); j < len - 1 && arr[i]; ++j)
            {
                int idx(BS(arr, k, arr[i] + arr[j]));
                // all values starting from idx are invalid
                cnt += idx - j - 1; // the values between j and (idx - 1) are the possible ones
            }
        }
        return cnt;
    }
    void TEST()
    {
        vi arr{2, 2, 3, 4};
        cout << triangleNumber(arr) << edl; // 3
        arr = {4, 2, 3, 4};
        cout << triangleNumber(arr) << edl; // 4
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