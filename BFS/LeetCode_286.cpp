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
    const int INF{INT_MAX}; // 2147483647
    // Delta for: up, right, down, left
    vi dr{-1, 0, 1, 0};
    vi dc{0, 1, 0, -1};

public:
    Solution() { __elshorpagi__; }
    bool is_valid(vvi &visited, vvi &rooms, int row, int col)
    {
        if (row < 0 || row >= sz(rooms) || col < 0 || col >= sz(rooms[0]))
            return false;
        // rooms[row][col] == -1 that's mean it's a WALL
        if (rooms[row][col] == -1 || visited[row][col])
            return false;
        return true;
    }
    void BFS(vvi &rooms, queue<pii> &nodes, vvi &visited)
    {
        for (int level(0), sze(sz(nodes)); !nodes.empty(); ++level, sze = sz(nodes))
        {
            while (sze--)
            {
                pii cur(nodes.front());
                nodes.pop();
                fr(d, 0, 4)
                {
                    int new_row(cur.first + dr[d]), new_col(cur.second + dc[d]);
                    if (is_valid(visited, rooms, new_row, new_col) && rooms[new_row][new_col] == INF)
                    {
                        rooms[new_row][new_col] = level + 1;
                        visited[new_row][new_col] = 1;
                        nodes.push({new_row, new_col});
                    }
                }
            }
        }
    }
    void wallsAndGates(vvi &rooms)
    {
        if (sz(rooms) < 2 || sz(rooms[0]) < 2)
            return;
        vvi visited(sz(rooms), vi(sz(rooms[0])));
        queue<pii> nodes;
        // we start from the GATE
        // so we add all the GATES first and start from them
        // this technique is called (multi-source BFS) or (1-M BFS)
        fr(i, 0, sz(rooms))
        {
            fr(j, 0, sz(rooms[0]))
            {
                if (!rooms[i][j]) // it's a GATE
                {
                    visited[i][j] = 1;
                    nodes.push({i, j});
                }
            }
        }
        BFS(rooms, nodes, visited);
    }
    void TEST()
    {
        vvi rooms{{INF, -1, 0, INF},
                  {INF, INF, INF, -1},
                  {INF, -1, INF, -1},
                  {0, -1, INF, INF}};
        wallsAndGates(rooms);
        fc(i, rooms)
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