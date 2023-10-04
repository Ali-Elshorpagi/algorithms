#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

#define _CRT_SECURE_NO_DEPRECATE
#define Sukuna (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)

class Solution
{
    vi dr{-1, 0, 1, 0}; // Delta for: up, right, down, left
    vi dc{0, 1, 0, -1};
    vvvi memory; // for Memoization
    const int mod = 1e9 + 7;
    int rows, cols;

public:
    Solution() { Sukuna, memory.resize(55, vvi(55, vi(55, -1))); }
    bool is_valid(int row, int col)
    {
        if (row >= rows || row < 0 || col < 0 || col >= cols)
            return false;
        return true;
    }
    int dp(int row, int col, int max_moves)
    {
        if (!is_valid(row, col))
            return 1;

        if (!max_moves)
            return 0;

        auto &ref(memory[row][col][max_moves]);
        if (ref != -1)
            return ref;

        ref = 0;
        fr(d, 0, 4)
        {
            ref += dp(row + dr[d], col + dc[d], max_moves - 1);
            ref %= mod;
        }
        return ref;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        rows = m, cols = n;
        return dp(startRow, startColumn, maxMove);
    }
    void TEST()
    {
        // int m(1), n(3), maxMove(3), startRow(0), startColumn(1);
        // cout << findPaths(m, n, maxMove, startRow, startColumn) << edl; // 12
        int m(2), n(2), maxMove(2), startRow(0), startColumn(0);
        cout << findPaths(m, n, maxMove, startRow, startColumn) << edl; // 6
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