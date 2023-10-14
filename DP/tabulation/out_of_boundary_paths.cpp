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
    Solution() { Sukuna; }
    bool is_valid(int row, int col)
    {
        if (row >= rows || row < 0 || col < 0 || col >= cols)
            return false;
        return true;
    }
    int answer(int row, int col, int move)
    {
        if (move < 0)
            return 0;
        if (!is_valid(row, col))
            return 1;
        return memory[row][col][move];
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        memory.assign(55, vvi(55, vi(55, -1)));
        rows = m, cols = n, ++maxMove;
        fr(move, 0, maxMove)
        {
            fr(i, 0, rows)
            {
                fr(j, 0, cols)
                {
                    int cnt(0);
                    fr(d, 0, 4)
                    {
                        cnt += answer(i + dr[d], j + dc[d], move - 1);
                        cnt %= mod;
                    }
                    memory[i][j][move] = cnt;
                }
            }
        }
        return memory[startRow][startColumn][maxMove - 1];
    }
    void TEST()
    {
        int m(1), n(3), maxMove(3), startRow(0), startColumn(1);
        cout << findPaths(m, n, maxMove, startRow, startColumn) << edl; // 12
        m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0;
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