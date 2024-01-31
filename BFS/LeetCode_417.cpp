#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define __elshorpagi__ (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)
#define fc(it, v) for (auto &(it) : (v))

class Solution
{
    // Delta for: up, right, down, left
    vi dr{-1, 0, 1, 0};
    vi dc{0, 1, 0, -1};

public:
    Solution() { __elshorpagi__; }
    bool is_valid(vvi &heights, int row, int col)
    {
        if (row < 0 || row >= sz(heights) || col < 0 || col >= sz(heights[0]))
            return false;
        return true;
    }
    void BFS(vvi &heights, vvi &visited, queue<pii> &nodes)
    {
        while (!nodes.empty())
        {
            pii cur(nodes.front());
            nodes.pop();
            visited[cur.first][cur.second] = 1; // I did it instead of the 4 lines in the down
            fr(d, 0, 4)
            {
                int new_row(cur.first + dr[d]), new_col(cur.second + dc[d]);
                if (is_valid(heights, new_row, new_col) && !visited[new_row][new_col])
                {
                    if (heights[cur.first][cur.second] <= heights[new_row][new_col])
                    {
                        nodes.push({new_row, new_col});
                        visited[new_row][new_col] = 1;
                    }
                }
            }
        }
    }
    vvi pacificAtlantic(vvi &heights)
    {
        int rows(sz(heights)), cols(sz(heights[0]));
        vvi pacific_visited(rows, vi(cols)), atlantic_visited(rows, vi(cols));

        queue<pii> pacific_nodes; // push the boundaries of pacific ocean
        fr(i, 0, rows)
            pacific_nodes.push({i, 0}); // pacific_visited[i][0] = 1;
        fr(j, 0, cols)
            pacific_nodes.push({0, j}); // pacific_visited[0][j] = 1;
        BFS(heights, pacific_visited, pacific_nodes);

        queue<pii> atlantic_nodes; // push the boundaries of atlantic ocean
        fr(i, 0, rows)
            atlantic_nodes.push({i, cols - 1}); // atlantic_visited[i][cols - 1];
        fr(j, 0, cols)
            atlantic_nodes.push({rows - 1, j}); // atlantic_visited[rows - 1][j];
        BFS(heights, atlantic_visited, atlantic_nodes);

        vvi ans;
        fr(i, 0, rows) // build the answers
        {
            fr(j, 0, cols)
            {
                if (pacific_visited[i][j] && atlantic_visited[i][j])
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
    void TEST()
    {
        vvi heights{{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};
        vvi result = pacificAtlantic(heights);
        fc(i, result)
        {
            fc(j, i) cout << j << ' ';
            cout << edl;
        }
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