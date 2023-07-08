#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vector<pair<int, int>>> GRAPH;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fc(it, v) for (auto &(it) : (v))

// link : https://leetcode.com/problems/shortest-path-with-alternating-colors/
// code : leetcode 1129

class Solution // State Graph Problem
{

public:
    Solution() { Mesh_Ali; }
    void add_directed_edges(GRAPH &graph, vvi &edges, int color)
    {
        // pair<int, int> = pair<to, color>;
        // edge[0] = from
        // edge[1] = to
        // 0 -> Red Color
        // 1 -> Blue Color
        fc(edge, edges) graph[edge[0]].push_back({edge[1], color});
    }
    void BFS(GRAPH &graph, vvi &visited, vi &ans)
    {
        // queue<tuple<int, int, int>> = queue<tuple<node, steps, color>>;
        queue<tuple<int, int, int>> nodes; // u can change the tuple to vector<int> or Struct
        // start with node 0, no.steps is 0 and undefined color -1
        nodes.push({0, 0, -1});
        visited[0][1] = visited[0][0] = 1;
        ans[0] = 0;
        while (!nodes.empty())
        {
            tuple<int, int, int> cur = nodes.front();
            int node(get<0>(cur)), steps(get<1>(cur)), prev_color(get<2>(cur));
            nodes.pop();
            fc(it, graph[node]) // it.first = neighbour, it.second = color
            {
                if (!visited[it.first][it.second] && prev_color != it.second)
                {
                    visited[it.first][it.second] = 1;
                    nodes.push({it.first, steps + 1, it.second});
                    if (ans[it.first] == -1)
                        ans[it.first] = steps + 1;
                }
            }
        }
    }
    vi shortestAlternatingPaths(int n, vvi &redEdges, vvi &blueEdges)
    {
        vi ans(n, -1);
        GRAPH graph(n);
        add_directed_edges(graph, redEdges, 0);
        add_directed_edges(graph, blueEdges, 1);
        vvi visited(n, vi(2));
        BFS(graph, visited, ans);
        return ans;
    }
    void TEST()
    {
        int n(3);
        vvi redEdges{{0, 1}, {1, 2}}, blueEdges{};
        vi ans = shortestAlternatingPaths(n, redEdges, blueEdges);
        fc(it, ans) cout << it << ' '; // 0, 1, -1
        cout << edl;
        n = 7;
        redEdges = {{0, 1}, {0, 2}, {1, 4}, {1, 2}, {2, 3}}, blueEdges = {{1, 2}, {2, 5}, {3, 6}};
        ans = shortestAlternatingPaths(n, redEdges, blueEdges);
        fc(it, ans) cout << it << ' '; // 0 1 1 3 -1 2 4
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