#include <iostream>
#include <vector>

using namespace std;

typedef vector<string> vs;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)

class Solution
{
    vs chess_board;
    int ans;

public:
    Solution() { __elshorpagi__; }
    bool is_valid(int row, int col, int n)
    {
        // check this row on the left side
        fr(i, 0, col)
        {
            if (chess_board[row][i] == 'Q')
                return false;
        }
        // check the upper diagonal on the left side
        for (int i(row), j(col); i > -1 && j > -1; --i, --j)
        {
            if (chess_board[i][j] == 'Q')
                return false;
        }
        // check the lower diagonal on the left side
        for (int i(row), j(col); i < n && j > -1; ++i, --j)
        {
            if (chess_board[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void backtracking(int col, int n)
    {
        if (col == n)
            ++ans;
        else
        {
            fr(row, 0, n)
            {
                if (is_valid(row, col, n))
                {
                    chess_board[row][col] = 'Q'; // update the state
                    backtracking(col + 1, n);
                    chess_board[row][col] = '.'; // undo the state
                }
            }
        }
    }
    int totalNQueens(int n)
    {
        chess_board = vs(n, string(n, '.')), ans = 0;
        backtracking(0, n);
        return ans;
    }
    void TEST()
    {
        int n(4), result = totalNQueens(n);
        cout << result << edl; // 2
        n = 1, result = totalNQueens(n);
        cout << result << edl; // 1
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