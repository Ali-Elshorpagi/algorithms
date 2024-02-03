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
#define fc(it, v) for (auto &(it) : (v))

class Solution
{
public:
    Solution() { __elshorpagi__; }
    bool possible(vi &houses, vi &heaters, int mid)
    {
        int j(0), len_houses(sz(houses));
        fc(it, heaters)
        {
            int left_coverage(it - mid), right_coverage(it + mid);
            while (j < len_houses && houses[j] >= left_coverage && houses[j] <= right_coverage)
                ++j;
        }
        return j == len_houses;
    }
    int findRadius(vi &houses, vi &heaters)
    {
        sort(all(heaters)), sort(all(houses));
        // u can make the right = max(max(houses), max(heaters));
        int ans(-1), left(0), right(1e9);
        while (left <= right)
        {
            int mid(left + ((right - left) >> 1));
            if (possible(houses, heaters, mid))
                ans = mid, right = mid - 1;
            else
                left = mid + 1;
        }
        return ans;
    }
    void TEST()
    {
        vi houses{1, 2, 3}, heaters{2};
        cout << findRadius(houses, heaters) << edl; // 1
        houses = {1, 2, 3, 4}, heaters = {1, 4};
        cout << findRadius(houses, heaters) << edl; // 1
        houses = {1, 5}, heaters = {2};
        cout << findRadius(houses, heaters) << edl; // 3
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