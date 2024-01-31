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
    int eliminateMaximum(vi &dist, vi &speed)
    {
        int len(sz(dist));
        vector<double> time(len);
        fr(i, 0, len) { time[i] = ceil((double)dist[i] / speed[i]); }
        sort(all(time));
        int cnt(0);
        fr(i, 0, len)
        {
            if (i >= time[i]) // i here equal my-time
                break;
            ++cnt;
        }
        return cnt;
    }
    void TEST()
    {
        vi dist{1, 3, 4}, speed{1, 1, 1};
        cout << eliminateMaximum(dist, speed) << edl; // 3
        dist = {1, 1, 2, 3}, speed = {1, 1, 1, 1};
        cout << eliminateMaximum(dist, speed) << edl; // 1
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