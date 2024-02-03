#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)
#define fc(it, v) for (auto &(it) : (v))

class Solution
{
    vi dr{-1, 0, 1, 0}; // Delta for: up, right, down, left
    vi dc{0, 1, 0, -1};
    int colur;

public:
    Solution() { __elshorpagi__; }
    bool is_valid(int new_row, int new_col, vvi &grid)
    {
        if (new_row < 0 || new_row >= sz(grid) || new_col < 0 || new_col >= sz(grid[0]))
            return false;
        return true;
    }
    void dfs(vvi &grid, vvi &visited, int r, int c, int old_color)
    {
        if (!is_valid(r, c, grid) || grid[r][c] != old_color || visited[r][c])
            return;
        visited[r][c] = 1;
        if (!r || !c || r >= sz(grid) - 1 || c >= sz(grid[0]) - 1)
            grid[r][c] = colur;
        if ((r + 1 <= sz(grid) - 1 && grid[r + 1][c] != old_color && !visited[r + 1][c]) ||
            (r - 1 >= 0 && grid[r - 1][c] != old_color && !visited[r - 1][c]) ||
            (c + 1 <= sz(grid[0]) - 1 && grid[r][c + 1] != old_color && !visited[r][c + 1]) ||
            (c - 1 >= 0 && grid[r][c - 1] != old_color && !visited[r][c - 1]))
            grid[r][c] = colur;
        fr(d, 0, 4) dfs(grid, visited, r + dr[d], c + dc[d], old_color);
    }
    vvi colorBorder(vvi &grid, int row, int col, int color)
    {
        colur = color;
        vvi visited(sz(grid), vi(sz(grid[0])));
        dfs(grid, visited, row, col, grid[row][col]);
        return grid;
    }
    void TEST()
    {
        vvi grid{{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
        int row(1), col(1), color(2);
        vvi ans = colorBorder(grid, row, col, color);
        fc(i, ans)
        {
            fc(j, i)
            {
                cout << j << ' ';
            }
            cout << edl;
        }
        // Output: [[2,2,2],[2,1,2],[2,2,2]]
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
    {
        cout << "Case #" << tc + 1 << edl;
        sol.TEST();
        cout << edl << "DONE" << edl;
    }
    return (0);
}