#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define cl(v) ((v).clear())
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)
#define fl(i, x, n) for (int i(x); i > n; --i)
#define fc(it, v) for (auto &(it) : (v))
#define sq(x) (x) * (x)
#define yes cout << "YES\n"
#define no cout << "NO\n"

// link : https://leetcode.com/problems/graph-valid-tree/
// code : leetcode 261

/*
 * valid tree can contain multiple CCs
 * Tree:
 *      1) no.edges = no.nodes - 1
 *      2) no cycles
 */

const int oo = 1e7; // A big value expressing infinity

class Solution
{
public:
    Solution() { Mesh_Ali; }
    void add_undirected_edge(vvi &graph, int from, int to)
    {
        graph[from].emplace_back(to);
        graph[to].emplace_back(from);
    }
    void BFS(vvi &graph, vi &visited, int start)
    {
        queue<int> qu{};
        while (!qu.empty())
        {
            int cur(qu.front());
            qu.pop();
            fc(neighbour, graph[cur])
            {
                if (!visited[neighbour])
                {
                    qu.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }
    // this problem is premium, so I modified the code to suit me
    bool validTree(int nodes, vvi &edges)
    {
        if (sz(edges) != nodes - 1 || !nodes)
            return false;
        vvi graph(nodes);
        fc(edge, edges)
            add_undirected_edge(graph, edge[0], edge[1]);
        vi visited(nodes);
        BFS(graph, visited, nodes);
        // return sz(visited) == nodes;
    }
    void TEST()
    {
        int nodes, edges;
        cin >> nodes >> edges;
        vvi graph(nodes);
        fr(e, 0, edges)
        {
            int from, to;
            cin >> from >> to;
            add_undirected_edge(graph, from, to);
        }
        if (validTree(nodes, graph))
            yes;
        else
            no;
    }
};

int main()
{
    Solution sol;
    freopen("../../test/input.txt", "r", stdin);
    freopen("../../test/output.txt", "w", stdout);
    int tc(1);
    cin >> tc;
    while (tc--)
        cout << "Case #" << tc + 1 << edl, sol.TEST();
    cout << edl << "DONE" << edl;
    return (0);
}