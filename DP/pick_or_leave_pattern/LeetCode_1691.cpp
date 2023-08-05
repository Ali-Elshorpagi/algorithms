#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fc(it, v) for (auto &(it) : (v))

class Solution
{
    vvi memory; // for Memoization
public:
    Solution() { Mesh_Ali, memory.resize(105, vi(105, -1)); }
    bool is_valid(vvi &cuboids, int cur_idx, int prev_idx)
    {
        // you don't need to compare on [0] as sorting does
        if (cuboids[cur_idx][1] >= cuboids[prev_idx][1])
            if (cuboids[cur_idx][2] >= cuboids[prev_idx][2])
                return true;
        return false;
    }
    int dp(vvi &cuboids, int cur_idx, int prev_idx)
    {
        if (cur_idx >= sz(cuboids))
            return 0;
        // +1 cuz its start with -1, so it will access to garbage or RTE
        auto &ref(memory[cur_idx][prev_idx + 1]);
        if (ref != -1)
            return ref;
        int pick(0);
        if (prev_idx == -1 || is_valid(cuboids, cur_idx, prev_idx)) // pick
            pick = cuboids[cur_idx][2] + dp(cuboids, cur_idx + 1, cur_idx);
        int leave(dp(cuboids, cur_idx + 1, prev_idx)); // leavve
        return ref = max(pick, leave);
    }
    int maxHeight(vvi &cuboids)
    {
        // sort every vector in matrix
        fc(it, cuboids) { sort(all(it)); }
        sort(all(cuboids)); // sort the whole matrix
        // fc(i, cuboids) { fc(j, i) { cout << j << ' ' ; } cout << edl; }
        return dp(cuboids, 0, -1);
    }
    void TEST()
    {
        // vvi cuboids{{50, 45, 20}, {95, 37, 53}, {45, 23, 12}};
        // cout << maxHeight(cuboids) << edl; // 190
        // vvi cuboids{{7, 11, 17}, {7, 17, 11}, {11, 7, 17}, {11, 17, 7}, {17, 7, 11}, {17, 11, 7}};
        // cout << maxHeight(cuboids) << edl; // 102
        vvi cuboids{{38, 25, 45}, {76, 35, 3}};
        cout << maxHeight(cuboids) << edl; // 76
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