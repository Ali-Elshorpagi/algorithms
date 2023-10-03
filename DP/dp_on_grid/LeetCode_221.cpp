#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vector<char>> vvc;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)
#define sq(x) (x) * (x)

class Solution
{
    vvi memory; // for Memoization

public:
    Solution() { Mesh_Ali, memory.resize(305, vi(305, -1)); }
    bool is_valid(vvc &matrix, int row, int col)
    {
        if (row >= sz(matrix) || col >= sz(matrix[0]) || matrix[row][col] == '0')
            return false;
        return true;
    }
    int dp(vvc &matrix, int row, int col)
    {
        if (!is_valid(matrix, row, col))
            return 0;

        auto &ref(memory[row][col]);
        if (ref != -1)
            return ref;

        int go_right(dp(matrix, row, col + 1)),
            go_down(dp(matrix, row + 1, col)),
            go_diagonal(dp(matrix, row + 1, col + 1));
        // current cell + min(my children)
        ref = 1 + min({go_right, go_down, go_diagonal});
        return ref;
    }
    int maximalSquare(vvc &matrix)
    {
        int max_side(0);
        fr(i, 0, sz(matrix))
        {
            fr(j, 0, sz(matrix[0]))
            {
                if (matrix[i][j] == '1')
                    max_side = max(max_side, dp(matrix, i, j));
            }
        }
        return sq(max_side);
    }
    void TEST()
    {
        vvc matrix{{'1', '0', '1', '0', '0'},
                   {'1', '0', '1', '1', '1'},
                   {'1', '1', '1', '1', '1'},
                   {'1', '0', '0', '1', '0'}};
        cout << maximalSquare(matrix) << edl; // 4
        // vvc matrix{{'0', '1'},
        //            {'1', '0'}};
        // cout << maximalSquare(matrix) << edl; // 1
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