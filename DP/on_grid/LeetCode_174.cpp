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
    Solution() { __elshorpagi__, memory.resize(205, vi(205, -1)); }
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
    bool dp_evaluate(vvi &dungeon, int row, int col, int mid)
    {
        if (!is_valid(dungeon, row, col) || mid <= 0)
            return false;

        auto &ref(memory[row][col]);
        if (ref != -1)
            return ref;

        if (row == sz(dungeon) - 1 && col == sz(dungeon[0]) - 1)
            return dungeon[row][col] + mid > 0;

        bool flag(dp_evaluate(dungeon, row, col + 1, mid - dungeon[row][col]) ||
                  dp_evaluate(dungeon, row + 1, col, mid - dungeon[row][col]));

        return ref = flag ? 1 : 0;
    }
    int binary_search(vvi &dungeon) // it has an error, didn't fix yet
    {
        int left(1), right(2 * 1e5), ans(-1);
        while (left < right)
        {
            int mid(left + ((right - left) >> 1));
            memory.assign(205, vi(205, -1));
            if (dp_evaluate(dungeon, 0, 0, mid))
                ans = mid, right = mid;
            else
                left = mid + 1;
        }
        return ans;
    }
    int calculateMinimumHP(vvi &dungeon)
    {
        // return dp(dungeon, 0, 0);
        return binary_search(dungeon);
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