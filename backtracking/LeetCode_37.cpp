#include <iostream>
#include <vector>

using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;

#define _CRT_SECURE_NO_DEPRECATE
#define Sukuna (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)
#define fc(it, v) for (auto &(it) : (v))
#define yes cout << "YES\n"
#define no cout << "NO\n"

class Solution
{
public:
    Solution() { Sukuna; }
    bool is_valid(vvc &board, int row, int col, char ch)
    {
        fr(i, 0, 9)
        {
            // It ensures that the same character is not present in the same row, column,
            if (board[i][col] == ch || board[row][i] == ch)
                return false;
            // It ensures that the same character is not present in the 3x3 subgrid of the specified position.
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch)
                return false;
        }
        return true;
    }
    bool backtracking(vvc &board)
    {
        fr(i, 0, sz(board))
        {
            fr(j, 0, sz(board[0]))
            {
                if (board[i][j] == '.')
                {
                    for (char ch('1'); ch <= '9'; ++ch)
                    {
                        if (is_valid(board, i, j, ch))
                        {
                            board[i][j] = ch;
                            if (backtracking(board))
                                return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vvc &board) { backtracking(board); }
    void TEST()
    {
        vvc board{{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
        solveSudoku(board);
        vvc result{{'5', '3', '4', '6', '7', '8', '9', '1', '2'},
                   {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
                   {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
                   {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
                   {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
                   {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
                   {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
                   {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
                   {'3', '4', '5', '2', '8', '6', '1', '7', '9'}};
        result == board ? yes : no; // YES
        fc(it, board)
        {
            fc(jt, it) { cout << jt << ' '; }
            cout << edl;
        }
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