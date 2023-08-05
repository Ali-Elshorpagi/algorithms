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
    bool possible(vi &arr, int mid, int m, int k)
    {
        int cnt(0), bouquets(0);
        fc(it, arr)
        {
            if (it - mid < 1)
            {
                ++cnt;
                if (cnt == k)
                    cnt = 0, ++bouquets;
                if (bouquets == m)
                    return true;
            }
            else
                cnt = 0;
        }
        return false;
    }
    int minDays(vi &bloomDay, int m, int k)
    {
        int ans(-1), left(*min_element(all(bloomDay))), right(*max_element(all(bloomDay)));
        while (left <= right)
        {
            int mid(left + ((right - left) >> 1)); // the mid == days;
            if (possible(bloomDay, mid, m, k))
                ans = mid, right = mid - 1;
            else
                left = mid + 1;
        }
        return ans;
    }
    void TEST()
    {
        vi bloomDay{1, 10, 3, 10, 2};
        int m(3), k(1);
        cout << minDays(bloomDay, m, k) << edl; // 3
        bloomDay = {7, 7, 7, 7, 12, 7, 7}, m = 2, k = 3;
        cout << minDays(bloomDay, m, k) << edl; // 12
        bloomDay = {1, 10, 3, 10, 2}, m = 3, k = 2;
        cout << minDays(bloomDay, m, k) << edl; // -1
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