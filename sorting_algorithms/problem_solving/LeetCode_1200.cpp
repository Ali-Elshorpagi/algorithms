#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)
#define yes cout << "YES\n"
#define no cout << "NO\n"

// O(N) space if result vector is considered

class Solution
{
public:
    Solution() { __elshorpagi__; }
    vvi minimumAbsDifference(vi &arr)
    {
        sort(all(arr));
        int abs_differ(arr[1] - arr[0]), len(sz(arr));
        fr(i, 1, len)
        {
            if (arr[i] - arr[i - 1] < abs_differ)
                abs_differ = arr[i] - arr[i - 1];
        }
        vvi ans;
        fr(i, 0, len - 1)
        {
            if (arr[i + 1] - arr[i] == abs_differ)
                ans.push_back({arr[i], arr[i + 1]});
        }
        return ans;
    }
    void TEST()
    {
        vi arr{4, 2, 1, 3};
        vvi res{{1, 2}, {2, 3}, {3, 4}};
        res == minimumAbsDifference(arr) ? yes : no;
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