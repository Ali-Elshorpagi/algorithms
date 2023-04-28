#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)

// link : https://leetcode.com/problems/count-sub-islands/
// code : leetcode 1905

class Solution // O(N * M) time, O(N * M) space
{
    vi dr{-1, 0, 1, 0}; // Delta for: up, right, down, left
    vi dc{0, 1, 0, -1};
    bool is_sub;

public:
    Solution() { Mesh_Ali; }
    bool is_valid(int new_row, int new_col, vvi &g2)
    {
        if (new_row < 0 || new_row >= sz(g2) || new_col < 0 || new_col >= sz(g2[0]))
            return false;
        return true;
    }
    void dfs(vvi &g1, vvi &g2, int i, int j)
    {
        if (!is_valid(i, j, g2) || !g2[i][j])
            return;
        is_sub &= (g2[i][j] == g1[i][j]);
        g2[i][j] = 0; // mark as visited
        fr(d, 0, 4) dfs(g1, g2, i + dr[d], j + dc[d]);
    }
    int countSubIslands(vvi &g1, vvi &g2)
    {
        int ans(0);
        fr(i, 0, sz(g2))
        {
            fr(j, 0, sz(g2[0]))
            {
                if (g2[i][j]) // the grid itself also marks the visited nodes
                {
                    is_sub = true;
                    dfs(g1, g2, i, j);
                    ans += is_sub;
                }
            }
        }
        return ans;
    }
    void TEST()
    {
        vvi g1{{1, 1, 1, 0, 0}, {0, 1, 1, 1, 1}, {0, 0, 0, 0, 0}, {1, 0, 0, 0, 0}, {1, 1, 0, 1, 1}};
        vvi g2{{1, 1, 1, 0, 0}, {0, 0, 1, 1, 1}, {0, 1, 0, 0, 0}, {1, 0, 1, 1, 0}, {0, 1, 0, 1, 0}};
        cout << countSubIslands(g1, g2) << edl;
        // Output: 3;
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
    {
        cout << "Case #" << tc + 1 << edl;
        sol.TEST();
        cout << edl << "DONE" << edl;
    }
    return (0);
}