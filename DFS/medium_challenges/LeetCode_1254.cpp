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

// link : https://leetcode.com/problems/number-of-closed-islands/
// code : leetcode 1254

class Solution // O(N * M) time, O(N * M) space
{
    vi dr{-1, 0, 1, 0}; // Delta for: up, right, down, left
    vi dc{0, 1, 0, -1};

public:
    Solution() { Mesh_Ali; }
    bool is_valid(int new_row, int new_col, vvi &grid)
    {
        if (new_row < 0 || new_row >= sz(grid) || new_col < 0 || new_col >= sz(grid[0]))
            return false;
        return true;
    }
    bool dfs(vvi &visited, vvi &grid, int i, int j)
    {
        if (!is_valid(i, j, grid))
            return false;
        if (grid[i][j] || visited[i][j])
            return true;
        visited[i][j] = 1;
        bool flag(true);
        fr(d, 0, 4) flag &= dfs(visited, grid, i + dr[d], j + dc[d]);
        return flag;
    }
    int closedIsland(vvi &grid)
    {
        int cnt(0);
        vvi visited(sz(grid), vi(sz(grid[0])));
        fr(i, 0, sz(grid))
        {
            fr(j, 0, sz(grid[i]))
            {
                if (!grid[i][j] && !visited[i][j])
                    cnt += dfs(visited, grid, i, j);
            }
        }
        return cnt;
    }
    void TEST()
    {
        vvi grid{{1, 1, 1, 1, 1, 1, 1, 0}, {1, 0, 0, 0, 0, 1, 1, 0}, {1, 0, 1, 0, 1, 1, 1, 0}, {1, 0, 0, 0, 0, 1, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 0}};
        cout << closedIsland(grid) << edl;
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