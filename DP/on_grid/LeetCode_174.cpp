#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define Sukuna (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'

class Solution
{
    vvi memory; // for Memoization
public:
    Solution() { Sukuna, memory.resize(205, vi(205, -1)); }
    bool is_valid(vvi &matrix, int row, int col)
    {
        if (row >= sz(matrix) || col >= sz(matrix[0]))
            return false;
        return true;
    }
    int dp(vvi &matrix, int row, int col)
    {
        if (row == sz(matrix) - 1 && col == sz(matrix[0]) - 1)
            return matrix[row][col] < 0 ? -matrix[row][col] + 1 : 1; // max(1, -matrix[row][col] + 1);

        if (!is_valid(matrix, row, col))
            return 1e9;

        auto &ref(memory[row][col]);
        if (ref != -1)
            return ref;

        int go_right(max(1, dp(matrix, row, col + 1) - matrix[row][col])),
            go_down(max(1, dp(matrix, row + 1, col) - matrix[row][col]));

        return ref = min(go_right, go_down);
    }
    int calculateMinimumHP(vvi &dungeon)
    {
        return dp(dungeon, 0, 0);
    }
    void TEST()
    {
        vvi dungeon{
            {-2, -3, 3},
            {-5, -10, 1},
            {10, 30, -5}};
        cout << calculateMinimumHP(dungeon) << edl; // 7
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