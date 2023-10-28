#include <iostream>
#include <vector>

using namespace std;

typedef vector<string> vs;
typedef vector<vs> vvs;

#define _CRT_SECURE_NO_DEPRECATE
#define Sukuna (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)
#define fc(it, v) for (auto &(it) : (v))

class Solution
{
    vs chess_board;

public:
    Solution() { Sukuna; }
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
    void backtracking(vvs &ans, int col, int n)
    {
        if (col == n)
            ans.push_back(chess_board);
        else
        {
            fr(row, 0, n)
            {
                if (is_valid(row, col, n))
                {
                    chess_board[row][col] = 'Q'; // update the state
                    backtracking(ans, col + 1, n);
                    chess_board[row][col] = '.'; // undo the state
                }
            }
        }
    }
    int totalNQueens(int n)
    {

        chess_board = vs(n, string(n, '.'));
        vvs ans;
        backtracking(ans, 0, n);
        return sz(ans);
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