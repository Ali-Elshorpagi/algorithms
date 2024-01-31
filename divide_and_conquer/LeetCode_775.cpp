#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)
#define yes cout << "YES\n"
#define no cout << "NO\n"

class Solution
{
    vi tmp;

public:
    Solution() { __elshorpagi__; }
    ll merge_(vi &arr, int start, int md, int end)
    {
        ll global_inversions(0);
        for (int i(start), j(md + 1), k(start); k <= end; ++k)
        {
            if (i > md) // start is done
                tmp[k] = arr[j++];
            else if (j > end) // end is done
                tmp[k] = arr[i++];
            else if (arr[i] < arr[j]) // start is smaller
                tmp[k] = arr[i++];
            else
                tmp[k] = arr[j++], global_inversions += md - i + 1;
        }
        for (int i(start); i <= end; ++i)
            arr[i] = tmp[i];
        return global_inversions;
    }
    ll merge_sort(vi &arr, int begin, int end)
    {
        if (begin >= end)
            return 0;
        int mid(begin + ((end - begin) >> 1));
        ll global_inversions(merge_sort(arr, begin, mid));
        global_inversions += merge_sort(arr, mid + 1, end);
        global_inversions += merge_(arr, begin, mid, end);
        return global_inversions;
    }
    bool isIdealPermutation(vi &nums)
    {
        tmp = nums;
        ll local_inversions(0);
        fr(i, 0, sz(nums) - 1)
        {
            if (nums[i] > nums[i + 1])
                ++local_inversions;
        }
        ll global_inversions(merge_sort(nums, 0, sz(nums) - 1));
        return local_inversions == global_inversions;
    }
    void TEST()
    {
        vi nums{1, 0, 2};
        isIdealPermutation(nums) ? yes : no; // YES
        nums = {1, 2, 0};
        isIdealPermutation(nums) ? yes : no; // NO
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