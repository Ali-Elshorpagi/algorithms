#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)
#define fc(it, v) for (auto &(it) : (v))

class Solution
{
public:
    Solution() { __elshorpagi__; }
    int BS(vpii &startings, int target)
    {
        int left(0), right(sz(startings) - 1), pos(-1);
        while (left <= right)
        {
            int mid(left + ((right - left) >> 1));
            if (startings[mid].first < target)
                left = mid + 1;
            else if (startings[mid].first >= target) // lower-bound
                pos = mid, right = mid - 1;
        }
        return pos;
    }
    vi findRightInterval(vvi &intervals)
    {
        int len(sz(intervals));
        vpii startings;
        fr(i, 0, len) { startings.push_back({intervals[i][0], i}); } // push the start with his idx
        sort(all(startings));
        vi ans(len, -1);
        fr(i, 0, len)
        {
            int idx(BS(startings, intervals[i][1])); // u can use lower_bound() instead of BS()
            if (idx != -1)
                ans[i] = startings[idx].second;
        }
        return ans;
    }
    void TEST()
    {
        vvi intervals{{3, 4}, {2, 3}, {1, 2}};
        vi ans = findRightInterval(intervals); // [-1, 0, 1]
        fc(it, ans) { cout << it << ' '; }
        cout << edl;
        intervals = {{1, 4}, {2, 3}, {3, 4}};
        ans = findRightInterval(intervals);
        fc(it, ans) { cout << it << ' '; } // [-1, 2, -1]
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