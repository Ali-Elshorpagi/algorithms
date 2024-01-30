#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define _CRT_SECURE_NO_DEPRECATE
#define Sukuna (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define sz(v) ((int)((v).size()))
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)
#define fc(it, v) for (auto &(it) : (v))
#define yes cout << "YES\n"
#define no cout << "NO\n"

/*
 * Tree:
 *      1) no.edges = no.nodes - 1
 *      2) no cycles
 */

const int oo = 1e7; // A big value expressing infinity

class Solution
{
public:
    Solution() { Sukuna; }
    void add_undirected_edge(vvi &graph, int from, int to)
    {
        graph[from].emplace_back(to);
        graph[to].emplace_back(from);
    }
    bool BFS(vvi &graph, vi &visited, int start) // check about CCs
    {
        queue<int> nodes;
        visited[start] = 1;
        vi parent(sz(graph), -1);
        nodes.push(start);
        while (!nodes.empty())
        {
            int cur(nodes.front());
            nodes.pop();
            fc(neighbour, graph[cur])
            {
                if (!visited[neighbour])
                {
                    nodes.push(neighbour);
                    visited[neighbour] = 1;
                    parent[neighbour] = cur;
                }
                else if (parent[cur] != neighbour) // cycle
                    return true;
                // otherwise it's a fake cycle
            }
        }
        return false;
    }
    bool has_cycle(vvi &graph)
    {
        vi visited(sz(graph));
        fr(i, 0, sz(graph))
        {
            if (!visited[i] && BFS(graph, visited, i))
                return true;
        }
        return false;
    }
    bool validTree(int nodes, vvi &edges)
    {
        if (sz(edges) != nodes - 1 || !nodes)
            return false;
        vvi graph(nodes);
        fc(edge, edges)
            add_undirected_edge(graph, edge[0], edge[1]);
        return !has_cycle(graph);
    }
    void TEST()
    {
        int nodes(5);
        vvi edges{{0, 1}, {0, 2}, {0, 3}, {1, 4}};
        if (validTree(nodes, edges)) // true
            yes;
        else
            no;
        edges = {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};
        if (validTree(nodes, edges)) // false
            yes;
        else
            no;
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