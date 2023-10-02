#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)

class Solution
{
    vvi memory; // for Memoization
public:
    Solution() { Mesh_Ali, memory.resize(105, vi(105, -1e5)); }
    bool is_valid(vvi &matrix, int row, int col)
    {
        if (row >= sz(matrix) || col < 0 || col >= sz(matrix[0]))
            return false;
        return true;
    }
    int dp(vvi &matrix, int row, int col)
    {
        if (!is_valid(matrix, row, col))
            return 1e9;

        if (row == sz(matrix) - 1)
            return matrix[row][col];

        auto &ref(memory[row][col]);
        if (ref != -1e5)
            return ref;
        ref = matrix[row][col];
        // (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1);
        int choice1(dp(matrix, row + 1, col - 1)),
            choice2(dp(matrix, row + 1, col)),
            choice3(dp(matrix, row + 1, col + 1));
        ref += min({choice1, choice2, choice3});
        return ref;
    }
    int minFallingPathSum(vvi &matrix)
    {
        int ans(INT_MAX);
        fr(col, 0, sz(matrix)) { ans = min(ans, dp(matrix, 0, col)); }
        return ans;
    }
    void TEST()
    {
        // vvi matrix{{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
        // cout << minFallingPathSum(matrix) << edl; // 13
        vvi matrix{{-19, 57}, {-40, -5}};
        cout << minFallingPathSum(matrix) << edl; // -59
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