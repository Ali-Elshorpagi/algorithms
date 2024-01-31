#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

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
    bool possible(vi &arr, int mid, int threshold)
    {
        int sum(0), len(sz(arr));
        fr(i, 0, len)
        {
            // sum += (arr[i] + mid - 1) / mid;
            sum += ceil((double)arr[i] / mid);
        }
        return sum <= threshold;
    }
    int smallestDivisor(vi &arr, int threshold)
    {
        int left(1), right(*max_element(all(arr))), ans(0);
        while (left <= right)
        {
            int mid(left + ((right - left) >> 1));
            if (possible(arr, mid, threshold))
                ans = mid, right = mid - 1;
            else
                left = mid + 1;
        }
        return ans;
    }
    void TEST()
    {
        vi arr{1, 2, 5, 9};
        int threshold(6);
        cout << smallestDivisor(arr, threshold) << edl; // 5
        arr = {44, 22, 33, 11, 1}, threshold = 5;
        cout << smallestDivisor(arr, threshold) << edl; // 44
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