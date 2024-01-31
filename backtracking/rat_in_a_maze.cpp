#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<char>> vvc;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)

class Solution
{
    vi dr{-1, 0, 1, 0}; // Delta for: up, right, down, left
    vi dc{0, 1, 0, -1};
    int rows, cols, total_paths = 0, current_steps = 0, best_path_so_far = INT_MAX;
    vvc grid;

public:
    Solution() { __elshorpagi__; }
    bool is_valid(int row, int col)
    {
        if (row >= rows || row < 0 || col < 0 || col >= cols)
            return false;
        if (grid[row][col] != '.')
            return false;
        return true;
    }
    void backtracking(int row, int col)
    {
        if (row == rows - 1 && col == cols - 1)
        {
            // Only keep the total paths of minimum steps
            if (best_path_so_far > current_steps)
                best_path_so_far = current_steps, total_paths = 1; // new benchmark
            else if (best_path_so_far == current_steps)
                ++total_paths; // found one way equal to min path
            // third case is the current_steps > best_path_so_far, so we'll ignore it
            return;
        }
        fr(d, 0, 4) // loop upon 4 directions
        {
            int new_row(dr[d] + row), new_col(dc[d] + col);
            if (!is_valid(new_row, new_col))
                continue;
            // update the state
            ++current_steps;
            grid[new_row][new_col] = 'v';

            backtracking(new_row, new_col);

            // undo the state
            --current_steps;
            grid[new_row][new_col] = '.';
        }
    }
    void TEST()
    {
        rows = 5, cols = 7;
        grid = {{'.', '.', '.', '.', '.', '.', '.'},
                {'.', 'x', 'x', 'x', 'x', 'x', '.'},
                {'.', '.', '.', 'x', '.', '.', '.'},
                {'.', 'x', '.', '.', '.', '.', 'x'},
                {'.', '.', 'x', '.', 'x', '.', '.'}};

        grid[0][0] = 'v'; // make it as visited
        backtracking(0, 0);
        // total_paths = the number of the paths that have the lowest steps
        cout << total_paths << edl; // 1
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