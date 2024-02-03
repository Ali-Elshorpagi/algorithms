#include <iostream>
#include <vector>

using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)
#define yes cout << "YES\n"
#define no cout << "NO\n"

class Solution
{
    vi dr{-1, 0, 1, 0}; // Delta for: up, right, down, left
    vi dc{0, 1, 0, -1};
    bool is_cycle = false;

public:
    Solution() { __elshorpagi__; }
    bool is_valid(int r, int c, vvc &grid)
    {
        if (r < 0 || r >= sz(grid) || c < 0 || c >= sz(grid[0]))
            return false;
        return true;
    }
    void dfs(vvc &grid, vvi &visited, int r, int c, char old_val, int par_r = -1, int par_c = -1)
    {
        if (!is_valid(r, c, grid) || grid[r][c] != old_val || is_cycle)
            return;
        if (visited[r][c])
        {
            is_cycle = true;
            return;
        }
        visited[r][c] = 1;
        fr(d, 0, 4)
        {
            int new_row(r + dr[d]), new_col(c + dc[d]);
            if (new_row == par_r && new_col == par_c)
                continue; // will decrease the choices to 3 directions instead of 4 directions
            dfs(grid, visited, new_row, new_col, old_val, r, c);
        }
    }
    bool containsCycle(vvc &grid)
    {
        vvi visited(sz(grid), vi(sz(grid[0])));
        fr(i, 0, sz(grid))
        {
            fr(j, 0, sz(grid[0]))
            {
                if (!visited[i][j])
                {
                    is_cycle = false;
                    dfs(grid, visited, i, j, grid[i][j]);
                    if (is_cycle)
                        return true;
                }
            }
        }
        return false;
    }
    void TEST()
    {
        bool ans;
        vvc g1{{'a', 'a', 'a', 'a'}, {'a', 'b', 'b', 'a'}, {'a', 'b', 'b', 'a'}, {'a', 'a', 'a', 'a'}};
        ans = containsCycle(g1);
        ans ? yes : no;
        vvc g2{{'a', 'b', 'b'}, {'b', 'z', 'b'}, {'b', 'b', 'a'}};
        ans = containsCycle(g2);
        ans ? yes : no;
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