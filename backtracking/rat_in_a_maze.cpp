#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<char>> vvc;

#define _CRT_SECURE_NO_DEPRECATE
#define Sukuna (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)

class Solution
{
    vi dr{-1, 0, 1, 0}; // Delta for: up, right, down, left
    vi dc{0, 1, 0, -1};
    int rows, cols, total_paths = 0;
    vvc grid;

public:
    Solution() { Sukuna; }
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
            ++total_paths;
            return;
        }
        fr(d, 0, 4) // loop upon 4 directions
        {
            int new_row(dr[d] + row), new_col(dc[d] + col);
            if (!is_valid(new_row, new_col))
                continue;

            grid[new_row][new_col] = 'v'; // update the grid
            backtracking(new_row, new_col);
            grid[new_row][new_col] = '.'; // undo the grid
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
        cout << total_paths << edl; // 4
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