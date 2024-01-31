#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'

class Solution
{
    vvi memory; // for Memoization
public:
    Solution() { __elshorpagi__, memory.resize(105, vi(105, -1)); }
    bool is_valid(vvi &matrix, int row, int col)
    {
        if (row >= sz(matrix) || col >= sz(matrix[0]))
            return false;
        return true;
    }
    int dp(vvi &matrix, int row, int col)
    {
        if (!is_valid(matrix, row, col) || matrix[row][col] == 1)
            return 0;
        if (row == sz(matrix) - 1 && col == sz(matrix[0]) - 1)
            return 1;
        auto &ref(memory[row][col]);
        if (ref != -1)
            return ref;
        int go_right(dp(matrix, row, col + 1));
        int go_down(dp(matrix, row + 1, col));

        return ref = go_right + go_down;
    }
    int uniquePathsWithObstacles(vvi &obstacleGrid)
    {
        return dp(obstacleGrid, 0, 0);
    }
    void TEST()
    {
        // vvi obstacleGrid{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
        // cout << uniquePathsWithObstacles(obstacleGrid) << edl; // 2
        vvi obstacleGrid{{0, 1}, {0, 0}};
        cout << uniquePathsWithObstacles(obstacleGrid) << edl; // 1
        // vvi obstacleGrid{{0, 0}, {0, 1}};
        // cout << uniquePathsWithObstacles(obstacleGrid) << edl; // 0
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