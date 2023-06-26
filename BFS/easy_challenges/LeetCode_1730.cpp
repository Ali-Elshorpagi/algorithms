#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vector<char>> vvc;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)
#define fc(it, v) for (auto &(it) : (v))

// link : https://leetcode.com/problems/shortest-path-to-get-food/
// code : leetcode 1730

class Solution
{
    // Note : u can use the struct that called 'Cell' instead of STL::Pair
    struct Cell
    {
        int r, c;
        Cell(int r, int c) : r(r), c(c) {}
    };

    // Delta for: up, right, down, left
    vi dr{-1, 0, 1, 0};
    vi dc{0, 1, 0, -1};

public:
    Solution() { Mesh_Ali; }
    bool is_valid(int r, int c, vvc &matrix)
    {
        if (matrix[r][c] == 'X' || r < 0 || r >= sz(matrix) || c < 0 || c >= sz(matrix[0]))
            return false;
        return true;
    }
    int BFS(vvc &matrix, pii &start)
    {
        queue<pii> indices;
        // u can use the matrix itself as a visited array
        // This is good for competitions, but not industry / interviews
        vvi visited(sz(matrix), vi(sz(matrix[0])));
        indices.push(start);
        visited[start.first][start.second] = 1;
        // matrix[start.r][start.c] = 'X'; // as a visited array
        for (int steps(0), sze(sz(indices)); !indices.empty(); ++steps, sze = sz(indices))
        {
            while (sze--)
            {
                pii cur(indices.front());
                indices.pop();
                fr(d, 0, 4)
                {
                    int nr(cur.first + dr[d]), nc(cur.second + dc[d]);
                    if (visited[nr][nc] || !is_valid(nr, nc, matrix))
                        continue;
                    if (matrix[nr][nc] == '#')
                        return steps + 1;
                    // matrix[nr][nc] = 'X';
                    indices.push({nr, nc});
                    visited[nr][nc] = 1;
                }
            }
        }
        return -1;
    }
    int getFood(vvc &matrix)
    {
        pii start(-1, -1);
        fr(i, 0, sz(matrix))
        {
            fr(j, 0, sz(matrix[0]))
            {
                if (matrix[i][j] == '*')
                    start = {i, j}; // there is no break cus I need the closest one
            }
        }
        return BFS(matrix, start);
    }
    void TEST()
    {
        vvc grid1{{'X', 'X', 'X', 'X', 'X', 'X'},
                  {'X', '*', 'O', 'O', 'O', 'X'},
                  {'X', 'O', 'O', '#', 'O', 'X'},
                  {'X', 'X', 'X', 'X', 'X', 'X'}};
        cout << getFood(grid1) << edl; // 3
        vvc grid2 = {{'X', 'X', 'X', 'X', 'X'},
                     {'X', '*', 'X', 'O', 'X'},
                     {'X', 'O', 'X', '#', 'X'},
                     {'X', 'X', 'X', 'X', 'X'}};
        cout << getFood(grid2) << edl; // -1
        vvc grid3 = {{'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                     {'X', '*', 'O', 'X', 'O', '#', 'O', 'X'},
                     {'X', 'O', 'O', 'X', 'O', 'O', 'X', 'X'},
                     {'X', 'O', 'O', 'O', 'O', '#', 'O', 'X'},
                     {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'}};
        cout << getFood(grid3) << edl; // 6
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