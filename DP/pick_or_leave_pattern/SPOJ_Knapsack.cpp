#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pair<int, int>> vpii;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fc(it, v) for (auto &(it) : (v))

class Solution
{
    vpii arr;
    vvi memory; // for Memoization

public:
    Solution() { __elshorpagi__, memory.resize(2001, vi(2001, -1)); }
    // arr[idx].first = weights[idx];
    // arr[idx].second = values[idx];
    // s = limits || max weight;
    // remains = history weight;
    int dp(int idx, int remains)
    {
        if (idx == sz(arr))
            return 0;
        auto &ref(memory[idx][remains]);
        if (ref != -1)
            return ref;
        int pick(0);
        if (remains >= arr[idx].first)
            pick = arr[idx].second + dp(idx + 1, remains - arr[idx].first);
        int leave(dp(idx + 1, remains));
        return ref = max(pick, leave);
    }
    void TEST()
    {
        int s, n;
        cin >> s >> n;
        arr.resize(n);
        fc(it, arr) { cin >> it.first >> it.second; }
        cout << dp(0, s) << edl;
    }
};

int main()
{
    Solution sol;
    freopen("../../test/input.txt", "r", stdin);
    freopen("../../test/output.txt", "w", stdout);
    int tc(1);
    // cin >> tc;
    while (tc--)
        cout << "Case #" << tc + 1 << edl, sol.TEST();
    cout << edl << "DONE" << edl;
    return (0);
}